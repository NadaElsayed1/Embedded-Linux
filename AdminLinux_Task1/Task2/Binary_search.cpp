#include <iostream>

int Binary_search(int arr[], int size, int target)
{
    int middle;
    int left = 0, right = size - 1;
    while (left <= right)
    {
        middle = left + ((right - left) / 2);
        if (target == arr[middle])
            return middle;
        else if (target > arr[middle])
            left = middle + 1;
        else
            right = middle - 1;
    }

    return -1;
}

int main()
{
    int index, target;
    int array[5] = {5, 3, 9, 10, 20};
    std::cout << "Array elements:\n";
    for (int i = 0; i < 5; i++)
    {
        std::cout << array[i] << " ";
    }
    std::cout << std::endl
              << "Please enter an element to search: ";
    std::cin >> target;

    index = Binary_search(array, 5, target);

    if (index != -1)
        printf("%d is at index: %d\n", target, index);
    else
        printf("element not found!\n");

    return 0;
}