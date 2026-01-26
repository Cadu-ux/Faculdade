#include <stdio.h>
int main() {
int A,B,C;
printf("Insira o valor do lado A: ");
scanf("%d", &A);
printf("Insira o valor do lado B: ");
scanf("%d", &B);
printf("Insira o valor do lado C: ");
scanf("%d", &C);
if (A + B < C || B + C < A || A + C < B){
    printf("Nao eh um triangulo ");
} else if (A == B && A == C){
    printf("eh equilatero");
} else if(A == B || A == C || C == B){
    printf("eh isosceles");
} else if (A != B && A != C){
    printf("eh escaleno");
}


    return 0;
}