/**
** Three-bonacci
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

    long long int a,b,c,d;
    scanf("%lld %lld %lld %lld",&a, &b, &c, &d);
    long long int fib[150000];
    fib[0] = a;
    fib[1] = b;
    fib[2] = c;
    int i;
    for(i = 3;i < 150000;i++)
    {
        fib[i] = (fib[i-1] + fib[i-2]) - fib[i-3];
    }
    if(d < 0)
    {
        printf("%lld\n",fib[d-1]);
    }
    else
    {
        printf("%lld\n",fib[d]);
    }
    return 0;
}
