#include <stdio.h>
int main () {
    int horas, minutos,tempoPassado;
    
    printf("Digite o numero de horas: ");
    scanf("%d", &horas);
    printf("Digite o numero de minutos: ");
    scanf("%d", &minutos);
    tempoPassado = (horas * 60) + minutos;
    printf("Desde o inicio do dia passaram %d minutos", tempoPassado);
    
    return 0;
}