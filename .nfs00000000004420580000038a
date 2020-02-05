#include <stdio.h>
#include <math.h>

//Aly Husein, CS 2211 Assignment 4 Task 2

//Initializing variables
double smallNumE;
long long i;
long long n = 1000000;
double pi = 0;
double smallerThan = 0;

int main()
{
    //Taking user entry for number E
    printf("Please enter a number:\n");
    scanf("%lf", &smallNumE);
    
    //Loops until n is the smallest integer it can be for the formula in the loop to work
    while (smallNumE > smallerThan)
    {
        smallerThan = (4.0/(2.0*(n+1.0)-1.0));
        n = n-1;
    }

    //For Loop to add until i becomes n
    for (i=1; i < (n+1); i++)
    {
        pi += (pow(-1, (i+1)))*(4.0/((2.0*i)-1.0));
    }
    
    printf("Pi is %lf\n", pi);
}
