/* 
 * File:   main.cpp
 * Author: Dr. Mark E. Lehr
 * Created on October 12th, 2016, 8:27 PM
 * Purpose:  Example Recursion
 */

//System Libraries Here
#include <iostream>
#include <cmath>
#include <iomanip>
#include <cstdlib>
#include <ctime>
using namespace std;

//User Libraries Here

//Global Constants Only, No Global Variables
//Like PI, e, Gravity, or conversions
const double PI = atan(1) * 4;

//Function Prototypes Here
float rExpVal(int, int);
float expVal(int, int);
float rFV(float,float,int);
float nonrFV(float,float,int);
int   bCoeff(int, int);
int   max(int *, int,int);
float rSin(float);
float rCos(float);
double rSin(double);
double rCos(double);

//Program Execution Begins Here
int main(int argc, char** argv) {
    srand(static_cast<unsigned int>(time(0)));
    
    //try the expected value recursion
    cout << "loop expected value km = 64, n = 64      = " << expVal(64,64) << endl;
    cout << "recursive expected value km = 64, n = 64 = " << rExpVal(64,64) << endl;
    cout << endl;
    
    //do the future value computations
    cout << fixed << setprecision(2) << showpoint;
    cout << "cmath output of future value     -> pv = 100, i = 0.08, n = 9 -> $"
            << 100 * pow(1 + 0.08, 9) << endl;
    cout << "loop output of future value      -> pv = 100, i = 0.08, n = 9 -> $"
            << nonrFV(100,0.08,9) << endl;
    cout << "recursive output of future value -> pv = 100, i = 0.08, n = 9 -> $"
            << rFV(100,0.08,9) << endl;
    cout << endl;
    
    //test the recursive binomial coefficient
    cout << "combination(5,2) = " << bCoeff(5,2) << endl;
    //output pascal's triangle
    for(int r = 0; r <= 5; r++)
    {
        cout << r << ". ";
        for(int c = 0; c <= r; c++)
        {
            cout << bCoeff(r,c) << ' ';
        }
        cout << endl;
    }
    cout << endl;
    
    //test the maximum recursive function by filling an
    //array and finding the max
    int *array = new int[10];
    cout << "the array to find the maximum value" << endl;
    for(int i = 0; i < 10; i++)
    {
        array[i] = rand() % 90 + 10;
        cout << array[i] << ' ';
    }
    cout << endl;
    cout << "the max value = " << max(array, 0, 10) << endl;
    
    delete [] array;
    
    //test the mutual recursive functions
    cout << fixed << setprecision(6) << showpoint;
    cout << "the recursive sin of PI/ 4 = 45deg = sqrt (2)/2 = " << rSin(PI/4) << endl;
    cout << "the recursive cos of PI/ 4 = 45deg = sqrt (2)/2 = " << rCos(PI/4) << endl;
    cout << "the math lib  sin of PI/ 4 = 45deg = sqrt (2)/2 = " << sin(PI/4) << endl;
    cout << "the math lib  cos of PI/ 4 = 45deg = sqrt (2)/2 = " << cos(PI/4) << endl;
    
    cout << "as a check sqrt(2) / 2 = " << sqrt(2) / 2 << endl;
    //Exit
    return 0;
}

double rSin(double angle)
{
    //base condition
    if(abs(angle) < 0.000001) return angle - (angle*angle*angle)/6;
    //recursion
    return 2 * rSin(angle / 2) * rCos(angle / 2);
}

double rCos(double angle)
{
    //base condition
    if(abs(angle) < 0.000001) return 1 - (angle*angle) / 2;
    //recursion
    double a = rCos(angle / 2);
    double b = rSin(angle / 2);
    return a*a - b*b;
}

float rSin(float angle)
{
    //base condition
    if(abs(angle) < 0.000001) return angle - (angle*angle*angle)/6;
    //recursion
    return 2 * rSin(angle / 2) * rCos(angle / 2);
}

float rCos(float angle)
{
    //base condition
    if(abs(angle) < 0.000001) return 1 - (angle*angle) / 2;
    //recursion
    float a = rCos(angle / 2);
    float b = rSin(angle / 2);
    return a*a - b*b;
}

int   max(int *a, int beg, int end)
{
    //base condition
    if(end - beg <= 1) return a[beg];
    //recursion
    int half = (end + beg) / 2;
    int m1 = max(a,beg,half);
    int m2 = max(a,half,end);
    return (m1 > m2 ? m1 : m2);
}

int bCoeff(int r, int c)
{
    //base condition
    if(c == 0) return 1;
    if(r == c) return 1;
    //recursion
    return bCoeff(r - 1, c - 1) + (bCoeff(r - 1, c));
}

float expVal(int km, int n)
{
    //base condition
    if(km <= 0) return 0;
    float sum = 0; 
    //loop to solve the recursion
    for(int i = 1; i <= km; i++)
    {
        sum *= (1 - 1.0f/n);
        sum += 1;
    }
}

float rExpVal(int km, int n)
{
    //base condition
    if(km <= 0) return 0;
    if(km == 1) return 1;
    //recursion
    return 1 + rExpVal(km-1,n) * (1 - 1.0f/n);
}

float rFV(float pv,float i,int n)
{
    //base condition
    if(n <= 0) return pv;
    //recursion
    return rFV(pv,i,n - 1) * (1 + i);
}

float nonrFV(float pv,float i,int n)
{
    //base condition
    float fv = pv;
    //loop
    for(int j = 1; j <= n; j++)
    {
        fv *= (1 + i);
    }
    return fv;
}