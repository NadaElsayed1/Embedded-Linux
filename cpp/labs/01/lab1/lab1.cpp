#include <iostream>
#include <cstring>

using namespace std;

void createArray(char **arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        int nameLength;
        cout << "Enter the size of name " << i + 1 << ": ";
        cin >> nameLength;
        arr[i] = new char[nameLength + 1];
        cout << "Enter name " << i + 1 << ": ";
        cin.ignore(); // to ignore any newline character left in the buffer
        cin.getline(arr[i], nameLength + 1);
    }
}

void printArray(char **arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << ' ';
    }
    cout << endl;
}

void deleteArray(char **arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        delete[] arr[i]; // Free memory for each string
    }
    delete[] arr; // Free memory for the array of pointers
}

int main()
{
    int size;
    cout << "Enter the number of names: ";
    cin >> size;

    char **arr = new char *[size];

    createArray(arr, size);
    printArray(arr, size);
    deleteArray(arr, size);

    return 0;
}