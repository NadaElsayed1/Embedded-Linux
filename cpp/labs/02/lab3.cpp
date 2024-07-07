#include <iostream>

namespace ArrayPair
{
    std::pair<int*, int *> createArray(int s1, int s2)
    {
        std::pair<int*, int *> array(new int[s1], new int[s2]);
        return array;
    }

    void deleteArray(std::pair<int*, int *> array)
    {
        delete[] array.first;
        delete[] array.second;
    }

    void setPair(std::pair<int*, int *> array, int index, int value1,int value2)
    {
        array.first[index]=value1;
        array.second[index]=value2;
    }
    std::pair<int, int> getPair(std::pair<int*, int *>array, int index)
    {
        return {array.first[index],array.second[index]};
    }
    void print(std::pair<int*, int *>array, int size)
    {
        for(int i = 0; i < size ; i++)
        {
            std::cout << "(" << array.first[i] << "," << array.second[i] << ")" << " ";
        }
        std::cout << std::endl;
    }
}

int main()
{
    int size = 2;
    auto arrayOfpairs = ArrayPair::createArray(size,size);

    for (int i = 0; i < size; i++)
    {
        ArrayPair::setPair(arrayOfpairs,i,i,i*2);
    }
   
    ArrayPair::print(arrayOfpairs,size);

    ArrayPair::deleteArray(arrayOfpairs);

    return 0;
}