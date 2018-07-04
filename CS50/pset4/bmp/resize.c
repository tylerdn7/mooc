/**
 * resize.c
 *
 * Ahasanul Basher Hamza
 * ahasanulhamza133@gmail.com
 * 
 * hamza133
 * 
 * Computer Science 50
 * Problem Set 4
 *
 * a program called resize that 
 * resizes 24-bit uncompressed BMPs by a factor of n
 */
       
#include <stdio.h>
#include <stdlib.h>

#include "bmp.h"

int main(int argc, char* argv[])
{
    // ensure proper usage
    if (argc != 4)
    {
        printf("Usage: ./copy n infile outfile\n");
        return 1;
    }

    // remember filenames
    
    //converting string to an int using atoi() function and assigning it to an integer variable.
    
    int n = atoi(argv[1]);
    
    //error checking
    if(n < 1 || n > 100)
    {
        return 0;
    }
    char* infile = argv[2];
    char* outfile = argv[3];

    // open input file 
    FILE* inptr = fopen(infile, "r");
    if (inptr == NULL)
    {
        printf("Could not open %s.\n", infile);
        return 2;
    }

    // open output file
    FILE* outptr = fopen(outfile, "w");
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
    BITMAPFILEHEADER fh = bf;
    BITMAPINFOHEADER ih = bi;
    
    //changing image's height,width and image size with the user inputted value
    
    ih.biWidth *= n;
    ih.biHeight *= n;
    
    //new image will need more padding thats why declared a variable new_padding
    
    int new_padding = (4 - (ih.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;
    
    //varible chck contains each row size
    
    int chck = ih.biWidth * sizeof(RGBTRIPLE);
    
    //checks the value of chck until its a multiple of 4 and adds new_padding with it.
    
    while(chck % 4 != 0)
    {
        chck += new_padding;
    }
    
    //changing the value of bitmapheader info
    
    ih.biSizeImage = abs(ih.biHeight) * chck;
    fh.bfSize = 54 + abs(ih.biHeight) * chck;
    
    // write outfile's BITMAPFILEHEADER
    fwrite(&fh, sizeof(BITMAPFILEHEADER), 1, outptr);

    // write outfile's BITMAPINFOHEADER
    fwrite(&ih, sizeof(BITMAPINFOHEADER), 1, outptr);

    // determine padding for scanlines
    int padding =  (4 - (bi.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;
    
    // iterate over infile's scanlines
    for (int i = 0, biHeight = abs(bi.biHeight); i < biHeight; i++)
    {
        //iterating over the rows n-1 times
        
        for(int y = 0;y < n;y++)
        {
            // iterate over pixels in scanline
            for (int j = 0; j < bi.biWidth; j++)
            {
                // temporary storage
                RGBTRIPLE triple;
    
                // read RGB triple from infile
                fread(&triple, sizeof(RGBTRIPLE), 1, inptr);
                for(int k = 0;k < n;k++)
                {
                    // write RGB triple to outfile
                    fwrite(&triple, sizeof(RGBTRIPLE), 1, outptr);
                }
            }

            // skip over padding, if any
            fseek(inptr, padding, SEEK_CUR);
    
            // then add it back (to demonstrate how)
            for (int k = 0; k < new_padding; k++)
            {
                fputc(0x00, outptr);
            }
            
            //fseek back to the start of the original row.and repeat the row n - 1 times
            
            if(y < n - 1)
            {
                fseek(inptr,(-bi.biWidth * sizeof(RGBTRIPLE))-padding ,SEEK_CUR);
            }
        }
    }
    // close infile
    fclose(inptr);

    // close outfile
    fclose(outptr);

    // that's all folks
    return 0;
}