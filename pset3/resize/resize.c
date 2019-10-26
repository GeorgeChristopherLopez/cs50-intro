// Copies a BMP file

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "bmp.h"



// open file
//update outfiles header info
//read infiles scanline, pixel by pixel
//resize horizontally
//remember padding
//resize vertically

int main(int argc, char *argv[])
{
    // ensure proper usage
    if (argc != 4)
    {
        fprintf(stderr, "Usage: n infile outfile\n");
        return 1;
    }

    // remember filenames
    char *n = argv[1];
    char *infile = argv[2];
    char *outfile = argv[3];
    int length, h;
    length = strlen(n);

     // ensure proper usage of n
    for (h = 0; h < length; h++){
        if(!isdigit(n[h])){
            printf("n must be number\n");
            printf("Usage: n infile outfile\n");
            return 1;

        }
    }
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
    BITMAPFILEHEADER bf_in;
    fread(&bf_in, sizeof(BITMAPFILEHEADER), 1, inptr);

    // read infile's BITMAPINFOHEADER
    BITMAPINFOHEADER bi_in;
    fread(&bi_in, sizeof(BITMAPINFOHEADER), 1, inptr);

    // ensure infile is (likely) a 24-bit uncompressed BMP 4.0
    if (bf_in.bfType != 0x4d42 || bf_in.bfOffBits != 54 || bi_in.biSize != 40 ||
        bi_in.biBitCount != 24 || bi_in.biCompression != 0)
    {
        fclose(outptr);
        fclose(inptr);
        fprintf(stderr, "Unsupported file format.\n");
        return 4;
    }


    // read infile's BITMAPFILEHEADER for outfile
    BITMAPFILEHEADER bf_out = bf_in;


    // read infile's BITMAPINFOHEADER for outfile
    BITMAPINFOHEADER bi_out = bi_in;

    // conver value at n to int intN
    int intN = atoi(n);

    // Ch-ch-ch-ch-changes
    // declare width and height of outfile
    bi_out.biWidth = bi_in.biWidth * intN;
    bi_out.biHeight= bi_in.biHeight * intN;

    // determine padding for scanlines
    int oldPadding = (4 - (bi_in.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;
    int newPadding = (4 - (bi_out.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;


    // Ch-ch-changes
    // declare size of outfile and size of image
    bi_out.biSizeImage = ((sizeof(RGBTRIPLE) * bi_out.biWidth) + newPadding) * abs(bi_out.biHeight);
    bf_out.bfSize = bi_out.biSizeImage + sizeof(BITMAPFILEHEADER) + sizeof(BITMAPINFOHEADER);

   /* // Debugging print lines
    printf("n is: %d\n", intN);
    printf("length of n is: %d\n", length);
    printf("old width: %d\n", bi_in.biWidth);
    printf("new width: %d\n", bi_out.biWidth);
    printf("old height: %d\n", bi_in.biHeight);
    printf("new height: %d\n", bi_out.biHeight);
    printf("old padding: %d\n", oldPadding);
    printf("new padding: %d\n", newPadding);
    printf("size in bytes of a triple: %lu\n", sizeof(RGBTRIPLE));
*/

    // write outfile's BITMAPFILEHEADER
    fwrite(&bf_out, sizeof(BITMAPFILEHEADER), 1, outptr);

    // write outfile's BITMAPINFOHEADER
    fwrite(&bi_out, sizeof(BITMAPINFOHEADER), 1, outptr);

    // iterate over infile's scanlines
    for (int i = 0, biInfileHeight = abs(bi_in.biHeight); i < biInfileHeight; i++)
    {

        for (int x = 0; x < intN -1; x++){

             // iterate over pixels in scanline
        for (int j = 0; j < bi_in.biWidth; j++)
        {
            // temporary storage
            RGBTRIPLE triple;

            // read RGB triple from infile
            fread(&triple, sizeof(RGBTRIPLE), 1, inptr);



            // write RGB triple to outfile n times
                for (int k = 0; k < intN; k++)
                {
                    fwrite(&triple, sizeof(RGBTRIPLE), 1, outptr);
                }


        }



            // then add it back (to demonstrate how)
            for (int l = 0; l < newPadding; l++)
            {
                fputc(0x00, outptr);
            }
             fseek(inptr, - (bi_in.biWidth * sizeof(RGBTRIPLE)), SEEK_CUR);
        }


       // last row
        for (int k = 0; k < bi_in.biWidth; k++)
        {
            // temporary storage
            RGBTRIPLE triple;

            // read RGB triple from infile
            fread(&triple, sizeof(RGBTRIPLE), 1, inptr);

            // write RGB triple to outfile n times
            for (int l = 0; l < intN; l++)
            {
                fwrite(&triple, sizeof(RGBTRIPLE), 1, outptr);
            }
        }


        // then add padding of the outfile
        for (int m = 0; m < newPadding; m++)
        {
            fputc(0x00, outptr);
        }
        // skip over padding, if any
        fseek(inptr, oldPadding, SEEK_CUR);

    }

    // close infile
    fclose(inptr);

    // close outfile
    fclose(outptr);

    // success
    return 0;
}
