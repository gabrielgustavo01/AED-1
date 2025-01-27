#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    int N;
    scanf("%d", &N);

    char ra[101]; // Permitindo até 100 caracteres + '\0'
    for (int i = 0; i < N; i++) {
        scanf("%s", ra);

        // Verifica se a string começa com "RA" e tem 20 caracteres
        if (strncmp(ra, "RA", 2) != 0 || strlen(ra) != 20) {
            printf("INVALID DATA\n");
            continue;
        }

        // Verifica se os 18 caracteres seguintes são todos dígitos
        int valido = 1;
        for (int j = 2; j < 20; j++) {
            if (!isdigit(ra[j])) {
                valido = 0;
                break;
            }
        }

        if (!valido) {
            printf("INVALID DATA\n");
            continue;
        }

        // Extrai a senha provisória
        char senha[19] = "";
        int index = 0;
        for (int j = 2; j < 20; j++) {
            if (ra[j] != '0' || index > 0) {
                senha[index++] = ra[j];
            }
        }

        if (index == 0) { // Todos os dígitos eram zeros
            printf("INVALID DATA\n");
        } else {
            printf("%s\n", senha);
        }
    }

    return 0;
}
