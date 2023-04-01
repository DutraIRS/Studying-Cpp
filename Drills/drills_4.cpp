/*
Problem 1:
Given some integer n (1 ≤ n ≤ 10000) that is not divisible by 2 or 5,
there exists some multiple of n formed only by 1's (for example,
3 divides 111, 7 divides 111111 and 9901 divides 111111111111).
Your task is to find that number, returning only the amount of 1's.
See the examples of input and output:
>>>7
6
>>>9901
12

Problem 2:
Josephus' problem is known by the legend of Flavius Josephus, a Jewish historian
who lived in the first century. In the problem we have 40 soldiers that, to not
give up, decide to kill each other forming a circle, where each one kills the
soldier on his left (for example, if there are 5 soldiers, soldier 1 kills soldier 2,
soldier 3 kills soldier 4, soldier 5 kills soldier 1 and soldier 3 kills soldier 5,
leaving soldier 3 alive). Your task is, given a number of soldiers, to determine
who survived implementing the function recursively. See some examples of input
and output:
>>> 5
3
>>> 11
7

In the original problem they killed with an interval of 3, that is, 1 kills 3,
4 kills 6, 7 kills 9 etc. Implement the solution of this problem recursively, receiving the
number n of soldiers and the k of the interval between the deaths, returning the
survivor. Following the examples:
>>> 5 2
3
>>> 6 3
1
>>> 1234 233
25
*/

#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

int oneMultiple (int n);
int josephus (int n, int k);

int main()
{
    cout << oneMultiple(7) << endl;
    cout << oneMultiple(9901) << endl;

    cout << josephus(5, 2) << endl;
    cout << josephus(6, 3) << endl;

    return 0;
}

int oneMultiple (int n)
{
    if (n % 2 == 0 || n % 5 == 0)
    {
        cout << "Invalid number" << endl;
        return 0;
    } else
    {
        int iCount = 1;
        long long int iMultiple = 1;
        while (iMultiple % n != 0)
        {
            iMultiple *= 10;
            iMultiple++;
            iCount++;
        }
        return iCount;
    }
}

int josephus (int n, int k)
{
    if (n == 1)
    {
        return 1;
    } else
    {
        return ((josephus(n - 1, k) + k - 1) % n ) + 1;
    }
}