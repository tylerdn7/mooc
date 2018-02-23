/**
** GPA 01
** RPM counting Program
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


void solutionRPM(long long int rpm, int &years, long long int &finalRPM) {

    long long int total_rpm = rpm * 8;
    long long int sum = 0;
    int count = 0;
    while(sum <= total_rpm && count < 10)
    {
        sum = 0;
        int p = rpm % 1000;
        p /= 10;
        while(rpm != 0)
        {
            long long int k = rpm % 10;
            sum += (k * k);
            rpm /= 10;
        }
        sum *= 323;
        sum += p;
        rpm = sum;
        count++;
    }
    finalRPM = rpm;
    years = count;

}
int main()
{
    long long int n;
    scanf("%lld", &n);
    int year;
    long long int finalrp;
    int &x = year;
    long long int &y = finalrp;
    solutionRPM(n,x,y);
    printf("%d %lld\n",year,finalrp);
    return 0;
}
