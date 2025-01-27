#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main() {
    int N;
    scanf("%d", &N);

    char linha[15];
    for (int i = 0; i < N; i++) {
        scanf("%s", linha);

        int soma = 0, numero = 0;
        for (int j = 0; j < 14; j++) {
            if (isdigit(linha[j])) {
                numero = numero * 10 + (linha[j] - '0');
            } else {
                soma += numero;
                numero = 0;
            }
        }
        soma += numero;

        printf("%d\n", soma);
    }

    return 0;
}
