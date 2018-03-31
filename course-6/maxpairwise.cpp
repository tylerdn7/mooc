/**
** Max Pairwise product
** Ahasanul Basher Hamza
** Date: 28/03/18
***/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <strings.h>
#include <math.h>
#include <ctype.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>
#include <iostream>
#include <cstdio>

using namespace std;
int findmaxindex(unsigned long long int ara[],int n)
{
    unsigned long long int i,max = 0,index = 0;
    for(i = 0;i < n;i++)
    {
        if(ara[i] >= max)
        {
            max = ara[i];
            index = i;
        }
    }
    return index;
}
int main()
{
    int n;
    scanf("%d", &n);
    int i,j;
    unsigned long long int ara[n];
    for(i = 0;i < n;i++)
    {
        scanf("%llu", &ara[i]);
    }
    //unsigned long long int res = maxpairwise(ara,n);
    int index1 = findmaxindex(ara,n);
    unsigned long long int number1 = ara[index1];
    ara[index1] = 0;
    int index2 = findmaxindex(ara,n);
    unsigned long long int number2 = ara[index2];
    ara[index2] = 0;
    unsigned long long int res = number1 * number2;
    printf("%llu\n",res);

    return 0;
}
