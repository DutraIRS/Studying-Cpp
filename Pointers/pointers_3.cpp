#include <iostream>
using namespace std;

int main(){
    int rows, cols;
    cout << "Enter the number of rows and columns: " << endl;
    cin >> rows >> cols;

    int **matrix = new int*[rows];

    for (int i = 0; i < rows; i++)
    {
        matrix[i] = new int[cols];
    }

    matrix[0][0] = 1;

    cout << matrix[0][0] << endl;

    for (int i = 0; i < rows; i++)
    {
        delete[] matrix[i];
    }

    delete[] matrix;

    matrix = NULL;

    system("pause");
    return 0;
}