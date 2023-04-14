#include <iostream>

using namespace std;

int main()
{
    int arriValues[] = { 7, 90, 42, 666 };
    cout << "arriValues: " << arriValues << endl;

    int* ptrArrayValues = arriValues;
    cout << "ptrArrayValues: " << ptrArrayValues << endl;

    int* ptrArrayValues2 = &arriValues[0];
    cout << "ptrArrayValues2: " << ptrArrayValues2 << endl;

    cout << "\n==================\n" << endl;

    cout << "value of ptrArrayValues[0]+1: " << ++*ptrArrayValues << endl;
    cout << "value of ptrArrayValues[0]+1: " << *ptrArrayValues++ << endl;
    cout << "value of ptrArrayValues[1]: " << *ptrArrayValues << endl; // weird

    ptrArrayValues++;
    cout << "value of ptrArrayValues[2]: " << *ptrArrayValues << endl;

    cout << "weird value: " << ptrArrayValues - ptrArrayValues2 << endl;
    
    cout << "\n==================\n" << endl;

    return 0;
}