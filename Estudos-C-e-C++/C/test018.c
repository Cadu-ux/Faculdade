#include <ctype.h>
#include <stdio.h>
int main() {
    char frase[100];
    int i, vogais = 0;
    
    printf("Digite uma frase: ");
    scanf(" "); // Limpa buffer
    scanf("%[^\n]", frase);

    for(i=0; frase[i] != '\0'; i++) {
        char c = tolower(frase[i]);
        if(c=='a'||c=='e'||c=='i'||c=='o'||c=='u') 
            vogais++;
    }
    printf("Total de vogais: %d\n", vogais);
    return 0;
}