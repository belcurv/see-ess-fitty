///////////////////////////////////////////////////////////////////////////////
//
// Spec per CS50x course notes
//   a program that recreates half-pyramids using hashes (#) for blocks.
//   1. first prompt the user for the half-pyramids' heights {int) 1-23
//      (The height of the half-pyramids = the width of each half-pyramid,
//      with an a gap of size 2 separating them.)
//   2. If user fails to provide an Int 0-23, you should re-prompt for the
//      same again.
//   3. Generate (printf & one or more loops) the desired half-pyramids.
//   4. left-align the bottom-left corner of the left-hand half-pyramid with
//      the left-hand edge of your terminal window.
//
// Ugh - so procedural!
//
///////////////////////////////////////////////////////////////////////////////

#include <stdio.h>
#include <cs50.h>

// init global vars
int minHeight = 0;
int maxHeight = 23;
int gapSize = 2;

// declare functions
bool validHeight(int h);
void printLeftPadding(int height, int i);
void printLeftBlocks(int i);
void printRightBlocks(int i);
void printGap(int g);

// main program
int main(void)
{
    // init locally scoped variables
    int height;

    // await valid user input
    do
    {
        height = get_int("Desired height: ");
    }
    while (!validHeight(height));

    // render pyramids
    for (int i = 0; i < height; i++)
    {
        printLeftPadding(height, i);  // print left padding
        printLeftBlocks(i);           // print left blocks
        printGap(gapSize);            // print gap
        printRightBlocks(i);          // print right blocks
        printf("\n");                 // newline
    }
}

// check if input height meets min/max criteria
bool validHeight(int h)
{
    return h >= minHeight && h <= maxHeight;
}

// render left row padding
void printLeftPadding(int height, int i)
{
    for (int pad = 0; pad < height - i - 1; pad++)
    {
        printf(" ");
    }
}

// render left row blocks
void printLeftBlocks(int i)
{
    for (int leftBlock = 0; leftBlock < i + 1; leftBlock ++)
    {
        printf("#");
    }
}

// render gap
void printGap(int g)
{
    for (int gap = 0; gap < g; gap ++)
    {
        printf(" ");
    }
}

// render right row blocks
void printRightBlocks(int i)
{
    for (int rightBlock = 0; rightBlock < i + 1; rightBlock ++)
    {
        printf("#");
    }
}
