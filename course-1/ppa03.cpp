/**
** Course : IIT CSE 101
** Practice Programming Assignment 03
** Ahasanul Basher Hamza
** Date: 22/02/18
***/

#include <iostream>
#include <string>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
using namespace std;

void detectHappy(int number, int &finalNumber, int &cycle_no) {

    //Write your solution code below this line
    int sum = 0;
    int c = 0;
    while(sum != 1)
    {
        sum = 0;
        if(c >= 10)
        {
            break;
        }
        while(number != 0)
        {
            int k = number % 10;
            sum += k * k;
            number /= 10;
        }
        number = sum;
        ++c;
    }
    cycle_no = c;
    finalNumber = number;

}
int main()
{
    int n;
    scanf("%d", &n);
    int finalNumber;
    int cycle_no;
    int& x = finalNumber;
    int& y = cycle_no;
    detectHappy(n,x,y);
    printf("%d %d\n",finalNumber,cycle_no);
}
