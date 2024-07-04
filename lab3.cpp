#include <iostream>

using namespace std;

typedef int *(*SumCallback)(int **, int, int *);

int *sumRows(int **array, int rows, int *rowSizes)
{
    int *sums = new int[rows];
    for (int i = 0; i < rows; ++i)
    {
        sums[i] = 0;
        for (int j = 0; j < rowSizes[i]; ++j)
        {
            sums[i] += array[i][j];
        }
    }
    return sums;
}

int *processArray(int **array, int rows, int *rowSizes, SumCallback callback)
{
    return callback(array, rows, rowSizes);
}

int main()
{
    int rows;
    cout << "Enter the number of rows: ";
    cin >> rows;

    int **array = new int *[rows];
    int *rowSizes = new int[rows];

    for (int i = 0; i < rows; ++i)
    {
        cout << "Enter the number of elements in row " << i + 1 << ": ";
        cin >> rowSizes[i];
        array[i] = new int[rowSizes[i]];
        cout << "Enter the elements of row " << i + 1 << ":\n";
        for (int j = 0; j < rowSizes[i]; ++j)
        {
            cin >> array[i][j];
        }
    }

    int *result = processArray(array, rows, rowSizes, sumRows);

    cout << "Sums of rows:\n";
    for (int i = 0; i < rows; ++i)
    {
        cout << "Sum of row " << i + 1 << ": " << result[i] << endl;
    }

    // Clean up
    for (int i = 0; i < rows; ++i)
    {
        delete[] array[i];
    }
    delete[] array;
    delete[] rowSizes;
    delete[] result;

    return 0;
}