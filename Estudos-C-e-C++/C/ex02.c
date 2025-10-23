#include <stdio.h> 
int main() {
    float base, altura, resultado;
    printf("Calculando a area de um retangulo. Digite a base e a altura:\n");   
    printf("Base: ");
    scanf("%f", &base);
    printf("Altura: ");
    scanf("%f", &altura);
    resultado = base*altura;
    printf("A area do retangulo eh: %.2f", resultado);
    return 0;
}