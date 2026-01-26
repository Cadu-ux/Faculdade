#include <stdio.h>
int main() {
float notas[10], soma=0, maior, menor;
    int i;

    for(i=0; i<10; i++) {
        printf("Nota %d: ", i+1);
        scanf("%f", &notas[i]);
        soma += notas[i];
        
        if(i==0) { // Inicializa com o primeiro valor
            maior = notas[i];
            menor = notas[i];
        } else {
            if(notas[i] > maior) maior = notas[i];
            if(notas[i] < menor) menor = notas[i];
        }
    }

    printf("Maior: %.2f\nMenor: %.2f\nMédia: %.2f\n", maior, menor, soma/10);
    return 0;
}