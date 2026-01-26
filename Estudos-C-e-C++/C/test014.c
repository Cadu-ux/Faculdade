int main() {
    int n, i, divisores = 0;
    printf("Digite um numero positivo: ");
    scanf("%d", &n);

    for (i = 1; i <= n; i++) {
        if (n % i == 0) divisores++;
    }

    if (divisores == 2) // Divisível apenas por 1 e por ele mesmo
        printf("%d é PRIMO.\n", n);
    else
        printf("%d NÃO é primo.\n", n);
    return 0;
}