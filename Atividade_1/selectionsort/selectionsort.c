#include <stdio.h>

#define MAX 10

void printArray(int *v){
    for (int i = 0; i < MAX; i++){
        printf("%d ", v[i]);
    }

    printf("\n");
}

void selectionsort(int *v) {
    for (int i = 0; i < MAX; i++){
        int minIndex = i;
        for (int j = i + 1; j < MAX; j++){
            if (v[minIndex] > v[j]) minIndex = j;
        }

        if (minIndex != i) {
            int temp = v[i];
            v[i] = v[minIndex];
            v[minIndex] = temp;
        }
    }
}

int main() {
    int v[MAX] = {9,8,7,6,5,4,3,2,1,0};

    printArray(v);
    selectionsort(v);
    printArray(v);

    return 0;
}