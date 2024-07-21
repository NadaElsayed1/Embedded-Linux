#include <iostream>

namespace DynamicAlloc
{
    int** create2DArray(int size)
    {
        int** array = new int*[size];
        for (int i = 0; i < size; ++i)
        {
            array[i] = new int[size];
            for (int j = 0; j < size; ++j)
            {
                std::cin >> array[i][j];
            }
        }

        return array;
    }

    void delete2DArray(int** array, int size)
    {
        for (int i = 0; i < size; ++i)
        {
            delete[] array[i];
        }
        delete[] array;
    }
}

int main()
{
    int size = 2;
    std::cout << "Enter elements for the 2D array:" << std::endl;
    int** array = DynamicAlloc::create2DArray(size);
   
    std::cout << "Your entered array:" << std::endl;
    for (int i = 0; i < size; ++i)
    {
        for (int j = 0; j < size; ++j)
        {
            std::cout << array[i][j] << " ";
        }
        std::cout << std::endl;
    }

    DynamicAlloc::delete2DArray(array, size);
   
    std::cout << "Array deleted successfully." << std::endl;
   
    return 0;
}