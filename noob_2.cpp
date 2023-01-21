#include <iostream>
using namespace std;

int main() {
    int a;
    int b;

    cout << "Enter two numbers: ";
    cin >> a >> b;

    int c = a + b;
    cout << c << endl;

    int intMax = INT_MAX;
    cout << intMax << " -> " << intMax + 1 << endl;
    // standard int size is 4 bytes, going beyond that will cause overflow

    cout << (int)'a' << endl;
    cout << int('a') << endl;
    cout << int('A') << endl;
    cout << char(66) << endl;

    system("cls");

    cout << a++ << endl; // a is incremented after being printed
    cout << a << endl;
    cout << ++a << endl; // a is incremented before being printed

    a == b ? cout << "a == b" << endl : cout << "a != b" << endl;

    system("pause");
    return 0;
}