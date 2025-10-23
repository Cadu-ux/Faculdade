#include <stdio.h> 
int main () {
    int n1 = 1;
    int n2 = 2;
    int n3 = 3;
    if (n1 > n2 && n1 > n3) {
        printf ("%d eh o maior numero entre os apresentados", n1);
    }
    if (n2 > n1 && n2 > n3) {
        printf ("%d eh o maior numero entre os apresentados", n2);
    }
    else {
        printf ("%d eh o maior numero entre os apresentados", n3);
    }
    return 0;
}