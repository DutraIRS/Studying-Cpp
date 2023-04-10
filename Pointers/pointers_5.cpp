#include <iostream>

using namespace std;

// Built-in array (C-style) vs Array/Vector (C++ style)
// String vs C-style

int cube(int*);
// int vectorSum(const int[], const size_t);
int vectorSum(const int*, const size_t);
// Passing an array to a function is equivalent to passing a constant pointer to the first element of the array

int main()
{
    // Variable: direct reference to memory location
    // Pointer: indirect reference to memory location

    //int* ptrInt = 0; // Pointer must be initialized (risk of crash or memory leak)
    //int* ptrInt = NULL;
    int* ptrInt = nullptr;

    cout << "Pointer: " << ptrInt << endl;
    cout << "Pointer's address: " << &ptrInt << endl;

    int iMagicNumber = 42;
    cout << "iMagicNumber's address: " << &iMagicNumber << endl;
    cout << "\n==================\n" << endl;

    ptrInt = &iMagicNumber;

    cout << "Pointer: " << ptrInt << endl;
    cout << "Pointer's address: " << &ptrInt << endl;

    cout << "\n==================\n" << endl;
    
    cout << "Size of types: " << endl;
    cout << "char: " << sizeof(char) << endl;
    cout << "int: " << sizeof(int) << endl;
    cout << "double: " << sizeof(double) << "\n" << endl;

    cout << "Size of pointers to types: " << endl;
    cout << "char*: " << sizeof(char*) << endl;
    cout << "int*: " << sizeof(int*) << endl;
    cout << "double*: " << sizeof(double*) << endl;

    cout << "\n==================\n" << endl;

    cout << "Pointer: " << ptrInt << endl;
    cout << "Pointer's address: " << &ptrInt << endl;
    cout << "Pointer's value: " << *ptrInt << endl; // Dereference

    cout << "\n==================\n" << endl;

    int iNum1 = 42;
    int iNum2 = 666;

    int* const ptrNum1 = &iNum1; // Constant pointer
    *ptrNum1 = 666; // OK
    //ptrNum1 = &iNum2; // Error
    // The pointer itself is constant, not the value it points to

    cout << "iNum1: " << iNum1 << endl;
    cout << "*ptrNum1: " << *ptrNum1 << endl;

    const int* ptrNum2 = &iNum2; // Pointer to constant
    //*ptrNum2 = 42; // Error
    ptrNum2 = &iNum1; // OK
    // The value it points to is constant, not the pointer itself

    const int* const ptrNum3 = &iNum1; // Constant pointer to constant
    //*ptrNum3 = 42; // Error
    //ptrNum3 = &iNum2; // Error
    // The pointer itself and the value it points to are constant

    cout << "\n==================\n" << endl;

    int iValue = 3;
    int iCube = cube(&iValue);

    int arriValues[] = {0, 1, 2, 3};
    int iSum = vectorSum(arriValues, 4);

    return 0;
}

int cube(int* ptrValue)
{
    return (*ptrValue) * (*ptrValue) * (*ptrValue);
}

// int vectorSum(const int values[], const size_t vecSize)
// {
//     return -1;
// }

int vectorSum(const int* values, const size_t vecSize)
{
    return -1;
}