#include <iostream>

using std::cin;
using std::cout;
using std::endl;
using std::string;

int factorial(int iNum);
int recursive_factorial(int iNum);

int main()
{
    int arriExample[2][3] = {{1, 2, 3}, {4, 5, 6}};
    //int arriExample[2][3] = {1, 2, 3, 4, 5, 6}; would also work
    //int arriExample[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int arriExample2[4];

    arriExample2[0] = 8;
    arriExample2[1] = 64;
    arriExample2[2] = 256;
    arriExample2[3] = 512;

    cout << "Value: " << arriExample2[0] 
         << "\nAddress: " << &arriExample2[0] << endl;
    cout << "\nValue: " << arriExample2[1] 
         << "\nAddress: " << &arriExample2[1] << endl;
    cout << "\nValue: " << arriExample2[2] 
         << "\nAddress: " << &arriExample2[2] << endl;
    cout << "\nValue: " << arriExample2[3]
         << "\nAddress: " << &arriExample2[3] << endl;
    cout << "\nValue: " << arriExample2[4]
         << "\nAddress: " << &arriExample2[4] << endl;
    cout << "\nValue: " << arriExample2[40]
         << "\nAddress: " << &arriExample2[40] << endl;
    cout << "\nValue: " << arriExample2[-40]
         << "\nAddress: " << &arriExample2[-40] << endl;

    cout << "\n ----------- \n" << endl;

    if (&arriExample2[0] == arriExample2) cout << "True" << endl;
    else cout << "False" << endl;

    cout << arriExample2 << endl;
    cout << "\n ----------- \n" << endl;

    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << "(" << i << ", " << j << ") = "<< arriExample[i][j]
                 << "\tAddress: " << &arriExample[i][j] << endl;
        }
    }

    cout << "\n ----------- \n" << endl;

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            cout << "(" << i << ", " << j << ") = "<< arriExample[i][j]
                 << "\tAddress: " << &arriExample[i][j] << endl;
        }
    }

     factorial(2);
     factorial(3);
     factorial(4);
     factorial(1);
     factorial(0);
     factorial(5);

     cout << recursive_factorial(2) << endl;
     cout << recursive_factorial(3) << endl;
     cout << recursive_factorial(4) << endl;
     cout << recursive_factorial(1) << endl;
     cout << recursive_factorial(0) << endl;
     cout << recursive_factorial(5) << endl;

    return 0;
}

int factorial(int iNum)
{
     int iResult = 1;

     for (int i = 2; i <= iNum; i++)
     {
          iResult *= i;
     }

     cout << iResult << endl;
     return iResult;
}

int recursive_factorial(int iNum)
{
     if (iNum == 1) return 1;

     return recursive_factorial(iNum - 1)*iNum;
}