#include <iostream>
#include <cmath>

/*
1) Make a function equivalent to python's sum(.) for a linked list. From a list's
head, it should return the element's sum.

2) Using the previous structure, make a function that, given 2 linked lists,
creates a new one (you may not alter the already existing ones) consisting of
the concatenation.

3) Given a linked list, implement a bubble sort function that modifies the passed list.

4) Our linked list receive only integers, but this isn't always what we desire.
Now, implement a linked list of linked lists of integers. In order to do that,
make a Node2 struct that receives a pointer to a linked list instead of a integer.
Then, implement the equivalent print and insert functions.
*/


struct Node
{
    int iData;
    Node* ptrNext;
};

void insert(struct Node* head, int iData)
{
    struct Node* ptrNew = (struct Node*)malloc(sizeof(struct Node));
    ptrNew->iData = iData;
    ptrNew->ptrNext = nullptr;

    if (head == nullptr)
    {
        head = ptrNew;
    }
    else
    {
        struct Node* ptrCurrent = head;
        while (ptrCurrent->ptrNext != nullptr)
        {
            ptrCurrent = ptrCurrent->ptrNext;
        }
        ptrCurrent->ptrNext = ptrNew;
    }
}

void printList(struct Node* head)
{
    struct Node* ptrCurrent = head;
    while (ptrCurrent != nullptr)
    {
        std::cout << ptrCurrent->iData << " ";
        ptrCurrent = ptrCurrent->ptrNext;
    }
    std::cout << std::endl;
}

int sum(struct Node* head)
{
    struct Node* ptrCurrent = head;
    int iSum = 0;

    while (ptrCurrent != nullptr)
    {
        iSum = iSum + ptrCurrent->iData;
        ptrCurrent = ptrCurrent->ptrNext;
    }

    return iSum;
}

struct Node* copyList(struct Node* head)
{
    struct Node* newList = (struct Node*)malloc(sizeof(struct Node));
    newList->iData = head->iData;
    newList->ptrNext = nullptr;
    
    struct Node* ptrTemp = head->ptrNext;

    while (ptrTemp != nullptr)
    {
        insert(newList, ptrTemp->iData);

        ptrTemp = ptrTemp->ptrNext;
    }

    return newList;
}

struct Node* concat(struct Node* head1, struct Node* head2)
{
    struct Node* newList = copyList(head1);
    struct Node* ptrCurrent = newList;

    while (ptrCurrent->ptrNext != nullptr)
    {
        ptrCurrent = ptrCurrent->ptrNext;
    }

    ptrCurrent->ptrNext = head2;
    
    return newList;
}

void swapNodes(struct Node** head, struct Node* nodeA, struct Node* nodeB)
{
    // Assumes nodeA comes before nodeB
    if (nodeA == *head)
    {
        if (nodeA->ptrNext == nodeB)
        {
            nodeA->ptrNext = nodeB->ptrNext;
            nodeB->ptrNext = nodeA;
            (*head) = nodeB;
        }
        else
        {
            struct Node* ptrTempBPrev = (*head);

            while (ptrTempBPrev->ptrNext != nodeB)
            {
                ptrTempBPrev = ptrTempBPrev->ptrNext;
            }

            struct Node* ptrTempBNext = nodeB->ptrNext;

            nodeB->ptrNext = (*head)->ptrNext;
            ptrTempBPrev->ptrNext = nodeA;
            (*head) = nodeB;
            nodeA->ptrNext = ptrTempBNext;
        }
    }
    else
    {
        if (nodeA->ptrNext == nodeB)
        {
            struct Node* ptrTempAPrev = (*head);

            while (ptrTempAPrev->ptrNext != nodeA)
            {
                ptrTempAPrev = ptrTempAPrev->ptrNext;
            }

            nodeA->ptrNext = nodeB->ptrNext;
            nodeB->ptrNext = nodeA;
            ptrTempAPrev->ptrNext = nodeB;
        }
        else
        {
            struct Node* ptrTempA = (*head);

            while (ptrTempA->ptrNext != nodeA)
            {
                ptrTempA = ptrTempA->ptrNext;
            }

            struct Node* ptrTempB = (*head);

            while (ptrTempB->ptrNext != nodeB)
            {
                ptrTempB = ptrTempB->ptrNext;
            }

            ptrTempA->ptrNext = nodeB;
            ptrTempB->ptrNext = nodeA;

            struct Node* ptrTempBNext = nodeB->ptrNext;

            nodeB->ptrNext = nodeA->ptrNext;
            nodeA->ptrNext = ptrTempBNext;
        }
    }
}

int getListSize(struct Node* head)
{
    int iSize = 0;
    while (head != nullptr)
    {
        iSize++;
        head = head->ptrNext;
    }

    return iSize;
}

struct Node* getNodeByIndex(struct Node* head, int iIndex)
{
    if (iIndex == 0)
    {
        return head;
    }
    else
    {
        for (int i = 0; i < iIndex; i++)
        {
            head = head->ptrNext;
        }
        return head;
    }
}

void bubbleSort(struct Node** head)
{
    int iListSize = getListSize((*head));

    for (int iOuterLoop = 0; iOuterLoop < iListSize - 1; iOuterLoop++)
        for (int iInnerLoop = 0; iInnerLoop < iListSize - 1 - iOuterLoop; iInnerLoop++)
            {
                struct Node* nodeA = getNodeByIndex((*head), iInnerLoop);
                struct Node* nodeB = nodeA->ptrNext;

                if (nodeA->iData > nodeB->iData)
                    swapNodes(head, nodeA, nodeB);
            }
}

struct Node2
{
    struct Node* node;
    struct Node2* next;
};

void insert2(struct Node2* head, struct Node* newNode)
{
    struct Node2* newNode2 = (struct Node2*)malloc(sizeof(struct Node2));
    newNode2->node = newNode;
    newNode2->next = nullptr;

    if (head == nullptr)
    {
        head = newNode2;
    }
    else
    {
        while (head->next != nullptr)
        {
            head = head->next;
        }

        head->next = newNode2;
    }
}

void printList2(struct Node2* head)
{
    if (head == nullptr)
    {
        std::cout << "Empty matrix!" << std::endl;
    }
    else
    {
        while (head != nullptr)
        {
            printList(head->node);
            head = head->next;
        }
    }
}

int main()
{
    std::cout << "1) ===================" << std::endl;
    struct Node* head = (struct Node*)malloc(sizeof(struct Node));
    head->iData = 0;
    head->ptrNext = nullptr;

    for (int i = 1; i < 10; i++)
    {
        insert(head, i);
        std::cout << "Sum: " << sum(head) << "\t List: ";
        printList(head);
    }

    std::cout << "\n\n2) ===================" << std::endl;
    struct Node* head1 = (struct Node*)malloc(sizeof(struct Node));
    head1->iData = 1;
    head1->ptrNext = nullptr;
    for (int i = 1; i < 10; i++)
    {
        insert(head1, 2 * i);
    }

    struct Node* head2 = (struct Node*)malloc(sizeof(struct Node));
    head2->iData = 1;
    head2->ptrNext = nullptr;
    for (int i = 1; i < 10; i++)
    {
        insert(head2, 5 * i);
    }

    std::cout << "Lists before: " << std::endl;
    std::cout << "A: ";
    printList(head1);

    std::cout << "B: ";
    printList(head2);

    struct Node* newHead = concat(head1, head2);
    
    std::cout << "\nLists after: " << std::endl;
    std::cout << "A: ";
    printList(head1);

    std::cout << "B: ";
    printList(head2);
    
    std::cout << "\nConcatenation: ";
    printList(newHead);

    std::cout << "\n\n3) ===================" << std::endl;
    std::cout << "Testing swapNodes" << std::endl;
    printList(newHead);
    swapNodes(&newHead, newHead, newHead->ptrNext);
    printList(newHead);

    swapNodes(&newHead, newHead, newHead->ptrNext->ptrNext);
    printList(newHead);

    swapNodes(&newHead, newHead->ptrNext, newHead->ptrNext->ptrNext);
    printList(newHead);

    swapNodes(&newHead, newHead->ptrNext, newHead->ptrNext->ptrNext->ptrNext);
    printList(newHead);

    std::cout << "\nTesting getListSize" << std::endl;
    std::cout << getListSize(newHead) << std::endl;
    insert(newHead, 0);
    std::cout << getListSize(newHead) << std::endl;

    std::cout << "\nTesting getNodeByIndex" << std::endl;
    printList(newHead);
    std::cout << "Index: " << 0 << "\t Data: " << getNodeByIndex(newHead, 0)->iData << std::endl;
    std::cout << "Index: " << 2 << "\t Data: " << getNodeByIndex(newHead, 2)->iData << std::endl;
    std::cout << "Index: " << 20 << "\t Data: " << getNodeByIndex(newHead, 20)->iData << std::endl;

    std::cout << "\nTesting bubbleSort" << std::endl;
    printList(newHead);
    bubbleSort(&newHead);
    printList(newHead);

    struct Node* head3 = (struct Node*)malloc(sizeof(struct Node));
    head3->iData = 1;
    head3->ptrNext = nullptr;

    for (int i = 1; i < 10; i++)
    {
        insert(head3, pow(-1, i) * i);
    }
    std::cout << std::endl;
    printList(head3);
    bubbleSort(&head3);
    printList(head3);

    std::cout << "\n\n4) ===================" << std::endl;
    printList(head);
    printList(head1);

    struct Node2* matrix = (struct Node2*)malloc(sizeof(struct Node2));
    matrix->node = head;
    matrix->next = nullptr;

    printList2(matrix);
    insert2(matrix, head1);
    printList2(matrix);

    return 0;
}