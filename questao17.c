#include <ctype.h>
#include <stdio.h>
#include <string.h>

/*
    Dada  uma  string  digitada  pelo  usuário, converta  a  primeira  letra
    de cada  palavra para maiúscula.
*/

#define ARRAY_SIZE 100

void toUpperCase(char *string);

int main() {
    char string[ARRAY_SIZE];

    printf("Digite uma frase (máximo de %d caracteres):\n> ", ARRAY_SIZE-1);
    fgets(string, ARRAY_SIZE, stdin);

    toUpperCase(string);

    printf("\nFrase com a primeira letra de cada palavra em maiúsculo:\n");
    printf("%s", string);
    return 0;
}

void toUpperCase(char *string) {
    int tamanho = strlen(string);
    int minuscula = 1;
    for (int i = 0; i < tamanho; i++) {
        if (isalpha(string[i])) {
            if (minuscula) {
                string[i] = toupper(string[i]);
                minuscula = 0;
            }
        } else {
            minuscula = 1;
        }
    }
}