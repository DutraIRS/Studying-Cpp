#include <iostream>

int main(){

    //std::string today = "Monday";
    //switch (today) key must be an integer or a character
    //{
    //case "Monday":
    //   std::cout << "Today is Monday" << std::endl;
    //    break;

    enum Day {Monday = 0, Tuesday = 1, Wednesday = 2, Thursday = 3, Friday = 4, Saturday = 5, Sunday = 6};
    // it is not necessary to assign values to the enum, the default is 0, 1, 2...
    Day today = Monday;
    
    switch (today)
    {
    case Monday: // could also use case 0:
        std::cout << "Today is Monday" << std::endl;
        break;
    }
    
    return 0;

}