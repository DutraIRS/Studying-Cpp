#include <iostream>

namespace FGV
{
    int iValue = 100;

    void mockFunction()
    {
        std::cout << "Hello from FGV namespace!\n" << std::endl;
    }

    namespace EMAp
    {
        int iValue = 1000;

        void mockFunction()
        {
            std::cout << "Hello from EMAp namespace!\n" << std::endl;
        }
    }
}

int iValue = 10;

using namespace FGV::EMAp;
using namespace std;

int main()
{
    int iValue = 1;

    mockFunction();
    FGV::EMAp::mockFunction();
    FGV::mockFunction();

    cout << "EMAp: " << FGV::EMAp::iValue << endl;
    cout << "FGV: " << FGV::iValue << endl;
    cout << "Global: " << ::iValue << endl;
    cout << "Local: " << iValue << endl;

    return 0;
}