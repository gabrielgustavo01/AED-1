#include <stdio.h>

int main() {
    int N, A, B;
    
    while (1) {
        scanf("%d", &N);
        if (N == 0) break;
        
        int pontosJogador1 = 0;
        int pontosJogador2 = 0;
        
        for (int i = 0; i < N; i++) {
            scanf("%d %d", &A, &B);
            if (A > B) {
                pontosJogador1++;
            } else if (B > A) {
                pontosJogador2++;
            }
        }
        
        printf("%d %d\n", pontosJogador1, pontosJogador2);
    }
    
    return 0;
}
