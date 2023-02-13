#include <iostream>
#include <string>
#include <list>

using namespace std;

class Warrior{
public:
    string name;
    string epithet;
    list <string> weapons;

    Warrior(string name = "", string epithet = "", list <string> weapons = {}){
        this->name = name;
        this->epithet = epithet;
        this->weapons = weapons;
    }
};

int main(){
    Warrior w1;
    w1.name = "Conan";
    w1.epithet = "the Barbarian";
    w1.weapons = {"sword", "axe", "bow", "spear"};
    w1.weapons.push_back("dagger");

    cout << w1.name << " " << w1.epithet << endl;

    cout << "Weapons: " << endl;

    for (string weapon : w1.weapons){
        cout << "\t" << weapon << endl;
    }
    
    system("pause");
}