#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

/*
1) Take a number from the user and print that number of odd numbers. Bonus: do the same for prime numbers
2) Take a number from the user and print the absolute value without using the abs() function
*/

void problemOne();
void problemTwo();
bool isPrime(int iNumber);

int main()
{
    problemOne();
    problemTwo();

    return 0;
}

void problemOne()
{
    /*
    Take a number from the user and print that number of odd numbers. Bonus: do the same for prime numbers
    */
    int iNumber;

    cout << "Enter a number: ";
    cin >> iNumber;

    for (int i = 0; i < iNumber; i++)
    {
        cout << i*2 + 1 << endl;
    }

    // Bonus
    int iCount = 1;
    int iPrimeCount = 0;
    while (iPrimeCount < iNumber)
    {
        if (isPrime(iCount))
        {
            cout << iCount << endl;
            iPrimeCount++;
        }
        iCount++;
    }
}

void problemTwo()
{
    /*
    Take a number from the user and print the absolute value without using the abs() function
    */
    int iNumber;

    cout << "Enter a number: ";
    cin >> iNumber;

    if (iNumber < 0)
    {
        iNumber = -iNumber;
    }

    cout << iNumber << endl;
}

bool isPrime(int iNumber)
{
    /*
    Check if a number is prime
    */
    if (iNumber == 1)
    {
        return false;
    }

    for (int i = 2; i < iNumber; i++)
    {
        if (iNumber % i == 0)
        {
            return false;
        }
    }

    return true;
}