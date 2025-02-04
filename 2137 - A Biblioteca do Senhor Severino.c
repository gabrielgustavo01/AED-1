#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compara(const void *a, const void *b) {
    return strcmp((const char *)a, (const char *)b);
}

int main() {
    int n;
    char codigos[1000][5];
    
    while (scanf("%d", &n) != EOF) {
        for (int i = 0; i < n; i++) {
            scanf("%s", codigos[i]);
        }

        qsort(codigos, n, sizeof(codigos[0]), compara);

        for (int i = 0; i < n; i++) {
            printf("%s\n", codigos[i]);
        }
    }
    
    return 0;
}
