#include <stdio.h>
#include <stdlib.h>

#define arraySize(x) (int) (sizeof(x) / sizeof((x)[0]))

void printArray(int arr[], int size){
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }

    printf("\n");

}

void merge (int arr[], int left, int mid, int right) {
    int i, j, k;
    int size_left = mid - left + 1;
    int size_right = right - mid;

    int arr_left[size_left], arr_right[size_right];

    for (i = 0; i < size_left; i++) 
        arr_left[i] = arr[left + i];
    for (j = 0; j < size_right; j++) 
        arr_right[j] = arr[mid + 1 + j];

    i = 0;
    j = 0;
    k = left;
    while (i < size_left && j < size_right) {
        if (arr_left[i] <= arr_right[j]) {
            arr[k] = arr_left[i];
            i++;
        }
        else {
            arr[k] = arr_right[j];
            j++;
        }
        k++;
    }

    while (i < size_left) {
        arr[k] = arr_left[i];
        i++;
        k++;
    }



    // int size = right - left + 1;
    // // printf("size: %d  left: %d  mid: %d  right: %d\n", size, left, mid, right);
    // int aux[size];
    
    // for (int i = left, j = 0; j < size; i++, j++) {
    //     aux[j] = arr[i];
    // }
    // printArray(arr, 10);

    // int i = left;
    // int auxI = 0;
    // int j = mid+1;
    // int auxJ = mid-left;
    // int k = left;

    // printf("(mid - left + 1): %d\n", (mid - left + 1));
    // printf("(right - mid): %d\n", (right - mid));

    // while (i <= (mid - left + 1) && j <= (right - mid)) {
    //     printf("%d %d %d\n", i, j, k);
    //     if (aux[i] <= aux[j]) {
    //         arr[k] = aux[i];
    //         i++;
    //     } else {
    //         arr[k] = aux[j];
    //         j++;
    //     }

    //     k++;
    // }

    // while(i < (mid - left + 1)) {
    //     arr[k] = aux[i];
    //     i++;
    //     k++;
    // }

    // while(j < (right - mid)) {
    //     arr[k] = aux[j];
    //     j++;
    //     k++;
    // }

    // printArray(arr, 10);
    // printf("\n");
}


void mergeSort(int arr[], int left, int right) {
    if (left >= right) return;

    int mid = (left + right) / 2;

    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);

    merge(arr, left, mid, right);

}

int main() {
    int arr[] = {10,9,8,7,6,5,4,3,2,1};
    int arr_size = arraySize(arr);

    printArray(arr, arr_size);
    mergeSort(arr, 0, arr_size-1);
    printf("\n");
    printArray(arr, arr_size);

    return 0;
}