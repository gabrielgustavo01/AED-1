#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void mesclar(int arr[], int esq, int meio, int dir) {
    int i, j, k;
    int n1 = meio - esq + 1;
    int n2 = dir - meio;

    int L[n1], R[n2];

    for (i = 0; i < n1; i++)
        L[i] = arr[esq + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[meio + 1 + j];

    i = 0;
    j = 0;
    k = esq;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void ordenacaoMerge(int arr[], int esq, int dir) {
    if (esq < dir) {
        int meio = esq + (dir - esq) / 2;

        ordenacaoMerge(arr, esq, meio);
        ordenacaoMerge(arr, meio + 1, dir);

        mesclar(arr, esq, meio, dir);
    }
}

int main() {
    for (int tamanho = 0; tamanho <= 400000; tamanho += 20000) {
        int *arr = malloc(tamanho * sizeof(int));
        for (int i = 0; i < tamanho; i++) {
            arr[i] = rand() % tamanho;
        }

        clock_t inicio = clock();
        ordenacaoMerge(arr, 0, tamanho - 1);
        clock_t fim = clock();

        double tempo_gasto = ((double) (fim - inicio)) / CLOCKS_PER_SEC;
        printf("Ordenacao por MergeSort com %d elementos levou %f segundos para executar \n", tamanho, tempo_gasto);

        free(arr);
    }

    return 0;
}
