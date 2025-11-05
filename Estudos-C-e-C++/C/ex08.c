#include <stdio.h>

int main() {
    float numero; 
    float quintaParte;

    printf("Digite um numero real: ");
    scanf("%f", &numero);

    quintaParte = numero / 5.0; 

    printf("\nA quinta parte de %.2f e: %.2f\n", numero, quintaParte);

    return 0;
}