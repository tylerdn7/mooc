/**
** IIT CSE - 102
** Graded Programming Assignment 01
** Ahasanul Basher Hamza
** Date: 27/02/18
***/

#include <iostream>
#include <string>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>

using namespace std;

struct rational {
   int numerator;
   int denominator;
};

/*Question: Reduce the number 'inputrational' to its lowest form and store it in 'outputrational'
struct rational *inputrational  : Actual rational number to be reduced
struct rational *outputrational : Variable to store the rational number in its lowest form */
void reduce(struct rational *inputrational, struct rational *outputrational) 
{
    int a = inputrational->numerator;
    int b = inputrational->denominator;
    for(int i = 1;i <= b;i++)
    {
        if(a % i == 0 && b % i == 0)
        {
            a /= i;
            b /= i;
            i = 1;
        }
    }
    outputrational->numerator = a;
    outputrational->denominator = b;

}

/* Question: Check whether both the rational numbers obtained in the lowest form are equal or not.
             Retrun true or false accordingly
struct rational *rational_number1: Denotes the first rational number
struct rational *rational_number2: Denotes the second rational number */
bool isEqual(struct rational num1, struct rational num2) 
{
    reduce(&num1,&num1);
    int a = num1.numerator;
    int b = num1.denominator;
    reduce(&num2,&num2);
    int c = num2.numerator;
    int d = num2.denominator;
    if(a == c && b == d)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
   int result;
   struct rational num1, num2;
   cout << "Enter Details of Number 1 " << endl;
   cout << "Enter Numerator :" << endl;
   cin >> num1.numerator;
   cout << "Enter Denominator :" << endl;
   cin >> num1.denominator;
   cout << "Enter Details of Number 2 " << endl;
   cout << "Enter Numerator :" << endl;
   cin >> num2.numerator;
   cout << "Enter Denominator :" << endl;
   cin >> num2.denominator;
   result = isEqual(num1, num2);     //to check rational 'num1' is equal to rational 'num2'
   if(result == true)
      cout << "Both rational numbers are equal" << endl;
   else
      cout << "Both rational numbers are not equal" << endl;
   return 0;
}
