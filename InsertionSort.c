#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void insertion_sort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

double medirInsertion(int n) {
    int *arr = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 10000;
    }

    clock_t start_time = clock();
    insertion_sort(arr, n);
    clock_t end_time = clock();

    free(arr);

    return (double)(end_time - start_time) / CLOCKS_PER_SEC;
}

int main() {
    srand(time(NULL));

    for (int n = 0; n <= 400000; n += 50000) {
        double tempo = medirInsertion(n);
        printf("Tamanho: %d, Tempo: %.5f segundos\n", n, tempo);
    }

    return 0;
}
