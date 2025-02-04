#include <stdio.h>

int main() {
    int n;

    while (scanf("%d", &n) && n != 0) {
        for (int i = 0; i < n; i++) {
            int a, b, c, d, e;
            scanf("%d %d %d %d %d", &a, &b, &c, &d, &e);

            int count = 0;
            char resposta = '*';

            if (a <= 127) { resposta = 'A'; count++; }
            if (b <= 127) { resposta = 'B'; count++; }
            if (c <= 127) { resposta = 'C'; count++; }
            if (d <= 127) { resposta = 'D'; count++; }
            if (e <= 127) { resposta = 'E'; count++; }

            if (count != 1) resposta = '*';

            printf("%c\n", resposta);
        }
    }

    return 0;
}
