/**
 * mario.c
 * 
 * Ahasanul Basher Hamza
 * ahasanulhamza133@gmail.com
 * 
 * hamza133
 * 
 * A program that recreates half-pyramid using hashes (#) for blocks
 * 
 * 
 **/
#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int n;
    
    // using do-while loop for asking user the right input
    
    do
    {
        printf("height: ");
        
        // using GetInt() function from cs50 library to take input from the user
        
        n = GetInt();
        
        // error checking
        
        if(n == 0)
        {
            return 0;
        }
    }
    while(n < 1 || n > 23);
    
    // first loop is iterating over the rows
    // second loop is iterating over the columns and printing spaces
    
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n - i - 1; j++)
        {
            printf(" ");
        }
        
        // third for loop is using for printing the hashes
        
        for(int k = 0; k < i + 2; k++)
        {
            printf("#");
        }

        printf("\n");
    }
}