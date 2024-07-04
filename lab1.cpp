#include <iostream>
#include <cstring>

using namespace std;

void createArray(char** Arr, int n)
{
    for(int i = 0; i < n; i++)
    {
        int nameLength;
        cout << "Enter the size of name " << i+1 << ": ";
        cin >> nameLength;
        Arr[i] = new char[nameLength + 1];
        cout << "Enter name " << i+1 << ": ";
        cin.ignore(); // to ignore any newline
        cin.getline(Arr[i], nameLength + 1);
}

void printArray(char** Arr, int n)
{
    for(int i = 0; i < n; i++)
    {
        cout << Arr[i] << ' ';  
    }
    cout << endl;  
}

void deleteArray(char** Arr, int n)
{
    for(int i = 0; i < n; i++)
    {
        delete[] Arr[i]; // Free memory for each string
    }
    delete[] Arr; // Free memory for the array of pointers
}

int main()
{
    int size;
    cout << "Enter the number of names: ";
    cin >> size;

    char** arr = new char*[size];

    createArray(arr, size);
    printArray(arr, size);
    deleteArray(arr, size);

    return 0;
}