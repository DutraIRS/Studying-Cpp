#include <iostream>

using namespace std;

struct Node
{
    int iData;
    struct Node* ptrNextNode;
    struct Node* ptrPrevNode;
};

void displayList(struct Node* ptrHeadNode)
{
    if (ptrHeadNode == nullptr)
    {
        cout << "Empty list!" << endl;
        return;
    }

    if (ptrHeadNode->ptrPrevNode != nullptr)
    {
        cout << "Middle of the list!" << endl;
        return;
    }

    cout << "List elements: {";
    while (ptrHeadNode->ptrNextNode != nullptr)
    {
        cout << ptrHeadNode->iData << ", ";
        ptrHeadNode = ptrHeadNode->ptrNextNode;
    }
    cout << ptrHeadNode->iData << "}" << endl;
}

struct Node* createNode(int iPayload)
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->iData = iPayload;
    newNode->ptrNextNode = nullptr;
    newNode->ptrPrevNode = nullptr;

    return newNode;
}

void insertFront(struct Node** head, int iPayload)
{
    struct Node* newNode = createNode(iPayload);
    newNode->ptrNextNode = *head;
    newNode->ptrPrevNode = nullptr;

    if (*head != nullptr) (*head)->ptrPrevNode = newNode;

    *head = newNode;
}

void insertEnd(struct Node** head, int iPayload)
{
    struct Node* newNode = createNode(iPayload);
    newNode->ptrNextNode = nullptr;

    if (*head == nullptr) 
    {
        newNode->ptrPrevNode = nullptr;
        *head = newNode;
    }
    else
    {
        struct Node* lastNode = *head;
        while (lastNode->ptrNextNode != nullptr) lastNode = lastNode->ptrNextNode;

        lastNode->ptrNextNode = newNode;
        newNode->ptrPrevNode = lastNode;
    }
}

void deleteFront(struct Node** head)
{
    if (*head == nullptr) cout << "Empty list!" << endl;

    struct Node* ptrTemp = *head;
    *head = (*head)->ptrNextNode;

    if (*head != nullptr) (*head)->ptrPrevNode = nullptr;

    free(ptrTemp);
}

void deleteEnd(struct Node** head)
{
    if (*head == nullptr)
    {
        cout << "Empty list!" << endl;
        return;
    }

    struct Node* ptrTemp = *head;
    while (ptrTemp->ptrNextNode != nullptr) ptrTemp = ptrTemp->ptrNextNode;

    if (ptrTemp->ptrPrevNode != nullptr) ptrTemp->ptrPrevNode->ptrNextNode = nullptr;
    else *head = nullptr;

    free(ptrTemp);
}

void insertAfter(struct Node* ptrLocation, int iPayload)
{
    if (ptrLocation == nullptr)
    {
        cout << "Impossible insertion" << endl;
        return;
    }

    struct Node* newNode = createNode(iPayload);
    newNode->ptrNextNode = ptrLocation->ptrNextNode;
    newNode->ptrPrevNode = ptrLocation;

    ptrLocation->ptrNextNode = newNode;
    if (newNode->ptrNextNode != nullptr) newNode->ptrNextNode->ptrPrevNode = newNode;
}

void deleteNode(struct Node** head, struct Node* ptrDelete)
{
    if (*head == nullptr || ptrDelete == nullptr)
    {
        cout << "Impossible deletion" << endl;
        return;
    }

    if (*head == ptrDelete)
    {
        *head = ptrDelete->ptrNextNode;
    }

    if (ptrDelete->ptrNextNode != nullptr)
    {
        ptrDelete->ptrNextNode->ptrPrevNode = ptrDelete->ptrPrevNode;
    }

    if (ptrDelete->ptrPrevNode != nullptr)
    {
        ptrDelete->ptrPrevNode->ptrNextNode = ptrDelete->ptrNextNode;
    }

    free(ptrDelete);
}

int main()
{
    cout << "===========" << endl;

    struct Node* ptrHeadNode = nullptr;

    displayList(ptrHeadNode);

    cout << "===========" << endl;

    insertFront(&ptrHeadNode, 0);
    displayList(ptrHeadNode);

    insertFront(&ptrHeadNode, 1);
    displayList(ptrHeadNode);

    insertFront(&ptrHeadNode, 7);
    displayList(ptrHeadNode);

    cout << "===========" << endl;

    insertEnd(&ptrHeadNode, 42);
    displayList(ptrHeadNode);

    insertEnd(&ptrHeadNode, 666);
    displayList(ptrHeadNode);

    cout << "===========" << endl;

    deleteFront(&ptrHeadNode);
    displayList(ptrHeadNode);

    deleteFront(&ptrHeadNode);
    displayList(ptrHeadNode);

    cout << "===========" << endl;

    deleteEnd(&ptrHeadNode);
    displayList(ptrHeadNode);

    deleteEnd(&ptrHeadNode);
    displayList(ptrHeadNode);

    cout << "===========" << endl;

    insertAfter(ptrHeadNode, 1);
    insertAfter(ptrHeadNode, 3);
    insertAfter(ptrHeadNode->ptrNextNode, 2);
    insertAfter(ptrHeadNode->ptrNextNode->ptrNextNode->ptrNextNode, 4);
    insertAfter(ptrHeadNode->ptrNextNode->ptrNextNode->ptrNextNode->ptrNextNode->ptrNextNode, 4);
    displayList(ptrHeadNode);

    cout << "===========" << endl;

    deleteNode(&ptrHeadNode, ptrHeadNode);
    displayList(ptrHeadNode);
    deleteNode(&ptrHeadNode, ptrHeadNode->ptrNextNode);
    displayList(ptrHeadNode);
    deleteNode(&ptrHeadNode, ptrHeadNode->ptrPrevNode);
    deleteNode(&ptrHeadNode, ptrHeadNode->ptrNextNode->ptrNextNode);
    displayList(ptrHeadNode);
    deleteNode(&ptrHeadNode, ptrHeadNode->ptrNextNode->ptrNextNode);
    displayList(ptrHeadNode);

    insertAfter(ptrHeadNode, 2);
    displayList(ptrHeadNode);
    deleteNode(&ptrHeadNode, ptrHeadNode->ptrNextNode);
    displayList(ptrHeadNode);

    cout << "===========" << endl;

    return 0;
}