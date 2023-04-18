/*
Problem 1:
Find the error and correct problem1()
to write the number 10 on the screen.

void problem1()
{
    int x, *p, **q;
    p = &x;
    q = &p;
    x = 10;
    
    cout << &q << endl;
}

Problem 2:
Write a function that converts minutes into hours and
minutes using pointers, follow the code skeleton below
(there is a trick here):
# include <iostream>

using namespace std;

int transf(int x, int∗ i, int∗ n)
{
    //complete here
}

int main ()
{
    int minutes, h, m;

    cin >> minutes;

    transf(minutes, &h, &m);

    cout << "Minutes = " << minutes << endl;
    cout << "This means " << h << " hours and " << m << " minutes." << endl;

    return 0;
}

Problem 3:
Create a function that receives by parameter a vector of integers,
the addresses of two integer variables (which we can call min and max) and the size of
the array. When passing these variables to the function, your program should analyze
which is the largest and smallest element of the vector and deposit these elements in the
variables of the parameter.

void maxMin(int vector[], int∗ max, int∗ min, int n);
*/
#include <iostream>

using namespace std;

void problem1();
void transf(int, int*, int*);
void maxMin(int iArray[], int*, int*, int);

int main()
{
    // 1
    problem1();
    cout << endl;

    // 2
    int minutes, h, m;

    cin >> minutes;

    transf(minutes, &h, &m);

    cout << "Minutes = " << minutes << endl;
    cout << "This means " << h << " hour(s) and " << m << " minute(s)." << endl;
    cout << endl;

    // 3
    int iArray1[] = {1, 2, 3, 4, 5};
    int iArray2[] = {1, 0};
    int iArray3[] = {10, -20, 4, 2};

    int iMax, iMin;

    maxMin(iArray1, &iMax, &iMin, 5);
    cout << "Array 1\nMax: " << iMax << "\nMin: " << iMin << "\n" << endl;
    maxMin(iArray2, &iMax, &iMin, 2);
    cout << "Array 2\nMax: " << iMax << "\nMin: " << iMin << "\n" << endl;
    maxMin(iArray3, &iMax, &iMin, 4);
    cout << "Array 3\nMax: " << iMax << "\nMin: " << iMin << "\n" << endl;

    return 0;
}

void problem1()
{
    int x, *p, **q;
    p = &x;
    q = &p;
    x = 10;
    
    cout << **q << endl;
}

void transf(int x, int* i, int* n)
{
    *i = x / 60;
    *n = x % 60;
}

void maxMin(int iArray[], int* iMax, int* iMin, int iSize)
{
    *iMax = iArray[0];
    *iMin = iArray[0];

    for (int i = 0; i < iSize; i++)
    {
        if (*iMax < iArray[i]) {*iMax = iArray[i];}
        if (*iMin > iArray[i]) {*iMin = iArray[i];}
    }
}