#include <stdio.h>
#include <stdlib.h>

struct DynArray
{
    int* arr;
    int size;
    int capacity;
};

struct DynArray init(int initialSize)
{
    struct DynArray dArr;
    dArr.size = initialSize;
    dArr.capacity = initialSize;
    dArr.arr = (int*)malloc(initialSize * sizeof(int));

    printf("Enter %d elements:\n", initialSize);
    for (int i = 0; i < initialSize; i++)
    {
        scanf("%d", &dArr.arr[i]);
    }

    return dArr;
}

void resize(struct DynArray* dArr, int newSize)
{
    int* newArr = (int*)malloc(newSize * sizeof(int));
    for (int i = 0; i < dArr->size; i++)
    {
        newArr[i] = dArr->arr[i];
    }
    free(dArr->arr);
    dArr->arr = newArr;
    dArr->capacity = newSize;
}

void insertEnd(struct DynArray* dArr)
{
    if (dArr->size == dArr->capacity)
    {
        resize(dArr, dArr->capacity * 2);
    }
    printf("Enter the element to insert at the end: ");
    scanf("%d", &dArr->arr[dArr->size]);
    dArr->size++;
}

void insertBegin(struct DynArray* dArr)
{
    if (dArr->size == dArr->capacity)
    {
        resize(dArr, dArr->capacity * 2);
    }
    for (int i = dArr->size; i > 0; i--)
    {
        dArr->arr[i] = dArr->arr[i - 1];
    }
    printf("Enter the element to insert at the beginning: ");
    scanf("%d", &dArr->arr[0]);
    dArr->size++;
}

void insertAt(struct DynArray* dArr, int pos)
{
    if (pos < 0 || pos > dArr->size)
    {
        printf("Invalid position!\n");
        return;
    }
    if (dArr->size == dArr->capacity)
    {
        resize(dArr, dArr->capacity * 2);
    }
    for (int i = dArr->size; i > pos; i--)
    {
        dArr->arr[i] = dArr->arr[i - 1];
    }
    printf("Enter the element to insert at position %d: ", pos);
    scanf("%d", &dArr->arr[pos]);
    dArr->size++;
}

void print(const struct DynArray* dArr)
{
    for (int i = 0; i < dArr->size; i++)
    {
        printf("%d ", dArr->arr[i]);
    }
    printf("\n");
}

int main()
{
    int initSize;
    printf("Enter the initial size of the array: ");
    scanf("%d", &initSize);

    struct DynArray dArr = init(initSize);
    print(&dArr);

    int pos;
    printf("Enter the position you want to insert at (-1 for end, 0 for beginning, or a specific position): ");
    scanf("%d", &pos);

    if (pos == -1)
    {
        insertEnd(&dArr);
    }
    else if (pos == 0)
    {
        insertBegin(&dArr);
    }
    else
    {
        insertAt(&dArr, pos - 1);
    }

    print(&dArr);

    free(dArr.arr);

    return 0;
}