#include <iostream>

using namespace std;

struct Node
{
    int data;
    struct Node* next;
};

void printList(struct Node*);
void addNode(struct Node*, int);

int main()
{
    struct Node* head = nullptr;
    struct Node* second = nullptr;
    struct Node* third = nullptr;

    head = (struct Node*)malloc(sizeof(struct Node));
    second = (struct Node*)malloc(sizeof(struct Node));
    third = (struct Node*)malloc(sizeof(struct Node));

    head->data = 1;
    head->next = second;

    second->data = 42;
    second->next = third;

    third->data = 666;
    third->next = nullptr;
    
    cout << "head: " << head << endl;
    cout << "head->data: " << head->data << endl;
    cout << "head->next: " << head->next << endl;
    cout << "&head: " << &head << endl;
    printList(head);
    cout << "head: " << head << endl;
    cout << "head->data: " << head->data << endl;
    cout << "head->next: " << head->next << endl;
    cout << "&head: " << &head << endl;

    cout << "\n==================\n" << endl;

    addNode(head, 777);
    printList(head);

    free(third); // let's create a habit of freeing memory
    free(second);
    free(head);

    return 0;
}

void printList(struct Node* sNode)
{
    while (sNode != nullptr)
    {
        cout << "Node's data: " << sNode->data << endl;
        sNode = sNode->next;
    }
}

void addNode(struct Node* sNode, int iData)
{
    struct Node* newNode = nullptr;
    newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = iData;
    newNode->next = nullptr;

    while (sNode->next != nullptr)
    {
        sNode = sNode->next;
    }
    sNode->next = newNode;
}