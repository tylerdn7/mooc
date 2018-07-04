#include <iostream>

int get_fibonacci_last_digit_naive(int n) 
{
    if (n <= 1)
        return n;

    int previous = 0;
    int current  = 1;

    for (int i = 0; i < n - 1; ++i) 
    {
        int tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
    }

    return current % 10;
}
int get_fibonacci_last(int n)
{
   if(n <= 1)
   {
    return n;
   }
    unsigned long long int fib[n+1],sum = 0;
    fib[0] = 0;
    fib[1] = 1;
    for(int i = 2;i < n+1 ;i++)
    {
        fib[i] = (fib[i-1] + fib[i-2]) % 10;
        sum = fib[i];
    }
 return sum;
}
int main() 
{
    int n;
    std::cin >> n;
    int c = get_fibonacci_last(n);
    std::cout << c << '\n';
}
