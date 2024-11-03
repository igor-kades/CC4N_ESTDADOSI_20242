#include <stdio.h>

#define MAX 10

void bubblesort(int *v){
    for (int i = MAX - 1; i > 0; i--){
        for (int j = 0; j < i; j++) {
            if (v[j] > v[j+1]) {
                int temp = v[j];
                v[j] = v[j + 1];
                v[j + 1] = temp;
            }
        }
    }
}

void printArray(int *v){
    for (int i = 0; i < MAX; i++){
        printf("%d ", v[i]);
    }

    printf("\n");
}

int main(){
    int v[MAX] = {9,8,7,6,5,4,3,2,1,0};
    printArray(v);
    bubblesort(v);
    printArray(v);

    return 0;    
}
