#include <iostream>

using namespace std;

/*
Problem 1: Given the chosen list structure, make a function that, given the head pointer
to the structure, and a string that can have the value "ascending" or "descending",
check if the list is ordered in the way indicated by the string, returning a boolean.

Problem 2: Different sort algorithms use different strategies, and we implemented in the
other lists the Bubble Sort and Merge Sort. Continuing the exploration of these algorithms,
implement for the structure chosen in the previous item two of the following algorithms,
passing as input to the sort function a pointer to the pointer of the list head:

(a) Selection Sort
(b) Insert Sort
(c) Shell Sort

Problem 3: Given a list in the chosen structure where the nodes represent a list of
integers in the same structure. Make a function to sort this list so that: first,
sort all the "internal" lists (which are stored in each node); second, sort the nodes
of the "external" list (which stores the internal lists).
*/

struct Node
{
    int data;
    Node* next;
    Node* prev;
};

struct MetaNode
{
    Node* node;
    MetaNode* next;
    MetaNode* prev;
};

bool isOrdered(Node* head, string order)
{
    Node* temp = head;
    while (temp->next != nullptr)
    {
        if (order == "ascending")
        {
            if (temp->data > temp->next->data)
            {
                return false;
            }
        }
        else if (order == "descending")
        {
            if (temp->data < temp->next->data)
            {
                return false;
            }
        }
        temp = temp->next;
    }

    return true;
}

void insert(Node* head, int data)
{
    Node* temp = head;
    while (temp->next != nullptr)
    {
        temp = temp->next;
    }

    Node* newNode = new Node;
    newNode->data = data;
    newNode->next = nullptr;
    newNode->prev = temp;
    temp->next = newNode;
}

void printList(Node* head)
{
    Node* temp = head;

    cout << "{";
    while (temp->next != nullptr)
    {
        cout << temp->data << ", ";
        temp = temp->next;
    }
    cout << temp->data << "}" << endl;
}

int getLength(Node* head)
{
    Node* temp = head;
    int length = 1;

    while (temp->next != nullptr)
    {
        temp = temp->next;
        length++;
    }

    return length;
}

Node* getNodeByIndex(Node* head, int index)
{
    Node* temp = head;
    
    for (int i = 0; i < index; i++)
    {
        temp = temp->next;
    }

    return temp;
}

void swapNodes(struct Node** head, struct Node* nodeA, struct Node* nodeB)
{
    // Assumes nodeA comes before nodeB
    if (nodeA == *head)
    {
        if (nodeA->next == nodeB)
        {
            nodeA->next = nodeB->next;
            if (nodeB->next != nullptr) nodeB->next->prev = nodeA;
            nodeA->prev = nodeB;
            nodeB->next = nodeA;
            nodeB->prev = nullptr;

            (*head) = nodeB;
        }
        else
        {
            struct Node* ptrTempBPrev = nodeB->prev;
            struct Node* ptrTempBNext = nodeB->next;

            nodeB->next = nodeA->next;
            nodeB->prev = nullptr;
            ptrTempBPrev->next = nodeA;
            if (ptrTempBNext != nullptr) ptrTempBNext->prev = nodeA;
            nodeA->next->prev = nodeB;
            nodeA->next = ptrTempBNext;
            nodeA->prev = ptrTempBPrev;

            (*head) = nodeB;
        }
    }
    else
    {
        if (nodeA->next == nodeB)
        {
            nodeA->next = nodeB->next;
            if (nodeB->next != nullptr) nodeB->next->prev = nodeA;
            nodeB->prev = nodeA->prev;
            nodeA->prev->next = nodeB;
            nodeB->next = nodeA;
            nodeA->prev = nodeB;
        }
        else
        {
            struct Node* ptrTempAPrev = nodeA->prev;
            struct Node* ptrTempBPrev = nodeB->prev;

            struct Node* ptrTempANext = nodeA->next;
            struct Node* ptrTempBNext = nodeB->next;

            nodeA->prev = nodeB->prev;
            nodeB->prev = ptrTempAPrev;

            ptrTempAPrev->next = nodeB;
            ptrTempBPrev->next = nodeA;

            nodeA->next = nodeB->next;
            nodeB->next = ptrTempANext;

            ptrTempANext->prev = nodeB;
            if (ptrTempBNext != nullptr) ptrTempBNext->prev = nodeA;
        }
    }
}

void selectionSort(Node** head)
{
    Node* temp = *head;
    int length = getLength(*head);
    
    for (int i = 0; i < length; i++)
    {
        temp = getNodeByIndex(*head, i);
        Node* min = temp;
        Node* r = temp;

        while (r != nullptr)
        {
            if (min->data > r->data)
            {
                min = r;
            }

            r = r->next;
        }

        if (min != temp)
        {
            swapNodes(head, temp, min);
        }
    }
}

void insertionSort(Node** head)
{
    Node* temp = *head;
    Node* temp2 = *head;
    int length = getLength(temp);

    for (int i = 1; i < length; i++)
    {
        for (int j = i; j > 0; j--)
        {
            temp = getNodeByIndex(*head, j);
            temp2 = getNodeByIndex(*head, j - 1);

            if (temp->data < temp2->data)
            {
                swapNodes(head, temp2, temp);
            }
        }
    }
}

void shellSort(Node** head)
{
    Node* temp = *head;
    int length = getLength(*head);
    int gap = 1;

    while (gap < length) gap = 3 * gap + 1;

    for (gap = (gap - 1) / 3; gap > 0; gap = (gap - 1) / 3)
    {
        for (int i = gap; i < length; i++)
        {
            for (int j = i; j >= gap; j -= gap)
            {
                temp = getNodeByIndex(*head, j);
                Node* temp2 = getNodeByIndex(*head, j - gap);

                if (temp->data < temp2->data)
                {
                    swapNodes(head, temp2, temp);
                }
            }
        }
    }
}

void bubbleSort(Node** head)
{
    Node* temp = *head;
    int length = getLength(*head);

    for (int i = 0; i < length; i++)
    {
        for (int j = 0; j < length - i - 1; j++)
        {
            temp = getNodeByIndex(*head, j);
            Node* temp2 = getNodeByIndex(*head, j + 1);

            if (temp->data > temp2->data)
            {
                swapNodes(head, temp, temp2);
            }
        }
    }
}

int getLength(MetaNode* metaHead)
{
    MetaNode* temp = metaHead;
    int length = 1;
    while (temp->next != nullptr)
    {
        temp = temp->next;
        length++;
    }

    return length;
}

MetaNode* getNodeByIndex(MetaNode* head, int index)
{
    MetaNode* temp = head;
    for (int i = 0; i < index; i++)
    {
        temp = temp->next;
    }

    return temp;
}

void swapNodes(struct MetaNode** head, struct MetaNode* nodeA, struct MetaNode* nodeB)
{
    // Assumes nodeA comes before nodeB
    if (nodeA == *head)
    {
        if (nodeA->next == nodeB)
        {
            nodeA->next = nodeB->next;
            if (nodeB->next != nullptr) nodeB->next->prev = nodeA;
            nodeA->prev = nodeB;
            nodeB->next = nodeA;
            nodeB->prev = nullptr;

            (*head) = nodeB;
        }
        else
        {
            struct MetaNode* ptrTempBPrev = nodeB->prev;
            struct MetaNode* ptrTempBNext = nodeB->next;

            nodeB->next = nodeA->next;
            nodeB->prev = nullptr;
            ptrTempBPrev->next = nodeA;
            if (ptrTempBNext != nullptr) ptrTempBNext->prev = nodeA;
            nodeA->next->prev = nodeB;
            nodeA->next = ptrTempBNext;
            nodeA->prev = ptrTempBPrev;

            (*head) = nodeB;
        }
    }
    else
    {
        if (nodeA->next == nodeB)
        {
            nodeA->next = nodeB->next;
            if (nodeB->next != nullptr) nodeB->next->prev = nodeA;
            nodeB->prev = nodeA->prev;
            nodeA->prev->next = nodeB;
            nodeB->next = nodeA;
            nodeA->prev = nodeB;
        }
        else
        {
            struct MetaNode* ptrTempAPrev = nodeA->prev;
            struct MetaNode* ptrTempBPrev = nodeB->prev;

            struct MetaNode* ptrTempANext = nodeA->next;
            struct MetaNode* ptrTempBNext = nodeB->next;

            nodeA->prev = nodeB->prev;
            nodeB->prev = ptrTempAPrev;

            ptrTempAPrev->next = nodeB;
            ptrTempBPrev->next = nodeA;

            nodeA->next = nodeB->next;
            nodeB->next = ptrTempANext;

            ptrTempANext->prev = nodeB;
            if (ptrTempBNext != nullptr) ptrTempBNext->prev = nodeA;
        }
    }
}

void selectionSort(MetaNode** head)
{
    MetaNode* temp = *head;
    int length = getLength(*head);
    
    for (int i = 0; i < length; i++)
    {
        temp = getNodeByIndex(*head, i);
        MetaNode* min = temp;
        MetaNode* r = temp;

        while (r != nullptr)
        {
            if (min->node->data > r->node->data)
            {
                min = r;
            }

            r = r->next;
        }

        if (min != temp)
        {
            swapNodes(head, temp, min);
        }
    }
}

void sortMetaNode(MetaNode** metaHead)
{
    MetaNode* temp = *metaHead;
    int length = getLength(temp);

    while (temp != nullptr)
    {
        selectionSort(&(temp->node));
        temp = temp->next;
    }

    for (int i = 1; i < length; i++)
    {
        for (int j = i; j > 0; j--)
        {
            temp = getNodeByIndex(*metaHead, j);
            MetaNode* temp2 = getNodeByIndex(*metaHead, j - 1);

            if (temp->node->data < temp2->node->data)
            {
                swapNodes(metaHead, temp2, temp);
            }
        }
    }
}

void printList(MetaNode* metaHead)
{
    cout << "{" << endl;
    while (metaHead != nullptr)
    {
        printList(metaHead->node);
        metaHead = metaHead->next;
    }
    cout << "}" << endl;
}

int main()
{
    Node* head = new Node;
    head->data = 4;
    head->next = nullptr;
    head->prev = nullptr;

    insert(head, 2);
    insert(head, 6);
    insert(head, 1);
    insert(head, 5);
    insert(head, 3);

    cout << "Initial List:" << endl;
    printList(head);

    bubbleSort(&head);

    cout << "\nBubble Sort:" << endl;

    printList(head);

    // cout << "Length: " << getLength(head) << endl;

    // swapNodes(&head, head, head->next->next);
    // printList(head);

    // cout << "Is ordered ascending: " << isOrdered(head, "ascending") << endl;

    // cout << "\nSelection Sort:" << endl;
    // selectionSort(&head);
    // printList(head);
    // cout << "Is ordered ascending: " << isOrdered(head, "ascending") << endl;

    // cout << "\nRandomizing list..." << endl;
    // swapNodes(&head, head, head->next);
    // swapNodes(&head, head, head->next->next->next->next);
    // swapNodes(&head, head->next, head->next->next->next);
    // swapNodes(&head, head->next, head->next->next);
    // printList(head);

    // cout << "\nInsertion Sort:" << endl;
    // insertionSort(&head);
    // printList(head);
    // cout << "Is ordered ascending: " << isOrdered(head, "ascending") << endl;

    // cout << "\nRandomizing list..." << endl;
    // swapNodes(&head, head, head->next);
    // swapNodes(&head, head, head->next->next->next->next);
    // swapNodes(&head, head->next, head->next->next->next);
    // swapNodes(&head, head->next, head->next->next);
    // printList(head);

    // cout << "\nShell Sort:" << endl;
    // shellSort(&head);
    // printList(head);
    // cout << "Is ordered ascending: " << isOrdered(head, "ascending") << endl;

    // cout << "\nRandomizing list..." << endl;
    // swapNodes(&head, head, head->next);
    // swapNodes(&head, head, head->next->next->next->next);
    // swapNodes(&head, head->next, head->next->next->next);
    // swapNodes(&head, head->next, head->next->next);
    // printList(head);

    // cout << "\nCreating more lists..." << endl;
    // Node* head2 = new Node;
    // head2->data = 7;
    // head2->next = nullptr;
    // head2->prev = nullptr;

    // insert(head2, 8);
    // insert(head2, 10);
    // insert(head2, 9);
    // insert(head2, 12);
    // insert(head2, 11);
    // printList(head2);

    // Node* head3 = new Node;
    // head3->data = 18;
    // head3->next = nullptr;
    // head3->prev = nullptr;

    // insert(head3, 13);
    // insert(head3, 17);
    // insert(head3, 14);
    // insert(head3, 15);
    // insert(head3, 16);
    // printList(head3);

    // cout << "\nCreating meta list..." << endl;
    // MetaNode* metaHead = new MetaNode;
    // metaHead->node = head;
    // metaHead->next = nullptr;
    // metaHead->prev = nullptr;

    // MetaNode* metaHead2 = new MetaNode;
    // metaHead2->node = head3;
    // metaHead2->next = nullptr;
    // metaHead2->prev = metaHead;
    // metaHead->next = metaHead2;

    // MetaNode* metaHead3 = new MetaNode;
    // metaHead3->node = head2;
    // metaHead3->next = nullptr;
    // metaHead3->prev = metaHead2;
    // metaHead2->next = metaHead3;

    // printList(metaHead);

    // cout << "\nSorting meta list..." << endl;
    // sortMetaNode(&metaHead);
    // printList(metaHead);

    return 0;
}