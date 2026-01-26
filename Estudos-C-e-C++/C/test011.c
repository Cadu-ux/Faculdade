#include <stdio.h>
int n1,n2,n3;
float media;
int main() {
printf("Insira um numero: ");
scanf("%d", &n1);
printf("Insira outro numero: ");
scanf("%d", &n2);
printf("Insira mais um numero: ");
scanf("%d", &n3);
media = (n1 + n2 + n3) / 3 ;
printf("A media dos numeros eh: %.1f", media);
return 0;
}