#include <stdio.h>
#include <string.h>

int eh_ordenado(char *sequencia, int tamanho) {
    for (int i = 0; i < tamanho - 1; i++) {
        if (sequencia[i] > sequencia[i + 1]) {
            return 0;
        }
    }
    return 1;
}

int verificar_troca(char *sequencia, int tamanho) {
    for (int i = 0; i < tamanho - 1; i++) {
        for (int j = i + 1; j < tamanho; j++) {
            char temp = sequencia[i];
            sequencia[i] = sequencia[j];
            sequencia[j] = temp;

            if (eh_ordenado(sequencia, tamanho)) {
                return 1;
            }

            temp = sequencia[i];
            sequencia[i] = sequencia[j];
            sequencia[j] = temp;
        }
    }
    return 0;
}

int main() {
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        int m;
        char sequencia[27];
        scanf("%d %s", &m, sequencia);

        if (verificar_troca(sequencia, m)) {
            printf("There are the chance.\n");
        } else {
            printf("There aren't the chance.\n");
        }
    }

    return 0;
}
