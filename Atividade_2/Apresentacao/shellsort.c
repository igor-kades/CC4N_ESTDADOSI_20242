#include <stdio.h>
#include <stdlib.h>

#define MAX 11

void printArray(int size, int v[size]) {
    for (int i = 0; i < MAX; i++) {
        printf("%d ", v[i]);
    }

    printf("\n");
}

void shellsort(int size, int *v) {
    int i, j, h = 1, aux, count = 0;

    for (; h < size; h = h * 3 + 1) ;

    do {
        h /= 3;
        for (i = h; i < size; i++) {
            aux = v[i];
            j = i;
            while (j > h-1 && aux <= v[j -h]) {
                v[j] = v[j - h];
                j -= h;
            }

            v[j] = aux;
        }
        printf("PASSO %d [h = %d]:\t", ++count, h);
        printArray(size, v);
    } while (h != 1);

}

int main () {
    int v[MAX];

    for (int i = 0; i < MAX; i++) {
        v[i] = rand() % 20 + 1;
    }

    printf("Vetor inicial:\t\t");
    printArray(MAX, v);

    shellsort(MAX, v);
    
    printf("Vetor final:\t\t");
    printArray(MAX, v);

    return 0;
}