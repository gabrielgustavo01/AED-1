// Nome: Gabriel Gustavo Pinto Ra:163.730
//Turma AED 1 - Noturno


#include <stdio.h>

int verificacao(int mat[9][9]) {
    // Verificação das linhas
    for (int i = 0; i < 9; i++) {
        int linha[10] = {0}; 
        for (int j = 0; j < 9; j++) {
            int x = mat[i][j];
            if (x < 1 || x > 9 || linha[x]) {
                return 0; 
            }
            linha[x] = 1; // Marca o número como encontrado
        }
    }

    // Verificação das colunas
    for (int j = 0; j < 9; j++) {
        int coluna[10] = {0}; 
        for (int i = 0; i < 9; i++) {
            int x = mat[i][j];
            if (x < 1 || x > 9 || coluna[x]) {
                return 0; 
            }
            coluna[x] = 1; // Marca o número como encontrado
        }
    }

    // Verificação dos blocos 3x3
    for (int blocoI = 0; blocoI < 3; blocoI++) {
        for (int blocoJ = 0; blocoJ < 3; blocoJ++) {
            int submatriz[10] = {0}; 
            for (int i = blocoI * 3; i < (blocoI + 1) * 3; i++) {
                for (int j = blocoJ * 3; j < (blocoJ + 1) * 3; j++) {
                    int x = mat[i][j];
                    if (x < 1 || x > 9 || submatriz[x]) {
                        return 0; 
                    }
                    submatriz[x] = 1; // Marca o número como encontrado
                }
            }
        }
    }

    return 1; 
}

int main() {
    int n;
    scanf("%d", &n); // Lê o número de casos

    for (int caso = 1; caso <= n; caso++) {
        int mat[9][9]; // Matriz 9x9 para cada caso

        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                scanf("%d", &mat[i][j]);
            }
        }

        // Exibe o número da instância e resultado da verificação
        printf("Instancia %d\n", caso);
        if (verificacao(mat)) {
            printf("SIM\n");
        } else {
            printf("NAO\n");
        }
        printf("\n"); 
    }

    return 0; 
}
