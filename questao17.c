#include <ctype.h>
#include <stdio.h>
#include <string.h>

/*
        Dada  uma  string  digitada  pelo  usuário, converta  a  primeira  letra
   de cada  palavra  para maiúscula.
*/

#define ARRAY_SIZE 100

void toUpperCase(char *string);

int main() {
    char string[ARRAY_SIZE];

    printf("Digite uma frase:\n> ");
    fgets(string, ARRAY_SIZE, stdin);

    toUpperCase(string);

    printf("\nFrase com a primeira letra de cada palavra em maiúsculo:\n");
    printf("%s", string);
    return 0;
}

void toUpperCase(char *string) {
    int tamanho = strlen(string);
    int maiuscula = 1;
    for (int i = 0; i < tamanho; i++) {
        if (isalpha(string[i])) {
            if (maiuscula) {
                string[i] = toupper(string[i]);
                maiuscula = 0;
            }
        } else {
            maiuscula = 1;
        }
    }
}