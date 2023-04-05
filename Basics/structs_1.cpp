#include <iostream>

using std::cout;
using std::cin;
using std::endl;
using std::string;

struct Student{
    string name;
    double gpa;
    bool enrolled = true;
};

struct Book
{
    string strTitle;
    string strAuthor;
    int iPublishDate;        
};

struct Dot
{
    unsigned short usRed;
    unsigned short usGreen;
    unsigned short usBlue;
};

struct Library
{
    string strName;
    int iCollectionSize;
    struct Book Books[1000];
};

void addBook(struct Library&, struct Book);
void listBooks(struct Library);

int main(){
    Student student1;
    student1.name = "John";
    student1.gpa = 3.5;
    student1.enrolled = true;

    cout << student1.name << endl;
    cout << student1.gpa << endl;
    cout << student1.enrolled << endl;

    struct // Anonymous struct
    {
        int iAge;
        string strName;
    }   studentEMAp;

    studentEMAp.iAge = 20;
    studentEMAp.strName = "Wilhelm";

    struct Book book1;
    book1.strTitle = "Outliers: The Story of Success";
    book1.strAuthor = "Malcolm Gladwell";
    book1.iPublishDate = 2006;
    
    struct Book book2;
    book2.strTitle = "How to Grow Old";
    book2.strAuthor = "Marcus Tullius Cicero";
    book2.iPublishDate = -41;

    cout << book1.strTitle << ", by " << book1.strAuthor << ". Published in " 
         << book1.iPublishDate << "." << endl;

    cout << book2.strTitle << ", by " << book2.strAuthor << ". Published in " 
         << book2.iPublishDate << "." << endl;

    struct Dot screen[640][480];
    screen[12][12].usRed = 0;
    screen[12][12].usGreen = 0;
    screen[12][12].usBlue = 0;

    screen[42][42] = {255, 182, 203};
    
    cout << "RGB(" << screen[12][12].usRed << ", " << screen[12][12].usGreen << ", " << screen[12][12].usBlue << ")" << endl;
    cout << "RGB(" << screen[42][42].usRed << ", " << screen[42][42].usGreen << ", " << screen[42][42].usBlue << ")" << endl;

    struct Library library;
    library.strName = "Uncle Rafa's Library";
    library.iCollectionSize = 0;

    library.Books[library.iCollectionSize] = book1;
    library.iCollectionSize++;
    library.Books[library.iCollectionSize] = book2;
    library.iCollectionSize++;
    
    cout << library.strName << endl;
    cout << library.iCollectionSize << endl;
    listBooks(library);

    struct Book book3;
    book3.strTitle = "Wuthering Heights";
    book3.strAuthor = "Emily Bronte";
    book3.iPublishDate = 1847;

    addBook(library, book3);
    listBooks(library);

    return 0;
}

void addBook(struct Library& library, struct Book book)
{
    library.Books[library.iCollectionSize] = book;
    library.iCollectionSize++;
}

void listBooks(struct Library library)
{
    cout << "Collection's Books: " << endl;
    for (int i = 0; i < library.iCollectionSize; i++)
    {
        cout << "\t" << library.Books[i].strTitle << ", by " << library.Books[i].strAuthor 
             << ". Published in " << library.Books[i].iPublishDate << endl;
    }
};
