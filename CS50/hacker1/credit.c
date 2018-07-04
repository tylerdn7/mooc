/**
 * credit.c
 * 
 * Ahasanul Basher Hamza
 * ahasanulhamza133@gmail.com
 * 
 * hamza133
 * 
 * A program that prompts the user for a credit card
 * number and then reports (via printf) whether it is
 * a valid American Express, MasterCard, or Visa card number
 * 
 * 
 * 
 **/
 
#include <stdio.h>
#include <cs50.h>

int main()
{
    printf("Number: ");
    long long int n = GetLongLong();
    int a,b,c,d = 0,e = 0,f,g;
    int ara[20];
    
    int i = 0;
    int s = 0;
    while(n != 0)
    {
        a = n % 10;
        n = n / 10;
        ara[i] = a;
        s++;
        i++;
        
    }
    g = ara[15];  
    for(i = 1;i < s;i+=2)
    {
        b = (ara[i] % 10) * 2;
        ara[i] = ara[i] / 2;
        while(b != 0)
        {
            c = b % 10;
            b = b / 10;
            d = d + c;
        }
    }
    for(i = 0;i < s;i+=2)
    {      
        e = e + ara[i];
    }
    f = e + d;
    if((f % 2 == 0) && (s == 15))
    {
        printf("AMEX\n");
        
    }
    else if((f % 2 == 0)  && (g == 4))
    {
        printf("VISA\n");
        
    }
    else if((f % 2 == 0) && (s == 16))
    {
        printf("MASTERCARD\n");
    }
    else 
    {
        printf("INVALID\n");
    }
    
}