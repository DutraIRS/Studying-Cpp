#include <iostream>
#include <chrono>

using namespace std;
using namespace std::chrono;

void printArray(int arriData[], int iArraySize)
{
    cout << "{";
    for (int i = 0; i < iArraySize - 1; i++)
    {
        cout << arriData[i] << ", ";
    }
    cout << arriData[iArraySize - 1] << "}" << endl;
}

// void selectSort(int arriData[], int iArraySize)
// {
//     int iTemp;

//     for (int iOuterLoop = 0; iOuterLoop < iArraySize - 1; iOuterLoop++)
//     {
//         for (int iInnerLoop = iOuterLoop + 1; iInnerLoop < iArraySize; iInnerLoop++)
//         {
//             if (arriData[iOuterLoop] > arriData[iInnerLoop])
//             {
//                 iTemp = arriData[iOuterLoop];

//                 arriData[iOuterLoop] = arriData[iInnerLoop];
//                 arriData[iInnerLoop] = iTemp;
//             }
//         }
//     }
// }

struct Node
{
    int iData;
    struct Node* ptrNextNode;
    struct Node* ptrPrevNode;
};

void selectSort(struct Node* head)
{
    while (head->ptrNextNode != nullptr)
    {
        struct Node* ptrMinNode = head;
        struct Node* ptrCurrentNode = head->ptrNextNode;

        while (ptrCurrentNode != nullptr)
        {
            if (ptrCurrentNode->iData < ptrMinNode->iData)
            {
                
            }

            ptrCurrentNode = ptrCurrentNode->ptrNextNode;
        }

        head = head->ptrNextNode;
    }

    // int iTemp;

    // for (int iOuterLoop = 0; iOuterLoop < iArraySize - 1; iOuterLoop++)
    // {
    //     for (int iInnerLoop = iOuterLoop + 1; iInnerLoop < iArraySize; iInnerLoop++)
    //     {
    //         if (arriData[iOuterLoop] > arriData[iInnerLoop])
    //         {
    //             iTemp = arriData[iOuterLoop];

    //             arriData[iOuterLoop] = arriData[iInnerLoop];
    //             arriData[iInnerLoop] = iTemp;
    //         }
    //     }
    // }
}

// Doubly linked list

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
// End of doubly linked list

int main()
{
    // cout << "\n======================\n" << endl;

    // cout << "Select sorting\n" << endl;

    // int arriData1[] = {9, 10, 4, 2, 6, 7, 1, 3, 5, 8};
    // int iArraySize = sizeof(arriData1) / sizeof(arriData1[0]);

    // cout << "Array size: " << iArraySize << endl;
    // cout << "Original array: ";
    // printArray(arriData1, iArraySize);

    // cout << "\n======================\n" << endl;

    // cout << "Testing selectSort():" << endl;

    // selectSort(arriData1, iArraySize);

    // cout << "Array after selectSort(): ";

    // printArray(arriData1, iArraySize);

    // auto timeStart = high_resolution_clock::now();
    // for (int i = 0; i < 1000000; i++)
    // {
    //     int arriData1[] = {9, 10, 4, 2, 6, 7, 1, 3, 5, 8};
    //     selectSort(arriData1, iArraySize);
    // }
    // auto timeStop = high_resolution_clock::now();
    
    // auto timeTaken = duration_cast<milliseconds>(timeStop - timeStart);
    
    // cout << "Time taken for 1M iterations: " << timeTaken.count() << " milliseconds" << endl;

    // cout << "\n======================\n" << endl;

    struct Node* ptrHead = nullptr;
    insertFront(&ptrHead, 1);
    insertFront(&ptrHead, 4);
    insertFront(&ptrHead, 2);
    insertFront(&ptrHead, 3);
    insertFront(&ptrHead, 5);

    displayList(ptrHead);
    selectSort(ptrHead);
    displayList(ptrHead);

    return 0;
}