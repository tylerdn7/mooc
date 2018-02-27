/**
** IIT CSE - 101
** Practice Programmin Assignment - 03
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

int * getArray1D(int n) 
{
    int *ara = new int[n];
    return ara;
}


/*Question: return a 2D array to the 'main' program(not shown). It should call the above function 'getArray1D' to get 1D array of size 'n'. */
int ** getArray2D(int m, int n, int **Aptr) 
{
    Aptr = new int*[m];
    for(int i = 0;i < m;i++)
    {
        Aptr[i] = new int[n];
    }
    return Aptr;

}
int main()
{
    int *ara1;
    int n;
    cin >> n;
    ara1 = getArray1D(n);
    int m1,n1;
    cin >> m1 >> n1;
    int **ara2;
    ara2 = getArray2D(m1,n1,ara2);
    return 0;
}
