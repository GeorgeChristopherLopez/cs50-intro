# Questions

## What's `stdint.h`?

a header file in C/C++ that provides typedefs for integers*

## What's the point of using `uint8_t`, `uint32_t`, `int32_t`, and `uint16_t` in a program?

if a type is of the form `[u]<something>N_t` (or similar) N must be a positive decimal with no leading 0's. In lamens terms, min value is number is >= 0

## How many bytes is a `BYTE`, a `DWORD`, a `LONG`, and a `WORD`, respectively?
Data Type | Bytes
------------ | -------------
`BYTE` | 8-bit unsigned value
`DWORD` | 32-bit unsigned integer
`LONG` |  32-bit signed integer
`WORD` | 16-bit unsigned integer


## What (in ASCII, decimal, or hexadecimal) must the first two bytes of any BMP file be? Leading bytes used to identify file formats (with high probability) are generally called "magic numbers."

The first 2 bytes of the BMP file format are the character "B" then the character "M" in ASCII encoding.*

## What's the difference between `bfSize` and `biSize`?

bfSize | The size, in bytes, of the bitmap file.
biSize | The number of bytes required by the structure.
## What does it mean if `biHeight` is negative?

The height of the bitmap, in pixels. If biHeight is positive, the bitmap is a bottom-up DIB and its origin is the lower-left corner. If biHeight is negative, the bitmap is a top-down DIB and its origin is the upper-left corner.

## What field in `BITMAPINFOHEADER` specifies the BMP's color depth (i.e., bits per pixel)?

**biBitCount**
The number of bits-per-pixel. The biBitCount member of the BITMAPINFOHEADER structure determines the number of bits that define each pixel and the maximum number of colors in the bitmap. 

## Why might `fopen` return `NULL` in `copy.c`?
There are many reasons fopen can return NULL including (but certainly not limited to):**
*The file doesn't exist
*The file is opened in a mode that doesn't allow other accesses
*The network is down
*The file exists, but you don't have permissions
*A file exists with the name you gave, but the current directory of the process is not what you expected so the relative pathname fails to find and open the file.
## Why is the third argument to `fread` always `1` in our code?

Number of elements, each one with a size of size bytes.

## What value does `copy.c` assign to `padding` if `bi.biWidth` is `3`?

1

## What does `fseek` do?

Sets the position indicator associated with the stream to a new position.

## What is `SEEK_CUR`?

Current position of the file pointer


