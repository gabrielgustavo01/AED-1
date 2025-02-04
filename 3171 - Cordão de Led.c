#include <stdio.h>

int maior[101];

int encontrar(int x) {
    if (maior[x] == x) return x;
    return maior[x] = encontrar(maior[x]);
}

void unir(int x, int y) {
    int px = encontrar(x);
    int py = encontrar(y);
    if (px != py) maior[py] = px;
}

int main() {
    int n, l;
    scanf("%d %d", &n, &l);

    for (int i = 1; i <= n; i++) maior[i] = i;

    for (int i = 0; i < l; i++) {
        int x, y;
        scanf("%d %d", &x, &y);
        unir(x, y);
    }

    int raiz = encontrar(1);
    for (int i = 2; i <= n; i++) {
        if (encontrar(i) != raiz) {
            printf("INCOMPLETO\n");
            return 0;
        }
    }
    
    printf("COMPLETO\n");
    return 0;
}
