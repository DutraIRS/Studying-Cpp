#include <iostream>
using namespace std;

int main() {

    float num1, num2;
    char operation;

    cout << "Calculator" << endl;
    cin >> num1 >> operation >> num2;

    switch (operation) {
        case '+':
            cout << num1 + num2 << endl;
            break;
        
        case '-':
            cout << num1 - num2 << endl;
            break;
        
        case '*':
            cout << num1 * num2 << endl;
            break;
        
        case '/':
            cout << num1 / num2 << endl;
            break;
        
        case '%':
            {
            bool isInt1 = num1 == (int)num1; // num1 % 1 == 0 would also work
            bool isInt2 = num2 == (int)num2;

            if (isInt1 && isInt2) {
                cout << (int)num1 % (int)num2 << endl;
            }
            else {
                cout << "Invalid input" << &*num1 << endl;
            }
            break;
            }
        
        default:
            cout << "Invalid input" << endl;
            break;
    }

    system("pause");

}