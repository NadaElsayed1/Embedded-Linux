#include <iostream>
#include <utility>

namespace ArrayPair
{
    std::pair<int, int>* createArray(int size)
    {
        std::pair<int, int>* array = new std::pair<int, int>[size];
        return array;
    }

    void deleteArray(std::pair<int, int>* array)
    {
        delete[] array;
    }

    void setPair(std::pair<int, int>* array, int index, int value1, int value2)
    {
        array[index] = std::make_pair(value1, value2);
    }

    std::pair<int, int> getPair(std::pair<int, int>* array, int index)
    {
        return array[index];
    }

    void print(std::pair<int, int>* array, int size)
    {
        for (int i = 0; i < size; i++)
        {
            std::cout << "(" << array[i].first << "," << array[i].second << ") ";
        }
        std::cout << std::endl;
    }
}

int main()
{
    int size = 2;
    auto arrayOfPairs = ArrayPair::createArray(size);

    for (int i = 0; i < size; i++)
    {
        ArrayPair::setPair(arrayOfPairs, i, i, i * 2);
    }

    ArrayPair::print(arrayOfPairs, size);

    ArrayPair::deleteArray(arrayOfPairs);

    return 0;
}