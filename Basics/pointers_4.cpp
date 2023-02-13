#include <iostream>

void swap(std::string &x, std::string &y);

int main(){
    std::string x = "Tea";
    std::string y = "Coffee";
    std::string temp;

    swap(x, y);

    std::cout << "x: " << " " << x << std::endl;
    std::cout << "y: " << " " << y << std::endl;

    std::string name = "John";
    std::string *pName = &name;
    std::cout << "name: " << *pName << std::endl;

    std::string flavours[3] = {"Chocolate", "Vanilla", "Strawberry"};
    std::string *pFlavours = flavours; // pointer to the first element of the array
    std::cout << "flavours: " << *pFlavours << std::endl;
    std::cout << "flavours: " << flavours << std::endl;
    std::cout << "flavours: " << *flavours << std::endl;
    std::cout << "flavours: " << *(flavours+1) << std::endl;


    int *pointer = nullptr;
    int w = 5;
    pointer = &w;
    if (pointer == nullptr){
        std::cout << "Address unassigned"<< std::endl;
    }
    else{
        std::cout << "Address assigned, value is " << *pointer << std::endl;
    }

    return 0;
}

void swap(std::string &x, std::string &y){
    std::string temp;

    temp = x;
    x = y;
    y = temp;
}