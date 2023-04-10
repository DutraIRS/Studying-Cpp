#include <iostream>

using std::cout;
using std::endl;
using std::string;

void firstTrade(int&, int&);
void secondTrade(int&, int&);

int main()
{
    string strName = "Yuri Saporito";
    int iValue = 42;

    cout << "\n===========" << endl;
    cout << "String value: " << strName << ". String address: " << &strName << endl;
    cout << "Integer value: " << iValue << ". Integer address: " << &iValue << endl;
    cout << "===========" << endl;

    string& strrefName = strName;
    int& irefValue = iValue; // typeof(this) = reference to an int

    cout << "String reference value: " << strrefName << ". String reference address: " << &strrefName << endl;
    cout << "Integer reference value: " << irefValue << ". Integer reference address: " << &irefValue << endl;
    cout << "===========" << endl;

    strrefName = "Camacho";
    irefValue = 666;

    cout << "String value: " << strName << ". String address: " << &strName << endl; // Changing the reference changes the original
    cout << "Integer value: " << iValue << ". Integer address: " << &iValue << endl;
    cout << "===========" << endl;

    int iNum1 = 7;
    int iNum2 = 42;

    cout << "Nums: " << iNum1 << ", " << iNum2 << endl;

    firstTrade(iNum1, iNum2);

    cout << "Nums: " << iNum1 << ", " << iNum2 << endl;

    secondTrade(iNum1, iNum2);

    cout << "Nums: " << iNum1 << ", " << iNum2 << endl;

    return 0;
}

void firstTrade(int& irefValue1, int& irefValue2)
{
    int iTemp = irefValue1;
    irefValue1 = irefValue2;
    irefValue2 = iTemp;
}

void secondTrade(int& irefValue1, int& irefValue2)
{
    irefValue1 = irefValue1 + irefValue2; // irefValue1 = 49
    irefValue2 = irefValue1 - irefValue2; // irefValue2 = 42
    irefValue1 = irefValue1 - irefValue2; // irefValue1 = 7
}