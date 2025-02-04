#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PALAVRAS 1000
#define MAX_DESCRICOES 100
#define TAM_PALAVRA 17

typedef struct {
    char palavra[TAM_PALAVRA];
    int valor;
} Entrada;

int buscar_valor(Entrada *dicionario, int m, char *palavra) {
    for (int i = 0; i < m; i++) {
        if (strcmp(dicionario[i].palavra, palavra) == 0) {
            return dicionario[i].valor;
        }
    }
    return 0;
}

int main() {
    int m, n;
    scanf("%d %d", &m, &n);
    
    Entrada *dicionario = malloc(m * sizeof(Entrada));
    
    for (int i = 0; i < m; i++) {
        scanf("%s %d", dicionario[i].palavra, &dicionario[i].valor);
    }
    
    char palavra[TAM_PALAVRA];
    int salario = 0;
    
    while (n > 0) {
        while (scanf("%s", palavra) == 1) {
            if (strcmp(palavra, ".") == 0) break;
            salario += buscar_valor(dicionario, m, palavra);
        }
        printf("%d\n", salario);
        salario = 0;
        n--;
    }
    
    free(dicionario);
    return 0;
}
