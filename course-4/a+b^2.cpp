/**
** A + B^2
** Ahasanul Basher Hamza
** Date: 20/3/18
***/

#ifdef JUDGE
#include <fstream>
std::ifstream cin("input.txt");
std::ofstream cout("output.txt");
#else
#include <iostream>
using std::cin;
using std::cout;
#endif

int main()
{
    long long a, b;
    cin >> a >> b;
    cout << a + (b*b) << std::endl;
    return 0;
}
