/**
** Win the Competition!
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

void sortr(int ara[],int n)
{
    int i,j;
    for(i = 0;i < n;i++)
    {
        for(j = 0;j < n-1;j++)
        {
            if(ara[j] > ara[j+1])
            {
                int swap = ara[j];
                ara[j] = ara[j+1];
                ara[j+1] = swap;
            }
        }
    }
}
int main()
{
    #ifdef JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
    #endif

    int n,i,j = 0, sum = 0;
    scanf("%d", &n);
    int ara[n];
    for(i = 0;i < n;i++)
    {
        scanf("%d", &ara[i]);
    }
    sortr(ara,n);
    for(i = 0;i < n;i++)
    {
        sum += ara[i];
        if(sum > 18000)
        {
            break;
        }
        j++;
    }
    printf("%d\n",j);
    return 0;
}
