#include <iostream>

struct Student{
    std::string name;
    double gpa;
    bool enrolled = true;
};

int main(){
    Student student1;
    student1.name = "John";
    student1.gpa = 3.5;
    student1.enrolled = true;

    std::cout << student1.name << std::endl;
    std::cout << student1.gpa << std::endl;
    std::cout << student1.enrolled << std::endl;

    return 0;
}