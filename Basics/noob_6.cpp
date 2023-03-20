#include <iostream>
#include <cmath> // including libraries in c++ only includes the prototypes of the functions, the actual code is in the lib file

using std::cout;
using std::cin;
using std::endl;
using std::string;

float sum(float, float); // function prototype (signature)

int sum(int a, int b)
{
    return a + b;
}

/*float sum(int a, int b)
{
    return a + b;
}*/ //ambiguous function declaration, the signature is the same (sum(int, int)) 

int sum(int a, int b, int c)
{
    return a + b + c;
}

int main()
{
    int a, b, c;
    a = 1;
    b = 2;
    c = 3;

    cout << sum(1, 2) << endl;
    cout << sum(1, 2, 3) << endl;
    // function polymorphism (static polymorphism, the compiler decides which function to call)
    // dynamic polymorphism (the runtime decides which function to call based on the type of the object)

    return 0;
}

float sum(float a, float b)
{
    return a + b;
}