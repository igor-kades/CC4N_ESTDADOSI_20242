#include <stdio.h>
#include <stdlib.h>

#define arraySize(x) (int) (sizeof(x) / sizeof((x)[0]))

void printArray(int arr[], int size){
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }

    printf("\n");
}

void swap(int arr[], int x, int y) {
    int temp = arr[x];
    arr[x] = arr[y];
    arr[y] = temp;
}

int partition(int arr[], int left, int right){
    int random = (rand() % (right - left)) + left;    

    swap(arr, left, random);

    int pivot = arr[left];

    int i = left;

    for (int j = left + 1; j <= right; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(arr, i, j);
        }
    }

    swap (arr, left, i);
    return i;
}

void quicksort(int arr[], int left, int right) {
    if (left >= right) return;

    int pivot = partition(arr, left, right);
    quicksort(arr, left, pivot - 1);
    quicksort(arr, pivot + 1, right);
}

int main() {
    int arr[] = {10,9,8,7,6,5,4,3,2,1};
    int size = arraySize(arr);

    printArray(arr, size);
    quicksort(arr, 0, size - 1);
    printArray(arr, size);

    return 0;
}