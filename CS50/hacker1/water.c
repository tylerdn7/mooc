/**
 * water.c
 * 
 * Ahasanul Basher Hamza
 * ahasanulhamza133@gmail.com
 * 
 * hamza133
 * 
 * A program that prompts the user for the length of his or her shower 
 * in minutes (as a positive integer) and then 
 * prints the equivalent number of bottles of water
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
        printf("minutes: ");
        n = GetInt();
    }
    while(n < 1);
    printf("bottles: %d\n", n * 12);
}