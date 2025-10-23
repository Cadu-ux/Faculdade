#include <stdio.h> 
int main() {
    float distancia, tempo, velocidade;
    printf("Calculando a velocidade de um carro. Digite a distancia e o tempo:\n");
    printf("Distancia: ");
    scanf ("%f", &distancia);
    printf("Tempo: ");
    scanf ("%f", &tempo);
    velocidade = distancia / tempo;
    printf("A velocidade do carro eh: %.2f km/h", velocidade);
    return 0;
}