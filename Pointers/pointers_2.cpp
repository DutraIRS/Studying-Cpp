#include <iostream>
using namespace std;

int main()
{
    int myArray[5] = {1, 2, 3, 4, 5};
    
    int size;
    cout << "Enter the size of the array: ";
    cin >> size;

    int *array = new int[size];
    // allocates memory for an array of size elements

    for (int i = 0; i < size; i++)
    {
        cout << "Enter element " << i << ": " << endl;
        cin >> array[i];
    }

    for (int i = 0; i < size; i++)
    {
        cout << array[i] << " ";
        // == cout << *(array + i) << " ";
    }

    delete[] array;
    // deallocates memory for an array of size elements
    array = NULL;
    
    system("pause");
}