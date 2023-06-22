#include <iostream>

using namespace std;

/**********************************************

Essential concepts of Trees:

Root
Child Node
Parent
Sibling
Leaf Node
AncestorNode

**********************************************/

struct Node
{
    int iPayload;
    struct Node* ptrLeft;
    struct Node* ptrRight;
};

struct Node* newNode(int iData)
{
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->iPayload = iData;
    newNode->ptrLeft = nullptr;
    newNode->ptrRight = nullptr;
    return newNode;
};

void traversePreOrder(struct Node* ptrStartingNode)
{
    if (ptrStartingNode != nullptr)
    {
        cout << " " << ptrStartingNode->iPayload;
        traversePreOrder(ptrStartingNode->ptrLeft);
        traversePreOrder(ptrStartingNode->ptrRight);
    }
}

void traverseInOrder(struct Node* ptrStartingNode)
{
    if (ptrStartingNode != nullptr)
    {
        traverseInOrder(ptrStartingNode->ptrLeft);
        cout << " " << ptrStartingNode->iPayload;
        traverseInOrder(ptrStartingNode->ptrRight);
    }
}

void traversePostOrder(struct Node* ptrStartingNode)
{
    if (ptrStartingNode != nullptr)
    {
        traversePostOrder(ptrStartingNode->ptrLeft);
        traversePostOrder(ptrStartingNode->ptrRight);
        cout << " " << ptrStartingNode->iPayload;
    }
}

struct Node* searchNode(struct Node* node, int iData)
{
    if(node == nullptr) return nullptr;
    else if(iData == node->iPayload) return node;
    else if(iData < node->iPayload) return searchNode(node->ptrLeft, iData);
    else return searchNode(node->ptrRight, iData);
    return nullptr;
};

int main()
{
    struct Node* root = newNode(1);
    root->ptrLeft = newNode(7);
    root->ptrRight = newNode(13);
    root->ptrRight->ptrLeft = newNode(42);
    root->ptrRight->ptrRight = newNode(666);

    cout << "Traversing Tree - PreOrder: ";
    traversePreOrder(root);
    cout << endl;

    cout << "Traversing Tree - InOrder: ";
    traverseInOrder(root);
    cout << endl;

    cout << "Traversing Tree - PostOrder: ";
    traversePostOrder(root);
    cout << endl;

    struct Node* root2 = newNode(42);
    root2->ptrLeft = newNode(7);
    root2->ptrRight = newNode(666);
    root2->ptrRight->ptrLeft = newNode(1);
    root2->ptrRight->ptrRight = newNode(13);

    string result;

    result = (nullptr == searchNode(nullptr, 42))? "Found": "Not found";
    cout << "Searching nullptr: " << result << endl;

    result = (root2 == searchNode(root2, 42))? "Found": "Not found";
    cout << "Searching 42: " << result << endl;

    result = (root2->ptrLeft == searchNode(root2, 7))? "Found": "Not found";
    cout << "Searching 7: " << result << endl;

    result = (root2->ptrLeft->ptrLeft == searchNode(root2, 1))? "Found": "Not found";
    cout << "Searching 1: " << result << endl;

    result = (nullptr != searchNode(root2, 10))? "Found": "Not found";
    cout << "Searching non-existent: " << result << endl;

    return 0;
}
