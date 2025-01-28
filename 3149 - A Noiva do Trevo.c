#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int hora;
    int minuto;
    char nome[101];
} Relato;

int comparar(const void *a, const void *b) {
    Relato *r1 = (Relato *)a;
    Relato *r2 = (Relato *)b;

    if (r1->hora != r2->hora) {
        return r1->hora - r2->hora;
    } else if (r1->minuto != r2->minuto) {
        return r1->minuto - r2->minuto;
    }
    return 0;
}

int main() {
    int P, Q;
    scanf("%d %d", &P, &Q);

    Relato relatos[Q];
    int count = 0;

    for (int i = 0; i < Q; i++) {
        char horario[6], nome[101];
        scanf("%s %s", horario, nome);

        int hora, minuto;
        sscanf(horario, "%d:%d", &hora, &minuto);

        if (hora == 0) hora = 24;

        if ((hora == 23 && minuto >= (60 - P)) || (hora == 24 && minuto <= P)) {
            relatos[count].hora = hora;
            relatos[count].minuto = minuto;
            strcpy(relatos[count].nome, nome);
            count++;
        }
    }

    qsort(relatos, count, sizeof(Relato), comparar);

    for (int i = 0; i < count; i++) {
        printf("%s\n", relatos[i].nome);
    }

    return 0;
}
