#include <iostream>
#include <chrono>

using namespace std;
using namespace std::chrono;

void printArray(int arriData[], int iArraySize)
{
    cout << "Array elements: {";
    for (int i = 0; i < iArraySize - 1; i++)
    {
        cout << arriData[i] << ", ";
    }
    cout << arriData[iArraySize - 1] << "}" << endl;
}

void swapValues(int& iValue1, int& iValue2)
{
    int iTemp = iValue1;
    iValue1 = iValue2;
    iValue2 = iTemp;
}

void bubbleSort(int arriData[], int iArraySize)
{
    for (int iOuterLoop = 0; iOuterLoop < iArraySize - 1; iOuterLoop++)
        for (int iInnerLoop = 0; iInnerLoop < iArraySize - 1; iInnerLoop++)
            if (arriData[iInnerLoop] > arriData[iInnerLoop + 1])
                swapValues(arriData[iInnerLoop], arriData[iInnerLoop + 1]);
}

void bubbleSortOptimized(int arriData[], int iArraySize)
{
    for (int iOuterLoop = 0; iOuterLoop < iArraySize - 1; iOuterLoop++)
        for (int iInnerLoop = 0; iInnerLoop < iArraySize - 1 - iOuterLoop; iInnerLoop++)
            if (arriData[iInnerLoop] > arriData[iInnerLoop + 1])
                swapValues(arriData[iInnerLoop], arriData[iInnerLoop + 1]);
}

void bubbleSortOptimized2(int arriData[], int iArraySize)
{
    bool bUnordered = true;
    for (int iOuterLoop = 0; iOuterLoop < iArraySize - 1; iOuterLoop++)
    {
        bUnordered = false;
        for (int iInnerLoop = 0; iInnerLoop < iArraySize - 1 - iOuterLoop; iInnerLoop++)
            if (arriData[iInnerLoop] > arriData[iInnerLoop + 1])
            {
                swapValues(arriData[iInnerLoop], arriData[iInnerLoop + 1]);
                bUnordered = true;
            }

        if (!bUnordered) break;
    }

}

int main()
{
    cout << "\n\nBubble sorting\n" << endl;

    int arriData1[] = {42, 7, 0, 666, 13, 1, 77, 32, 777, 980, 14, 2, 3};
    int iArraySize = sizeof(arriData1) / sizeof(arriData1[0]);

    cout << "Array size: " << iArraySize << endl;
    cout << "Original array: ";
    printArray(arriData1, iArraySize);

    cout << "\n======================\n" << endl;

    cout << "Testing swapValues():" << endl;

    swapValues(arriData1[1], arriData1[2]);

    cout << "Array after swapValues(): ";
    printArray(arriData1, iArraySize);

    cout << "\n======================\n" << endl;

    cout << "Testing bubbleSort():" << endl;

    cout << "Array after bubbleSort(): ";

    auto timeStart = high_resolution_clock::now();
    bubbleSort(arriData1, iArraySize);
    auto timeStop = high_resolution_clock::now();

    printArray(arriData1, iArraySize);
    auto timeTaken = duration_cast<nanoseconds>(timeStop - timeStart);
    cout << "Time taken: " << timeTaken.count() << " nanoseconds" << endl;

    cout << "\n======================\n" << endl;

    cout << "Second version of bubbleSort():" << endl;

    int arriData2[] = {42, 7, 0, 666, 13, 1, 77, 32, 777, 980, 14, 2, 3};

    cout << "Shuffled array: ";
    printArray(arriData2, iArraySize);

    cout << "Array after bubbleSortOptimized(): ";

    timeStart = high_resolution_clock::now();
    bubbleSortOptimized(arriData2, iArraySize);
    timeStop = high_resolution_clock::now();

    printArray(arriData2, iArraySize);
    timeTaken = duration_cast<nanoseconds>(timeStop - timeStart);
    cout << "Time taken: " << timeTaken.count() << " nanoseconds" << endl;

    cout << "\n======================\n" << endl;

    cout << "Third version of bubbleSort():" << endl;

    int arriData3[] = {42, 7, 0, 666, 13, 1, 77, 32, 777, 980, 14, 2, 3};

    cout << "Shuffled array: ";
    printArray(arriData3, iArraySize);

    cout << "Array after bubbleSortOptimized2(): ";

    timeStart = high_resolution_clock::now();
    bubbleSortOptimized2(arriData3, iArraySize);
    timeStop = high_resolution_clock::now();

    printArray(arriData3, iArraySize);
    timeTaken = duration_cast<nanoseconds>(timeStop - timeStart);
    cout << "Time taken: " << timeTaken.count() << " nanoseconds" << endl;

    cout << "\n======================\n" << endl;

    int unsortedArray[] = {42, 7, 0, 666, 13, 1, 77, 32, 777, 980, 14, 2, 3};
    timeStart = high_resolution_clock::now();
    for (int i = 0; i < 10000; i++)
    {
        bubbleSort(unsortedArray, iArraySize);
    }
    timeStop = high_resolution_clock::now();

    timeTaken = duration_cast<nanoseconds>(timeStop - timeStart);
    cout << "Time takennn: " << timeTaken.count() << " nanoseconds" << endl;

    return 0;
}