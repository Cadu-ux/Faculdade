#include <stdio.h>
int main() {
int n, soma = 0;
while(n!=0){
    printf("Digite um numero: ");
    scanf("%d", &n);
    if(n % 2 == 0){
        soma = soma + n ;
    }
} printf("A soma dos numeros pares digitados é %d.", soma);
    return 0;
}