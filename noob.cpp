#include <iostream>
#include <string>

// <return type> <function name> (<parameters>) { <body> }
// void means that the function does not return anything
void PrintTest()
{
    std::cout << "Hello World" << std::endl;
}

void PrintTest2(int x)
{
    std::cout << "Hello World" << x << std::endl;
}

class Humano {
public:
    Human() {
        age = 0;
        name = "John";
        surname = "Doe";
    }

    Human(std::string n) {
        age = 0;
        name = n;
        surname = "Doe";
    }

    Human(std::string n, int age = 0) {
        age = age;
        name = n;
        surname = "Doe";
    }

private:
    void ShowID() {
        std::cout << "ID: " << age << std::endl;
    }

    int age;
    std::string name;
    std::string surname;
};

struct Human {
    Human() {
        age = 0;
        name = "John";
        surname = "Doe";
    }

    Human(std::string n) {
        age = 0;
        name = n;
        surname = "Doe";
    }

    Human(std::string n, int age = 0) {
        age = age;
        name = n;
        surname = "Doe";
    }

    void ShowID() {
        std::cout << "ID: " << age << std::endl;
    }

    int age;
    std::string name;
    std::string surname;
};

int main()
{   
    Human myHuman;
    myHuman.age = 23;
    myHuman.name = "John";
    PrintTest();
    PrintTest2(23);
    PrintTest();
    int myInt = 0;
    unsigned int myUInt = 0;
    float myFloat = 0.0f;
    double myDouble = 0.0;
    bool myBool = false;
    char myChar = 'a';
    char myArray[11] = "0123456789";
    // comment
    // array has 11 elements because the last is always '\0'
    size_t mySize_t = 0;
    std::string myString = "Hello World";

    std::cout << "choose a number";
    std::cin >> myInt;

    if (myInt > 0)
    {
        std::cout << "myInt is positive" << std::endl;
    }
    else if (myInt == 0)
    {
        std::cout << "myInt is 0" << std::endl;
    }
    else
    {
        std::cout << "myInt is negative" << std::endl;
    }

    while (myInt < 100)
    {
        std::cout << "myInt is less than  100" << std::endl;
        myInt += 1;
    }

    int myArray2[10];

    for (int i = 0; i < 10; i++)
    {
        std::cout << "i = " << i << std::endl;
        myArray2[i] = i;
        std::cout << myArray2[i] << std::endl;
    }
    
    std::cout << "Hello World" << 100/27  << std::endl;
    system("pause");
    return 0;
}