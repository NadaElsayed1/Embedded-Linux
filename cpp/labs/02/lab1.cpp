#include <iostream>
#include <cmath>
#include <cstring>

namespace MathFunctions
{
    void print(double x)
    {
        double result = sqrt(x);
        std::cout << "Square root: " << result << std::endl;
    }
}

namespace StringFunctions
{
    void print(char* x)
    {
        int i = 0;
        while (x[i] != '\0')
        {
            if (x[i] >= 'a' && x[i] <= 'z')
            {
                x[i] = x[i] - 32;
            }
            else if (x[i] >= 'A' && x[i] <= 'Z')
            {
                x[i] = x[i] + 32;
            }
            i++;
        }
        std::cout << "Modified string: " << x << std::endl;
    }
}

namespace ArrayFunctions
{
    void print(int arr[], int size)
    {
        int rarr[size];
        for (int i = 0, j = size - 1; i < size; i++, j--)
        {
            rarr[i] = arr[j];
        }
        std::cout << "Reversed array: ";
        for (int i = 0; i < size; i++)
        {
            std::cout << rarr[i] << " ";
        }
        std::cout << std::endl;
    }
}

int main()
{
    int array[] = {1, 2, 3, 4, 5, 6};
    MathFunctions::print(16);
   
    char str[] = "Nada";
    StringFunctions::print(str);
   
    ArrayFunctions::print(array, 6);

    return 0;
}