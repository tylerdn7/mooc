/**
** Prepare Yourself to Competitions!
** Ahasanul Basher Hamza
** Date: 20/03/18
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

int findmin(int ara[],int n)
{
    int i,min = ara[0],index = 0;
    for(i = 0;i < n;i++)
    {
        if(ara[i] <= min)
        {
            min = ara[i];
            index = i;
        }
    }
    return index;
}
int findsum(int ara[],int n)
{
    int i,sum = 0;
    for(i = 0;i < n;i++)
    {
        sum+= ara[i];
    }
    return sum;
}
void copyara(int ara[],int ara2[],int n)
{
    int i;
    for(i = 0;i < n;i++)
    {
        ara2[i] = ara[i];
    }
}
int main()
{
    #ifdef JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
    #endif

    int i,j,n;
    scanf("%d", &n);
    int ara[n];
    int ara2[n];
    for(i = 0;i < n;i++)
    {
        scanf("%d", &ara[i]);
    }
    for(i = 0;i < n;i++)
    {
        scanf("%d", &ara2[i]);
    }
    int max = 0,sum = 0,c = 0,d = 0;


    int ara3[n];
    for(i = 0;i < n;i++)
    {
        if(ara[i] >= ara2[i])
        {
            ara3[i] = ara[i];
            c++;
        }
        else if(ara2[i] >= ara[i])
        {
            ara3[i] = ara2[i];
            d++;
        }
    }
    if(c > 0 && d > 0)
    {
        for(i = 0;i < n;i++)
        {
            sum += ara3[i];
        }
    }
    for(i = 0;i < n;i++)
    {
        int tempu[n];
        copyara(ara3,tempu,n);
        if(c > 0 && d == 0)
        {
            int k1 = findmin(ara,n);
            tempu[k1] = ara2[k1];
            ara[k1] = 999999;
            if(findsum(tempu,n) >= sum)
            {
                sum = findsum(tempu,n);
            }
        }

    }
    for(i = 0;i < n;i++)
    {
        int tempu[n];
        copyara(ara3,tempu,n);
        if(d > 0 && c == 0)
        {
            int k1 = findmin(ara2,n);
            tempu[k1] = ara[k1];
            ara2[k1] = 999999;
            if(findsum(tempu,n) >= sum)
            {
                sum = findsum(tempu,n);
            }
        }
    }
    printf("%d\n",sum);
    return 0;
}
