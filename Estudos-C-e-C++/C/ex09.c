#include <stdio.h>

int main() {
    float valor1, valor2, valor3;
    float soma;

    printf("Digite o primeiro valor: ");
    scanf("%f", &valor1);
    
    printf("Digite o segundo valor: ");
    scanf("%f", &valor2);
    
    printf("Digite o terceiro valor: ");
    scanf("%f", &valor3);

    soma = valor1 + valor2 + valor3;

    printf("\nA soma dos tres valores e: %.2f\n", soma);

    return 0;
}