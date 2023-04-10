#include <iostream>
#include "book.h"

using std::cout;
using std::endl;

typedef int i;

int main()
{
    i iValue = 42;

    struct Book book1;
    Book book2; // doesn't work in C unless you use typedef

    cout << "Size of Book: " << sizeof(struct Book) << endl;
    cout << "Size of Book 1: " << sizeof(book1) << endl;
    cout << "Size of Book 2: " << sizeof(book2) << endl;
    cout << "Size of Book 2's title: " << sizeof(book2.strTitle) << endl;
    cout << "Size of Book 2's author: " << sizeof(book2.strAuthor) << endl;

    //organizedFunction(iValue); // vscode asks for a different project folder structure

    return 0;
}