#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void bubbleSort(char** arr, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (strcmp(arr[j], arr[j + 1]) > 0) {
                char* temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    int N, K;
    scanf("%d %d", &N, &K);

    // Aloca memória para os nomes dos alunos
    char** alunos = (char**)malloc(N * sizeof(char*));
    for (int i = 0; i < N; i++) {
        alunos[i] = (char*)malloc(21 * sizeof(char)); // Nome com até 20 caracteres
        scanf("%s", alunos[i]);
    }

    // Ordena os nomes em ordem alfabética utilizando Bubble Sort
    bubbleSort(alunos, N);

    // Imprime K-1
    printf("%s\n", alunos[K - 1]);

    // Libera a memória alocada
    for (int i = 0; i < N; i++) {
        free(alunos[i]);
    }
    free(alunos);

    return 0;
}
