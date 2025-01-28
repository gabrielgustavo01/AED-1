#include <stdio.h>
#include <stdlib.h>

int comparaDecrescente(const void *a, const void *b) {
    return (*(int *)b - *(int *)a);
}

int main() {
    int N; 
    scanf("%d", &N);

    while (N--) {
        int M; 
        scanf("%d", &M);

        int notas[M];
        int notasOrdenadas[M];
        int alunosSemTroca = 0;

        for (int i = 0; i < M; i++) {
            scanf("%d", &notas[i]);
            notasOrdenadas[i] = notas[i];
        }

        qsort(notasOrdenadas, M, sizeof(int), comparaDecrescente);

        for (int i = 0; i < M; i++) {
            if (notas[i] == notasOrdenadas[i]) {
                alunosSemTroca++;
            }
        }

        printf("%d\n", alunosSemTroca);
    }

    return 0;
}
