#include <stdio.h>
int main () {
    float v1, v2, v3, media;
    printf("Digite 3 valores para calcular a media: \n");
    printf("Primeiro valor: ");
    scanf("%f", &v1);
    printf("Segundo valor: ");
    scanf("%f", &v2);
    printf("Terceiro valor: ");
    scanf("%f", &v3);
    media = (v1+v2+v3)/3;
    printf("A media eh: %.2f", media);
    return 0;
}