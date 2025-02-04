#include <stdio.h>

int main() {
    double a, b, c;
    const double pi = 3.14159;
    
    scanf("%lf %lf %lf", &a, &b, &c);
    
    double area_triangulo = (a * c) / 2;
    double area_circulo = pi * c * c;
    double area_trapezio = ((a + b) * c) / 2;
    double area_quadrado = b * b;
    double area_retangulo = a * b;
    
    printf("TRIANGULO: %.3lf\n", area_triangulo);
    printf("CIRCULO: %.3lf\n", area_circulo);
    printf("TRAPEZIO: %.3lf\n", area_trapezio);
    printf("QUADRADO: %.3lf\n", area_quadrado);
    printf("RETANGULO: %.3lf\n", area_retangulo);
    
    return 0;
}
