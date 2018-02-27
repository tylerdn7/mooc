/**
** IIT CSE - 101
** Graded Programming Assignment -02  
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


/* Question          : count number of students scoring X marks in GQ and store it in 'sum_gq'
   int numOfStudents : Integer number containing the total number of students
   int gq[]          : Integer array containing the GQ marks of all students
   int sum_gq[]      : Integer array to be computed  */
void getTotalGQ(int numOfStudents, int gq[], int sum_gq[]) {
    // Write your solution code below this line
    for(int i = 0;i < 11;i++)
    {
        sum_gq[i] = 0;
    }
    for(int i = 0;i < numOfStudents;i++)
    {
        ++sum_gq[gq[i]];
    }

}



/* Question          : Count number of students scoring Y marks in GPA and store it in 'sum_gpa'
   int numOfStudents : Integer number containing the total number of students
   float gpa[]       : Array of type float containing the GPA marks of all students
   int sum_gpa[]     : Integer array to be computed */
void getTotalGPA(int numOfStudents, float gpa[], int sum_gpa[]) {
    // Write your solution code below this line
     for(int i = 0;i < 4;i++)
    {
        sum_gpa[i] = 0;
    }
    for(int i = 0;i < numOfStudents;i++)
    {
        int r = gpa[i] * 10;
        if(r == 0)
        {
            ++sum_gpa[0];
        }
        else if(r == 3)
        {
            ++sum_gpa[1];
        }
        else if(r == 6)
        {
            ++sum_gpa[2];
        }
        else if(r == 10)
        {
            ++sum_gpa[3];
        }
    }

}



/* Question          : Count number of students scoring X marks in GQ, Y marks in GPA, total, and result, in 'count[][]'
   int numOfStudents : Integer number containing the total number of students
   int gq[]          : Integer array containing the GQ marks of all students
   float gpa[]       : Array of type float, containing the GPA marks of all students
   int count[][]     : Integer array to be computed */
void getTotalCount(int numOfStudents, int gq[], float gpa[], int count[][5]) {
    // Write your solution code below this line
    for(int i = 0;i < 12;i++)
    {
        for(int j = 0;j < 5;j++)
        {
            count[i][j] = 0;
        }
    }
    for(int i = 0;i < numOfStudents;i++)
    {
        int r = gpa[i] * 10;
        if(r == 0)
        {
            ++count[gq[i]][0];
        }
        else if(r == 3)
        {
            ++count[gq[i]][1];
        }
        else if(r == 6)
        {
            ++count[gq[i]][2];
        }
        else if(r == 10)
        {
            ++count[gq[i]][3];
        }
    }
    for(int i = 0;i < 11;i++)
    {
        int sum = 0;
        for(int j = 0;j < 4;j++)
        {
            sum += count[i][j];
        }
        count[i][4] = sum;
    }
    int sum = 0;
    for(int i = 0; i < 11;i++)
    {
        sum+=count[i][4];
    }
    count[11][4] = sum;
    for(int i = 0;i < 4;i++)
    {
        int sum = 0;
        for(int j = 0;j < 11;j++)
        {
            sum += count[j][i];
        }
        count[11][i] = sum;
    }

}


int main()
{
    int numOfStudents = 54;
    float gpa[54];
    int sum_gpa[4];
    int gq[54];
    int t;
    int count[12][5];
    for(int i = 0;i < 12;i++)
    {
        for(int j = 0;j < 5;j++)
        {
            count[i][j] = 0;
        }
    }
    for(int i = 0;i < numOfStudents;i++)
    {
        scanf("%d %d %f",&t,&gq[i],&gpa[i]);
    }
    getTotalCount(54,gq,gpa,count);
    printf("\nMarks\nGQ\\GPA\t0\t0.3\t0.6\t1\tGQ Total\n");
    for(int i = 0;i < 5;i++)
    {
        printf("_ _ _ _ _");
    }
    printf("\n");
    for(int i = 0;i < 12;i++)
    {
        if(i == 11)
        {
            printf("GPA Total:\n%d\t",i);
        }
        else
        {
            printf("%d\t",i);
        }
        for(int j = 0;j < 5;j++)
        {
            printf("%d\t",count[i][j]);
        }
        printf("\n");
    }
    return 0;
}
