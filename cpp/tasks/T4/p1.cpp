#include <iostream>
#include <cstring>

template <typename T>
class DynamicArray
{
private:
    T *array;
    int capacity;
    int size;

    void resize(int newCapacity)
    {
        T *newArray = new T[newCapacity];
        for (int i = 0; i < size; i++)
        {
            newArray[i] = array[i];
        }
        delete[] array;
        array = newArray;
        capacity = newCapacity;
    }

public:
    DynamicArray() : array(new T[1]), capacity(1), size(0) {}

    DynamicArray(int initialCapacity) : array(new T[initialCapacity]), capacity(initialCapacity), size(0) {}

    DynamicArray(int initialCapacity, T value) : array(new T[initialCapacity]), capacity(initialCapacity), size(initialCapacity)
    {
        for (int i = 0; i < initialCapacity; i++)
        {
            array[i] = value;
        }
    }

    DynamicArray(int initialCapacity, const T *values) : array(new T[initialCapacity]), capacity(initialCapacity), size(initialCapacity)
    {
        for (int i = 0; i < initialCapacity; i++)
        {
            array[i] = values[i];
        }
    }

    DynamicArray(const DynamicArray &obj) : array(new T[obj.capacity]), capacity(obj.capacity), size(obj.size)
    {
        for (int i = 0; i < size; i++)
        {
            array[i] = obj.array[i];
        }
    }

    ~DynamicArray()
    {
        delete[] array;
    }

    void pushback(T value)
    {
        if (size == capacity)
        {
            resize(capacity * 2);
        }
        array[size++] = value;
    }

    void popback()
    {
        if (size > 0)
        {
            size--;
        }
    }

    void removeAt(int index)
    {
        if (index < 0 || index >= size)
        {
            std::cout << "Invalid index!\n";
            return;
        }
        for (int i = index; i < size - 1; i++)
        {
            array[i] = array[i + 1];
        }
        size--;
    }

    void insertAt(int index, T value)
    {
        if (index < 0 || index > size)
        {
            std::cout << "Invalid index!\n";
            return;
        }
        if (size == capacity)
        {
            resize(capacity * 2);
        }
        for (int i = size; i > index; i--)
        {
            array[i] = array[i - 1];
        }
        array[index] = value;
        size++;
    }

    void insertMiddle(T value)
    {
        insertAt(size / 2, value);
    }

    void removeMiddle()
    {
        if (size > 0)
        {
            removeAt(size / 2);
        }
    }

    int getSize() const
    {
        return size;
    }

    void print() const
    {
        for (int i = 0; i < size; i++)
        {
            std::cout << array[i] << " ";
        }
        std::cout << std::endl;
    }
};

int main()
{
    int values[] = {15, 15, 15};
    DynamicArray<int> arr(3, values);
    std::cout << "Original array: ";
    arr.print();

    DynamicArray<int> arrc = arr;
    std::cout << "Copied array: ";
    arrc.print();

    std::cout << "Modifying the Original array: " << std::endl;

    std::cout << "Push 20: ";
    arr.pushback(20);
    arr.print();

    std::cout << "Pop the last element: ";
    arr.popback();
    arr.print();

    std::cout << "Insert 30 at index 2: ";
    arr.insertAt(2, 30);
    arr.print();

    std::cout << "Remove the 1st element: ";
    arr.removeAt(1);
    arr.print();

    std::cout << "Push 10: ";
    arr.pushback(10);
    arr.print();

    std::cout << "Insert 40 @ middle: ";
    arr.insertMiddle(40);
    arr.print();

    std::cout << "Remove the middle element: ";
    arr.removeMiddle();
    arr.print();

    std::cout << "Copied array after original array is modified: ";
    arrc.print();

    std::cout << "Size of array: " << arr.getSize() << std::endl;

    return 0;
}
