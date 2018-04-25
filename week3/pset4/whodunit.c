////////////////////////////////////////////////////////////////////////////////
//
// whodunit.c
//
//   A program that reveals Mr. Boddy’s drawing in such a way that you can
//   recognize whodunit.
//
//   https://docs.cs50.net/2018/x/psets/4/whodunit/whodunit.html
//
// BMP headers
// 1st: BITMAPFILEHEADER = 14 bytes long
// 2nd: BITMAPINFOHEADER = 40 bytes long
//
// Then comes the actual bitmap: an array of bytes, triples of which represent
// a pixel’s color. However, BMP stores these triples backwards (i.e., as BGR).
//
// Specification:
// * accept exactly two command-line arguments:
//   1) name of an input file to open for reading
//   2) name of an output file to open for writing
// * if executed with fewer or more than two command-line arguments, it should
//   remind the user of correct usage with fprintf (to stderr), and main
//   should return 1.
// * if input file cannot be opened for reading, program should inform user
//   user with fprintf (to stderr), and main should return 2.
// * if output file cannot be opened for writing, program should inform the
//   user with fprintf (to stderr), and main should return 3.
// * if input file is not a 24-bit uncompressed BMP 4.0, program should inform
//   the user with fprintf (to stderr), and main should return 4.
// * On success, main should return 0.
//
//
////////////////////////////////////////////////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>

#include "bmp.h"

int main(int argc, char *argv[])
{
    // ensure proper usage
    if (argc != 3)
    {
        fprintf(stderr, "Usage: ./whodunit infile outfile\n");
        return 1;
    }

    // remember filenames
    char *infile = argv[1];
    char *outfile = argv[2];

    // open input file
    FILE *inptr = fopen(infile, "r");
    if (inptr == NULL)
    {
        fprintf(stderr, "Could not open %s.\n", infile);
        return 2;
    }

    // open output file
    FILE *outptr = fopen(outfile, "w");
    if (outptr == NULL)
    {
        fclose(inptr);
        fprintf(stderr, "Could not create %s.\n", outfile);
        return 3;
    }

    // read infile's BITMAPFILEHEADER
    BITMAPFILEHEADER bf;
    fread(&bf, sizeof(BITMAPFILEHEADER), 1, inptr);

    // read infile's BITMAPINFOHEADER
    BITMAPINFOHEADER bi;
    fread(&bi, sizeof(BITMAPINFOHEADER), 1, inptr);

    // ensure infile is (likely) a 24-bit uncompressed BMP 4.0
    if (bf.bfType != 0x4d42 || bf.bfOffBits != 54 || bi.biSize != 40 ||
        bi.biBitCount != 24 || bi.biCompression != 0)
    {
        fclose(outptr);
        fclose(inptr);
        fprintf(stderr, "Unsupported file format.\n");
        return 4;
    }

    // write outfile's BITMAPFILEHEADER
    fwrite(&bf, sizeof(BITMAPFILEHEADER), 1, outptr);

    // write outfile's BITMAPINFOHEADER
    fwrite(&bi, sizeof(BITMAPINFOHEADER), 1, outptr);

    // determine padding for scanlines
    int padding = (4 - (bi.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;

    // iterate over infile's scanlines
    for (int i = 0, biHeight = abs(bi.biHeight); i < biHeight; i++)
    {
        // iterate over pixels in scanline
        for (int j = 0; j < bi.biWidth; j++)
        {
            // temporary storage
            RGBTRIPLE triple;

            // read RGB triple from infile
            fread(&triple, sizeof(RGBTRIPLE), 1, inptr);

            // if a pixel is red (#0000ff) or white (#ffffff) set it to black (#000000)
            if ((triple.rgbtBlue == 0x00 && triple.rgbtGreen == 0x00 && triple.rgbtRed == 0xff) ||
                (triple.rgbtBlue == 0xff && triple.rgbtGreen == 0xff && triple.rgbtRed == 0xff))
            {
                triple.rgbtBlue = 0x00;
                triple.rgbtGreen = 0x00;
                triple.rgbtRed = 0x00;
            }

            // write RGB triple to outfile
            fwrite(&triple, sizeof(RGBTRIPLE), 1, outptr);
        }

        // skip over padding, if any
        fseek(inptr, padding, SEEK_CUR);

        // then add it back (to demonstrate how)
        for (int k = 0; k < padding; k++)
        {
            fputc(0x00, outptr);
        }
    }

    // close infile
    fclose(inptr);

    // close outfile
    fclose(outptr);

    // success
    return 0;
}
