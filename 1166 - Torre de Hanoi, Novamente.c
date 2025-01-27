#include <stdio.h>
#include <math.h>

#define MAXN 50

int ehQuadradoPerfeito(int x) {
    int raiz = (int)sqrt(x);
    return raiz * raiz == x;
}

int main() {
    int T, N;
    scanf("%d", &T);

    while (T--) {
        scanf("%d", &N);

        int hastes[MAXN] = {0};
        int maxBolas = 0;

        for (int bola = 1; ; bola++) {
            int colocado = 0;
            for (int i = 0; i < N; i++) {
                if (hastes[i] == 0 || ehQuadradoPerfeito(hastes[i] + bola)) {
                    hastes[i] = bola;
                    maxBolas++;
                    colocado = 1;
                    break;
                }
            }
            if (!colocado) {
                break;
            }
        }

        printf("%d\n", maxBolas);
    }

    return 0;
}
