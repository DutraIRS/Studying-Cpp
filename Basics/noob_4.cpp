#include <iostream>
using namespace std;

void func();

float sum(float a, float b){
    return a + b;
}

int sum (int a, int b){
    return a + b;
}
// just like Julia's multiple dispatch

template<typename T> // T is a generic type
void swap(T &a, T &b){ // &a pass a to the function by reference
// the standard behaviour is to pass just the value of the variable
// which does not let you assign a new value to the variable
    T temp = a;
    a = b;
    b = temp;
}

int main(){

    func();
    
    int year, month;
    cout << "Enter year and month: ";
    cin >> year >> month;

    switch (month) {
        case 2:
            (year % 4 == 0 && year % 100 != 0 || year % 400 == 0) ?
            cout << "29 days" << endl : cout << "28 days" << endl;
            break;

        case 4: // if month == 4, will execute all code until next break
        case 6:
        case 9:
        case 11:
            cout << "30 days" << endl;
            break;
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            cout << "31 days" << endl;
            break;
        default:
            cout << "Invalid input" << endl;
            break;
    }
    system("pause");
}

void func(){
    cout << "Hello World" << endl;
}