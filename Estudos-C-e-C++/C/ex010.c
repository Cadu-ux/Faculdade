#include <stdio.h>

int main() {
    float n1, n2, n3, n4;
    float media;

    printf("Digite as quatro notas (separadas por espaco): ");
    
    // O scanf pode ler vários valores de uma vez,se lembre disso
    scanf("%f %f %f %f", &n1, &n2, &n3, &n4);

    media = (n1 + n2 + n3 + n4) / 4.0;

    printf("\nA media aritmetica eh: %.2f\n", media);

    return 0;
}