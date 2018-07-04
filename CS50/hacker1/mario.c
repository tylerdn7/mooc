/**
 * mario.c
 * 
 * Ahasanul Basher Hamza
 * ahasanulhamza133@gmail.com
 * 
 * hamza133
 * 
 * A program that recreates half-pyramids using hashes (#) for blocks
 * 
 * 
 **/
 
#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int n;
    do
    {
        printf("height: ");
        n = GetInt();
        if(n == 0)
        {
            return 0;
        }
    }
    while(n < 1 || n > 23);
    
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n-i-1; j++)
        {
            printf(" ");
        }
        for(int k = 0; k < i + 1; k++)
        {
            printf("#");
        }
        printf("  ");
        for(int l = 0;l < i + 1; l++)
        {
            printf("#");
        }
        printf("\n");
    }
}