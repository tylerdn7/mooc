/**
** Put the Chairs the Right Way!
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

int main()
{
    #ifdef JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
    #endif

    int a1,b1,c1;
    int i,j,k;
    scanf("%d %d %d", &a1,&b1,&c1);
    double max = 0.0;
    max = ((double)a1+b1+c1) / 6;
    printf("%lf\n",max);
    return 0;
}
