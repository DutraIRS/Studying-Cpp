#include <iostream>
#include <string>
#include <list>

using namespace std;

class Sage {
private:
    string Name;
    string Nationality;
    int BirthYear;
    list <string> Books;

public:
    Sage(string Name, string Nationality, int BirthYear, list <string> Books){
        this->Name = Name;
        this->Nationality = Nationality;
        this->BirthYear = BirthYear;
        this->Books = Books;
    }
    
    void getInfo(){
        cout << "Name: " << Name << endl;
        cout << "Nationality: " << Nationality << endl;
        cout << "Birth Year: " << BirthYear << endl;
    }

    void getBooks(){
        cout << "Books: " << endl;
        for (string book : this->Books){
            cout << "\t" << book << endl;
        }
    }

    void addBook(string book){
        this->Books.push_back(book);
    }

    string getName(){
        return this->Name;
    }
};

class Philosopher : public Sage {
    // the public keyword mantains the public methods of the parent class public
public:
    bool likesPlato;

    Philosopher(string Name, string Nationality, int BirthYear, list <string> Books, bool likesPlato) : Sage(Name, Nationality, BirthYear, Books) {
        // : Sage(Name, Nationality, BirthYear, Books) is the constructor of the parent class
        this->likesPlato = likesPlato;
    };

    void isFondOfPlato(){
        if (this->likesPlato) {
        cout << this->getName() << " likes Plato" << endl;
        }
        else {
        cout << this->getName() << " doesn't like Plato" << endl;
        }
    }
};

class Poet : public Sage {
public:
    int likesPlato;

    Poet(string Name, string Nationality, int BirthYear, list <string> Books, int likesPlato = 0) : Sage(Name, Nationality, BirthYear, Books) {
        this->likesPlato = likesPlato;
    };

    void isFondOfPlato(){
        cout << this->getName() << " rates Plato as " << this->likesPlato << "/10." << endl;
    }
};

int main() {
    Sage Hegel(
        "Georg Wilhelm Friedrich Hegel",
        "German",
        1770,
        {"Phenomenology of Spirit", "Science of Logic", "Encyclopaedia of the Philosophical Sciences"}
        );

    Hegel.getInfo();

    Hegel.addBook("Elements of the Philosophy of Right");

    Hegel.getBooks();

    cout << endl;

    Philosopher Nietzsche(
        "Friedrich Nietzsche",
        "German",
        1844,
        {"Thus Spoke Zarathustra", "Beyond Good and Evil"},
        false
        );

    Nietzsche.getInfo();

    Nietzsche.addBook("The Antichrist");

    Nietzsche.getBooks();

    Nietzsche.isFondOfPlato();

    system("pause");
    system("cls");

    Poet PercyShelley(
        "Percy Bysshe Shelley",
        "English",
        1792,
        {"Ozymandias", "Prometheus Unchained"},
        8
    );
    
    PercyShelley.getInfo();

    PercyShelley.addBook("Queen Mab");

    PercyShelley.getBooks();

    PercyShelley.isFondOfPlato();

    cout << endl;

    Poet Byron(
        "George Gordon Byron",
        "English",
        1788,
        {"Don Juan", "Childe Harold's Pilgrimage"}
    );

    Byron.getInfo();

    Byron.addBook("The Corsair");

    Byron.getBooks();

    Byron.isFondOfPlato();

    system("pause");
}