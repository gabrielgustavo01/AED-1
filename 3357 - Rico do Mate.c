#include <stdio.h>
#include <string.h>

int main() {
    int N;
    float L, Q;
    char nomes[10][13];

    scanf("%d %f %f", &N, &L, &Q);
  
    for (int i = 0; i < N; i++) {
        scanf("%s", nomes[i]);
    }

    int cuias_completas = (int)(L / Q);
    float ultima_cuia_volume = L - (cuias_completas * Q);

    int rico_indice = cuias_completas % N;

    if (ultima_cuia_volume == 0.0f) {
        rico_indice = (rico_indice - 1 + N) % N;
        ultima_cuia_volume = Q;
    }

    printf("%s %.1f\n", nomes[rico_indice], ultima_cuia_volume);

    return 0;
}
