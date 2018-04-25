# Questions

## What's `stdint.h`?

A header file that provides a set of typedefs that specify exact-width integer types, together with the defined minimum and maximum allowable values for each type, using macros ([source](https://en.wikibooks.org/wiki/C_Programming/stdint.h)).

## What's the point of using `uint8_t`, `uint32_t`, `int32_t`, and `uint16_t` in a program?

Using exact-width integer types simplifies manipulation of variables/memory registers that need API-specific widths, locations or exact alignments ([source](https://en.wikibooks.org/wiki/C_Programming/stdint.h)).

Naming convention: `intN_t` for signed `int`s and `uintN_t` for unsigned `int`s, where `N` is the bit-width.

| Specifier  |  Signing  |  Bits  |  Minimum Value  |  Maximum Value  |
|------------|-----------|--------|-----------------|-----------------|
| `uint8_t`  | Unsigned  |    8   |        0        |      2^7        |
| `uint32_t` | Unsigned  |   32   |        0        |    2^32 - 1     |
| `int32_t`  | Signed    |   32   |      −2^31      |    2^31 - 1     |
| `uint16_t` | Unsigned  |   16   |        0        |    2^16 − 1     |

## How many bytes is a `BYTE`, a `DWORD`, a `LONG`, and a `WORD`, respectively?

From `bmp.h`:

```
typedef uint8_t  BYTE;   // <== 1 byte
typedef uint32_t DWORD;  // <== 4 bytes
typedef int32_t  LONG;   // <== 4 bytes
typedef uint16_t WORD;   // <== 2 bytes
```

## What (in ASCII, decimal, or hexadecimal) must the first two bytes of any BMP file be? Leading bytes used to identify file formats (with high probability) are generally called "magic numbers."

The first two bytes in a bitmap file's header comprise the 'WORD' `bfType`, and have the hex value: `0x424d`.

## What's the difference between `bfSize` and `biSize`?

`bfSize` (member of the BITMAPFILEHEADER struct) = the overall size, in bytes, of the whole bitmap file.

`biSize` (member of the BITMAPINFOHEADER struct) = the number of bytes required by the bitmap's info header struct.

## What does it mean if `biHeight` is negative?

`biHeight` = The height of the bitmap, in pixels.

If biHeight is positive, the bitmap is a bottom-up bitmap and its origin is the lower-left corner.

If biHeight is negative, the bitmap is a top-down bitmap and its origin is the upper-left corner.

## What field in `BITMAPINFOHEADER` specifies the BMP's color depth (i.e., bits per pixel)?

`biBitCount` = The number of bits-per-pixel. The biBitCount member of the BITMAPINFOHEADER structure determines the number of bits that define each pixel and the maximum number of colors in the bitmap.

## Why might `fopen` return `NULL` in lines 24 and 32 of `copy.c`?

`fopen()` opens a file and returns a **file pointer** to it. If the file cannot be opened `fopen()` returns `NULL`. This could be the case if the file does not exist or because permissions do not allow a file to be opened for reading.

## Why is the third argument to `fread` always `1` in our code?

`fread()` syntax:

```
fread(<buffer>, <size>, <qty>, <file pointer>);
```

The third argument, `<qty>`, refers to the number of units of `<size>` bits to read in from a `<file pointer>` to a `<buffer>`. `fread()` is used 3 times in `copy.c`; in each case it is used to read exactly 1 'unit' of the size specified by the 2nd argument: 1 `BITMAPFILEHEADER`, 1 `BITMAPINFOHEADER`, or 1 `RGBTRIPLE`.

## What value does line 63 of `copy.c` assign to `padding` if `bi.biWidth` is `3`?

```C
// Line 63:
int padding = (4 - (bi.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;
```

so...

```
padding = (4 - (3 * 24) % 4 ) % 4
        = (4 - (72) % 4 ) % 4
        = (4 - 0) % 4
        = (4 % 4)
        = 0
```

## What does `fseek` do?

The C library function `int fseek(FILE *stream, long int offset, int whence)` sets the file position of the stream to the given offset ([source](https://www.tutorialspoint.com/c_standard_library/c_function_fseek.htm)).

## What is `SEEK_CUR`?

Referring to `copy.c`, line 82:

```C
// skip over padding, if any
fseek(inptr, padding, SEEK_CUR);
```

The 3rd parameter to `fseek()` is the position from where the offset (`padding`) is added. It is specified by one of the following constants:

1. SEEK_SET -- Beginning of file

2. SEEK_CUR -- Current position of the file pointer

3. SEEK_END -- End of file

So, `fseek(inptr, padding, SEEK_CUR);` says: "go to the position at _padding_ distance from the file pointer's current position."
