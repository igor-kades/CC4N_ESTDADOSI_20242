#include <stdio.h>
#include <stdlib.h>

#define arraySize(x) (int)(sizeof(x) / sizeof((x)[0]))

void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }

    printf("\n");
}

void swap(int arr[], int x, int y)
{
    int temp = arr[x];
    arr[x] = arr[y];
    arr[y] = temp;
}

void heapifyMin(int arr[], int size, int root)
{
    int smallest = root;
    int left = 2 * root + 1;
    int right = 2 * root + 2;

    if (left < size && arr[left] < arr[smallest])
    {
        smallest = left;
    }

    if (right < size && arr[right] < arr[smallest])
    {
        smallest = right;
    }

    if (smallest != root)
    {
        swap(arr, root, smallest);
        heapifyMin(arr, size, smallest);
    }
}

void heapifyMax(int arr[], int size, int root)
{
    int largest = root;
    int left = 2 * root + 1;
    int right = 2 * root + 2;

    if (left < size && arr[left] > arr[largest])
    {
        largest = left;
    }

    if (right < size && arr[right] > arr[largest])
    {
        largest = right;
    }

    // If largest is not root
    if (largest != root)
    {
        swap(arr, root, largest);
        heapifyMax(arr, size, largest);
    }
}

void heapsortMax(int arr[], int size)
{
    for (int i = size / 2 - 1; i >= 0; i--)
    {
        heapifyMax(arr, size, i);
    }

    for (int i = size - 1; i >= 0; i--)
    {
        swap(arr, i, 0);
        heapifyMax(arr, i, 0);
    }
}

void heapsortMin(int arr[], int size)
{

    for (int i = size / 2 - 1; i >= 0; i--)
    {
        heapifyMin(arr, size, i);
    }

    for (int i = size - 1; i > 0; i--)
    {
        swap(arr, i, 0);
        heapifyMin(arr, i, 0);
    }
}

int main()
{
    int arr[] = {9, 4, 3, 8, 10, 2, 5};
    int size = arraySize(arr);

    printArray(arr, size);

    heapsortMin(arr, size);
    printArray(arr, size);

    heapsortMax(arr, size);
    printArray(arr, size);

    return 0;
}