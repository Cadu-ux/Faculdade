#include <stdio.h>
int main() {
    int n, t1 = 0, t2 = 1, prox, i;
    printf("Quantos termos exibir? ");
    scanf("%d", &n);

    for (i = 1; i <= n; ++i) {
        printf("%d, ", t1);
        prox = t1 + t2;
        t1 = t2;
        t2 = prox;
    }
    printf("...\n");
    return 0;
}