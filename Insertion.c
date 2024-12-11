#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void ordenacaoInsercao(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int chave = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > chave) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = chave;
    }
}

int main() {
    for (int tamanho = 0; tamanho <= 400000; tamanho += 20000) {
        int *arr = malloc(tamanho * sizeof(int));
        for (int i = 0; i < tamanho; i++) {
            arr[i] = rand() % tamanho;
        }

        clock_t inicio = clock();
        ordenacaoInsercao(arr, tamanho);
        clock_t fim = clock();

        double tempo_gasto = ((double) (fim - inicio)) / CLOCKS_PER_SEC;
        printf("Ordenacao por Insertion com %d elementos levou %f segundos para executar \n", tamanho, tempo_gasto);

        free(arr);
    }

    return 0;
}

