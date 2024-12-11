
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void trocar(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

int particionar(int arr[], int baixo, int alto) {
    int pivo = arr[alto];
    int i = (baixo - 1);

    for (int j = baixo; j <= alto - 1; j++) {
        if (arr[j] < pivo) {
            i++;
            trocar(&arr[i], &arr[j]);
        }
    }
    trocar(&arr[i + 1], &arr[alto]);
    return (i + 1);
}

void ordenacaoRapida(int arr[], int baixo, int alto) {
    if (baixo < alto) {
        int pi = particionar(arr, baixo, alto);

        ordenacaoRapida(arr, baixo, pi - 1);
        ordenacaoRapida(arr, pi + 1, alto);
    }
}

int main() {
    for (int tamanho = 50000; tamanho <= 400000; tamanho += 50000) {
        int *arr = malloc(tamanho * sizeof(int));
        for (int i = 0; i < tamanho; i++) {
            arr[i] = rand() % tamanho;
        }

        clock_t inicio = clock();
        ordenacaoRapida(arr, 0, tamanho - 1);
        clock_t fim = clock();

        double tempo_gasto = ((double) (fim - inicio)) / CLOCKS_PER_SEC;
        printf("Ordenacao QuickSort com %d elementos levou %f segundos para executar \n", tamanho, tempo_gasto);

        free(arr);
    }

    return 0;
}
