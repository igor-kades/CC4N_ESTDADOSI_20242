#include <stdio.h>

#define MAX 10

void printArray(int *v){
    for (int i = 0; i < MAX; i++){
        printf("%d ", v[i]);
    }

    printf("\n");
}

void insertionsort(int *v){
    for (int i = 1; i  < MAX; i++) {
        int val = v[i];
        int j = i - 1;

        for(; j >= 0 && v[j] > val; j--) {
            v[j + 1] = v[j];
        }

        v[j + 1] = val;
    }
}

int main () {
    int v[MAX] = {9,8,7,6,5,4,3,2,1,0};

    printArray(v);
    insertionsort(v);
    printArray(v);

    return 0;
}