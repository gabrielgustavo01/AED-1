#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
    char nome[21];  
    int idade;     
} Duende;

int comparar(const void* a, const void* b) {
    Duende* duendeA = (Duende*)a;
    Duende* duendeB = (Duende*)b;
    
    if (duendeB->idade != duendeA->idade) {
        return duendeB->idade - duendeA->idade;
    }
    
    return strcmp(duendeA->nome, duendeB->nome);
}

int main() {
    int N;
    
    scanf("%d", &N);
    
    Duende duendes[N];
    
    for (int i = 0; i < N; i++) {
        scanf("%s %d", duendes[i].nome, &duendes[i].idade);
    }

    qsort(duendes, N, sizeof(Duende), comparar);
    
    int numTimes = N / 3;
    
    for (int i = 0; i < numTimes; i++) {
        printf("Time %d\n", i + 1);
        
        printf("%s %d\n", duendes[i].nome, duendes[i].idade);
        
        printf("%s %d\n", duendes[i + numTimes].nome, duendes[i + numTimes].idade);
        
        printf("%s %d\n", duendes[i + 2 * numTimes].nome, duendes[i + 2 * numTimes].idade);
        
        printf("\n");
    }

    return 0;
}
