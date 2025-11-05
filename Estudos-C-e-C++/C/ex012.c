#include <stdio.h>

int main() {
    int valor_1, valor_2;
    int aux; 

    printf("Digite o primeiro valor (valor_1): ");
    scanf("%d", &valor_1);

    printf("Digite o segundo valor (valor_2): ");
    scanf("%d", &valor_2);

    printf("\n--- Valores ANTES da troca ---\n");
    printf("valor_1 = %d\n", valor_1);
    printf("valor_2 = %d\n", valor_2);

    
    
    aux = valor_1; 
    
    valor_1 = valor_2;
    

    valor_2 = aux;
    


    printf("\n--- Valores DEPOIS da troca ---\n");
    printf("valor_1 = %d\n", valor_1);
    printf("valor_2 = %d\n", valor_2);

    return 0;
}