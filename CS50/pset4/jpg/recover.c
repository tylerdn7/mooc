/**
 * recover.c
 *
 * Ahasanul Basher Hamza
 * ahasanulhamza133@gmail.com
 * 
 * hamza133
 * 
 * Computer Science 50
 * Problem Set 4
 *
 * Recovers JPEGs from a forensic image.
 */

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
    //opening the file using fopen
    FILE *in = fopen("card.raw","rb");
    
    //error checking
    if (in == NULL)
    {
        printf("Could not open the card file\n");
        return 1;
    }

    int i,d = 1,j = 0;
    
    //creating a pointer which will work in the program as a buffer.Whose purpose is to hold 512 bytes and work with those bytes
    
    unsigned char *x = malloc(sizeof(unsigned char) * 512);
    char title[10];
    
    //while file has not reached the end point fread is reading 512 bytes at a time
    
    while(fread(x,512,1,in) == 1)
    {
        
        //checking whether it hits the first 3 bytes of a jpeg image
        
        if(x[0] == 0xff && x[1] == 0xd8 && x[2] == 0xff)
        {
            //if it has found a image then we are incrementing its counter value to 1 at a time
            j++;
           
            d = j;
            
            if(j == 1)
            {
                i = 0;
            }
            else
            {
                ++i;
            }
        }
        if(j == d)
        {
            
            //for writing those bytes in a file first we are naming it using sprintf() function
            sprintf(title,"%.3d.jpg",i);
            
            //then opening a new file and write those 512 bytes until we found another jpeg image
            
            FILE *out = fopen(title,"ab");
            fwrite(x,512,1,out);
            
            //error checking
            if (out == NULL)
            {
                printf("Could not create the file\n");
                return 1;
            }
            //and closing the openend file while we are at the end of a jpeg image file
            fclose(out);
        }
    }
    
    //freeing the allocated memory
    
    free(x);
    
    //closing the opened file
    
    fclose(in);
    
    return 0;
}
