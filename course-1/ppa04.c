/**
** PPA 04
** Stock market Program
** Ahasanul Basher Hamza
** Date: 24/02/18
***/

#include <iostream>
#include <string>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
using namespace std;

int profitEarned(int prices[]){

    int max = -1000000;
    for(int i = 0;i < 5;i++)
    {
        for(int j = 0;j < i;j++)
        {
            int sub = prices[i] - prices[j];
            if(sub >= max)
            {
                max = sub;
            }
        }
    }
    return max;
}
int main()
{
    int prices[5];
    for(int i = 0;i < 5;i++)
    {
        scanf("%d", &prices[i]);
    }
    printf("%d\n",profitEarned(prices));
    return 0;
}
