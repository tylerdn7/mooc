/**
 * greedy.c
 * 
 * Ahasanul Basher Hamza
 * ahasanulhamza133@gmail.com
 * 
 * hamza133
 * 
 * A program that first asks the user how much change is owed 
 * and then spits out the minimum number of coins
 * with which said change can be made
 * 
 * 
 **/
#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
    float n;
    
    // using do-while loop for asking user at least once for the input 
    
    do
    {
        printf("O hai! How much change is owed?\n");
        
        // using GetFloat() to take input from the user
        
        n = GetFloat();
    }
    while(n < 0);

    // rounding the value using round() function
    // and typecasting it to integer value
    
    int i = (int) round(n * 100);
    
    int count = 0;
    
    /* in each loop the program checks whether the value is greater than
     or equal to the conditional value if it is then it's subtracting that value
     each time the condtion is being checked and incrementing the count variable each
     time by 1 */
    
    while(i >= 25)
    {
        i -= 25;
        count++;
    }
    while(i >= 10)
    {
        i -= 10;
        count++;
    }
    while(i >= 5)
    {
        i -= 5;
        count++;
    }
    while(i >= 1)
    {
        i -= 1;
        count++;
    }
    
    // printing the owed amount
    
    printf("%d\n",count);
}
