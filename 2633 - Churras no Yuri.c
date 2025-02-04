#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char nome[21];
    int dias;
} Carne;

int compara(const void *a, const void *b) {
    return ((Carne*)a)->dias - ((Carne*)b)->dias;
}

int main() {
    int n;
    Carne carnes[10];
    
    while (scanf("%d", &n) != EOF) {
        for (int i = 0; i < n; i++) {
            scanf("%s %d", carnes[i].nome, &carnes[i].dias);
        }

        qsort(carnes, n, sizeof(Carne), compara);

        for (int i = 0; i < n; i++) {
            if (i > 0) printf(" ");
            printf("%s", carnes[i].nome);
        }
        printf("\n");
    }
    
    return 0;
}
