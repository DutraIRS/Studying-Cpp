#include <iostream>

using namespace std;;

struct Node
{
    int iData;
    struct Node* ptrNextNode;
};

struct Node* ptrTopNode = nullptr;

void display();
void push(int);
void pop();

int main()
{
    display();

    cout << "===========" << endl;

    push(7);
    push(42);
    push(666);
    display();

    cout << "===========" << endl;

    pop();
    pop();
    display();

    return 0;
}

void display()
{
    struct Node* ptrNode = nullptr;

    if (ptrTopNode == nullptr) cout << "Empty stack" << endl;
    else
    {
        ptrNode = ptrTopNode;
        cout << "Stack elements: {";

        while (ptrNode->ptrNextNode != nullptr)
        {
            cout << ptrNode->iData << ", ";
            ptrNode = ptrNode->ptrNextNode;
        }

        cout << ptrNode->iData << "}" << endl;
    }
}

void push(int iVal)
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->iData = iVal;
    newNode->ptrNextNode = ptrTopNode;
    ptrTopNode = newNode;
}

void pop()
{
    if (ptrTopNode == nullptr) cout << "Stack underflow" << endl;
    else
    {
        cout << "Removed element: " << ptrTopNode->iData << endl;
        struct Node* tempPtr = ptrTopNode;
        ptrTopNode = ptrTopNode->ptrNextNode;

        free(tempPtr);
    }
}