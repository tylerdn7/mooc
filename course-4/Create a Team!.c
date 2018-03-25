/**
** Create a Team!
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

    int a1,b1,c1,a2,b2,c2,a3,b3,c3;
    int i,j,k;
    scanf("%d %d %d", &a1,&b1,&c1);
    scanf("%d %d %d", &a2,&b2,&c2);
    scanf("%d %d %d", &a3,&b3,&c3);
    int ara1[3],ara2[3],ara3[3];
    ara1[0] = a1;
    ara1[1] = b1;
    ara1[2] = c1;
    ara2[0] = a2;
    ara2[1] = b2;
    ara2[2] = c2;
    ara3[0] = a3;
    ara3[1] = b3;
    ara3[2] = c3;
    double max = 0.0;
    for(i = 0;i < 3;i++)
    {
        for(j = 0;j < 3;j++)
        {
            for(k = 0;k < 3;k++)
            {
                double res = 0.0;
                if(i != j && i != k && j != k)
                {
                    res = (ara1[i] * ara1[i]) + (ara2[j] * ara2[j]) + (ara3[k] * ara3[k]);
                    res = sqrt(res);
                }
                if(res > max)
                {
                    max = res;
                }
            }
        }
    }
    printf("%lf\n",max);
    return 0;
}
