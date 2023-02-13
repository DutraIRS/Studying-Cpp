#include <iostream>
#include <string>
using namespace std;

class Employee {
public:
    string Name;
    string Company;
    int Age;
    // private by default

};

int main() {

    Employee employee1;
    employee1.Name = "John";
    employee1.Company = "Google";
    employee1.Age = 25;

    system("pause");
    return 0;
}