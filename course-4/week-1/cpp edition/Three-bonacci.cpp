/**
** Three-bonacci
** Ahasanul Basher Hamza
** Date: 28/3/18
***/

#ifdef JUDGE
#include <fstream>
std::ifstream cin("input.txt");
std::ofstream cout("output.txt");
#else
#include <iostream>

using namespace std;

#endif

int main()
{
    long long a,b,c,d;
    long long fib[150000];
    cin >> a >> b >> c >> d;
    fib[0] = a;
    fib[1] = b;
    fib[2] = c;
    for(int i = 3;i < 150000;i++)
    {
        fib[i] = fib[i-1] + fib[i-2] - fib[i-3];
    }
    if(d < 0)
    {
        cout << fib[d+1] << std::endl;
    }
    else
    {
        cout << fib[d] << std::endl;
    }

    return 0;
}
