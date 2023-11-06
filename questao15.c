#include <stdio.h>

/*
    Dada uma string digitada pelo usuário, identificar
    palíndromos. Exemplos de palíndromos: ovo, arara, seres, ...
*/

#define ARRAY_SIZE 30
int verificarPalindromo(char *palavra);

int main() {
    char palavra[ARRAY_SIZE];
    printf("Digite uma palavra:\n> ");
    scanf("%s", palavra);

    if (verificarPalindromo(palavra)) {
        printf("A palavra é palíndromo");
    } else {
        printf("A palavra não é palíndromo");
    }
    return 0;
}

int verificarPalindromo(char *palavra) {
    char palavra1[ARRAY_SIZE], palavra2[ARRAY_SIZE];
    int tamanhoPalavra = sizeof(palavra);

    for (int i=0; i<tamanhoPalavra; i++) {
        palavra1[i] = palavra[i];
        palavra2[i] = palavra[tamanhoPalavra-i-1];
    }

    if (palavra1==palavra2) {
        return 1;
    } else {
        return 0;
    }
}
