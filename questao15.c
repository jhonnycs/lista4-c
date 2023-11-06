#include <stdio.h>
#include <string.h>

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

    verificarPalindromo(palavra);

    return 0;
}

int verificarPalindromo(char *palavra) {
    int tamanhoPalavra = strlen(palavra);

    for (int i = 0; i < tamanhoPalavra; i++) {
        if (palavra[i] != palavra[tamanhoPalavra - i - 1]) {
            printf("A palavra %s não é palíndromo", palavra);
            return 0;
        }
    }
    printf("A palavra %s é palíndromo", palavra);
    return 1;
}
