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
 * 
 **/
#include <stdio.h>
#include <cs50.h>

int main(void)
{
    printf("minutes: ");
    
    // using GetInt() for taking input from the user
    
    int n = GetInt();
    
    int u;
    
    u = 12 * n;
    
    printf("bottles: %d\n", u);
    
    
}