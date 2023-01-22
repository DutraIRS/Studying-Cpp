#include <iostream>

using namespace std;

void findMinMax(int array[], int size, int *min, int *max)
{
    for (int i = 1; i < size; i++)
    {
        if (array[i] < *min)
        {
            *min = array[i];
        }
        if (array[i] > *max)
        {
            *max = array[i];
        }
    }
}

int main()
{
    int n = 5;
    cout << "n = " << n << "\n\n" << &n << endl;
    int *p = &n; 
    // p is a pointer to n
    // pointer is a variable that stores the address of another variable

    cout << p << endl;
    cout << *p << endl;

    *p = 10;

    cout << *p << endl;
    cout << n << endl;

    int numbers[5] = {1, 2, 3, 4, 5};

    cout << numbers << endl;
    cout << *numbers << endl;
    cout << &numbers[0] << endl;
    cout << numbers[0] << endl;
    cout << (numbers + 1) << endl;
    cout << *(numbers + 1) << endl;

    int min = numbers[0];
    int max = numbers[0];
    findMinMax(numbers, 5, &min, &max);

    cout << "min = " << min << endl;
    cout << "max = " << max << endl;

    system("pause");
    return 0;
}