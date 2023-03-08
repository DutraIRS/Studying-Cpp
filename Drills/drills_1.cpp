#include <iostream>
#include <complex>
#include <string>
#include <cmath>

void problemOne();
void problemTwo();
void problemThree();

int main() {
    problemOne();
    problemTwo();
    problemThree();

    return 0;
}

void problemOne() {
    /* 
    You receive a game's start time and end time (int). Find it's duration given that
    it can start in a day and end in the next, but never lasts more than 24 hours.
    */
    int iStartTime;
    int iEndTime;

    std::cout << "Enter the start time and the end time with a space or enter between each:\n";
    std::cin >> iStartTime >> iEndTime;

    if (iStartTime <= iEndTime) {
        std::cout << "The time difference is " << iEndTime - iStartTime << " hours." << std::endl;
    } else {
        std::cout << "The time difference is " << (iEndTime + 24) - iStartTime << " hours." << std::endl;
    }
}

void problemTwo() {
    /*
    You receive 3 floats (A, B and C) and must find the real roots of the equation
    Ax² + Bx + C = 0. If the equation has no real roots, print "Impossible".
    */
    float fA, fB, fC;

    std::cout << "Enter the values of A, B and C with a space or enter between each:\n";
    std::cin >> fA >> fB >> fC;

    float fDelta = (fB * fB) - (4. * fA * fC);

    if (fDelta < 0 || fA == 0) {
        std::cout << "Impossible" << std::endl;
    } else if (fDelta == 0) {
        std::cout << "The equation has one real root: " << (-fB) / (2. * fA) << std::endl;
    } else {
        std::cout << "The equation has two real roots: " << ((-fB) + sqrt(fDelta)) / (2. * fA) << " and " << ((-fB) - sqrt(fDelta)) / (2. * fA) << std::endl;
    }
}

void problemThree() {
    /*
    Now implement the same calculation as problem two, but allowing complex numbers.
    */
    std::complex<double> cA, cB, cC;
    std::complex<double> cRootOne, cRootTwo;
    std::string sRootOne, sRootTwo;

    std::cout << "Enter the values of A, B and C with a space or enter between each:\n";
    std::cin >> cA >> cB >> cC;

    if (cA.real() == 0) {
        std::cout << "Impossible" << std::endl;
        return;
    }
    
    cRootOne = (-cB + sqrt((cB * cB) - (4. * cA * cC))) / (2. * cA);
    cRootTwo = (-cB - sqrt((cB * cB) - (4. * cA * cC))) / (2. * cA);

    // This isn't necessary, but makes the output look nicer.
    if (cRootOne.imag() >= 0 && cRootTwo.imag() >= 0) {
        sRootOne = std::to_string(cRootOne.real()) + " + " + std::to_string(cRootOne.imag()) + "i";
        sRootTwo = std::to_string(cRootTwo.real()) + " + " + std::to_string(cRootTwo.imag()) + "i";
    }
    else if (cRootOne.imag() >= 0 && cRootTwo.imag() <= 0) {
        sRootOne = std::to_string(cRootOne.real()) + " + " + std::to_string(cRootOne.imag()) + "i";
        sRootTwo = std::to_string(cRootTwo.real()) + " - " + std::to_string(-cRootTwo.imag()) + "i";
    }
    else if (cRootOne.imag() <= 0 && cRootTwo.imag() >= 0) {
        sRootOne = std::to_string(cRootOne.real()) + " - " + std::to_string(-cRootOne.imag()) + "i";
        sRootTwo = std::to_string(cRootTwo.real()) + " + " + std::to_string(cRootTwo.imag()) + "i";
    }
    else {
        sRootOne = std::to_string(cRootOne.real()) + " - " + std::to_string(-cRootOne.imag()) + "i";
        sRootTwo = std::to_string(cRootTwo.real()) + " - " + std::to_string(-cRootTwo.imag()) + "i";
    }

    std::cout << "The roots are " << sRootOne << " and " << sRootTwo << std::endl;
}