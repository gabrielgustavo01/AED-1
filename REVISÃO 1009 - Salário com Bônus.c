#include <stdio.h>

int main() {
    char nome[50];
    double salarioFixo, vendas, totalReceber;

    // Leitura dos dados de entrada
    scanf("%s", nome);
    scanf("%lf %lf", &salarioFixo, &vendas);

    // Cálculo do total a receber
    totalReceber = salarioFixo + (vendas * 0.15);

    // Impressão do resultado
    printf("TOTAL = R$ %.2f\n", totalReceber);

    return 0;
}
