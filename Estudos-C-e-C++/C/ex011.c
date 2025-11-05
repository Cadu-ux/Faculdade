#include <stdio.h>

#define PI 3.141592

int main() {
    float graus;
    float radianos;

    printf("Digite o angulo em Graus: ");
    scanf("%f", &graus);

    radianos = graus * PI / 180.0;
    
    printf("\n%.2f graus equivalem a %.6f radianos.\n", graus, radianos);

    return 0;
}