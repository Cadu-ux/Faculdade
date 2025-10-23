#include <stdio.h>
int main () {
    int valor, notas50, notas20, notas10, notas5, notas1;
    printf("Insira o valor em dinheiro: \n");
    scanf("%d", &valor);
    notas50 = valor / 50;
    notas20 = ((valor % 50) / 20);
    notas10 = ((valor % 50) % 20)/ 10;
    notas5 = (((valor % 50) % 20) % 10) / 5;
    notas1 = ((((valor % 50)% 20) % 10) % 5) / 1;
    printf("Notas de 50: %d\nNotas de 20: %d\nNotas de 10: %d\nNotas de 5: %d\nNotas de 1: %d\n", notas50, notas20, notas10, notas5, notas1);
    
    return 0;
}