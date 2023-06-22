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

void insertionSort(int arriData[], int iArraySize)
{
    for (int iOuterLoop = 1; iOuterLoop < iArraySize; iOuterLoop++)
    {
        int iTemp = arriData[iOuterLoop];
        int iInnerLoop = iOuterLoop - 1;

        while (iTemp < arriData[iInnerLoop] && iInnerLoop >= 0)
        {
            arriData[iInnerLoop + 1] = arriData[iInnerLoop];
            iInnerLoop--;
        }

        arriData[iInnerLoop + 1] = iTemp;
    }
}

int main()
{
    cout << "\n======================\n" << endl;

    cout << "Insertion sorting\n" << endl;

    int arriData1[] = {9, 10, 4, 2, 6, 7, 1, 3, 5, 8};
    int iArraySize = sizeof(arriData1) / sizeof(arriData1[0]);

    cout << "Array size: " << iArraySize << endl;
    cout << "Original array: ";
    printArray(arriData1, iArraySize);

    cout << "\n======================\n" << endl;

    cout << "Testing insertionSort():" << endl;

    insertionSort(arriData1, iArraySize);

    cout << "Array after insertionSort(): ";

    printArray(arriData1, iArraySize);

    auto timeStart = high_resolution_clock::now();
    for (int i = 0; i < 1000000; i++)
    {
        int arriData1[] = {9, 10, 4, 2, 6, 7, 1, 3, 5, 8};
        insertionSort(arriData1, iArraySize);
    }
    auto timeStop = high_resolution_clock::now();
    
    auto timeTaken = duration_cast<milliseconds>(timeStop - timeStart);
    
    cout << "Time taken for 1M iterations: " << timeTaken.count() << " milliseconds" << endl;

    cout << "\n======================\n" << endl;

    return 0;
}