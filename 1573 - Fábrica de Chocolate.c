#include <stdio.h>
#include <math.h>

int main() {
    int a, b, c;

    while (1) {
        scanf("%d %d %d", &a, &b, &c);
        if (a == 0 && b == 0 && c == 0) break;
        
        int volume = a * b * c;
        int aresta_cubo = (int)cbrt(volume);

        printf("%d\n", aresta_cubo);
    }

    return 0;
}
