/**
** LCM fast
** Ahasanul Basher Hamza
** Date: 4/1/18
***/

#include <iostream>

long long lcm_naive(int a, int b)
{
    for (long l = 1; l <= (long long) a * b; ++l)
    {
        if (l % a == 0 && l % b == 0)
        return l;
    }
    return (long long) a * b;
}
unsigned long long gcd(unsigned long long a,unsigned long long b)
{
    if(b == 0)
    {
     return a;
    }
    a = a % b;
    return gcd(b,a);
}
int main()
{
    unsigned long long a, b;
    std::cin >> a >> b;
    unsigned long long lcm = (a*b) / gcd(a,b);
    std::cout << lcm << std::endl;
    return 0;
}
