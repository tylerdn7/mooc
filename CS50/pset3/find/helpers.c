/**
 * helpers.c
 * 
 * Ahasanul Basher Hamza
 * ahasanulhamza133@gmail.com
 * 
 * hamza133
 *
 * Computer Science 50
 * Problem Set 3
 *
 * Helper functions for Problem Set 3.
 */
       
#include <cs50.h>

#include "helpers.h"

/**
 * Returns true if value is in array of n values, else false.
 */
bool search(int value, int values[], int n)
{
    // TODO: implement a searching algorithm
    
    //error check
    
    if(n <= 0)
    {
        return false;
    }
    
    //implementing binary search
    
    int low = 0,high = n-1,mid;

    //iterating over all the elements of the array values[]

    for(int i = 0;i < n;i++)
    {
        //dividing the array into two parts
        
        mid = (high + low) / 2;
        
        //if the value is the middle value of the sorted array then returns true
        
        if(values[mid] == value)
        {
            return true;
        }
        
        //else if value is greater than the mid value then assigning low to mid + 1 value
        
        else if(value > values[mid])
        {
            low = mid + 1;
        }
        
        //else if value is lower than the mid value then assigning high to mid - 1 value
        
        else if(value < values[mid])
        {
            high = mid - 1;
        }
    }
            
    return false;
}

/**
 * Sorts array of n values.
 */
void sort(int values[], int n)
{
    // TODO: implement an O(n^2) sorting algorithm
    
    //implementing the bubble sort algorithm to sort the values[] array
    
    for(int i = 0; i < n - 1; i++)
    {
        
        for(int j = 0; j < n - i - 1; j++)
        {
            //if values[j] > values[j+1] then swapping their values using a temporary variable swap
                         
            if(values[j] > values[j+1])
            {
                int swap = values[j];
                values[j] = values[j+1];
                values[j+1] = swap;
            }
        }
    }
    return;
}