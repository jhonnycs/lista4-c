#include <stdio.h>
#include <string.h>

/*
    Dada  uma  string  digitada  pelo  usuário, eliminar  os  espaços  em
    brancos repetidos (em seqüência).
*/

#define ARRAY_SIZE 70

void removerEspacos(char *frase);

int main() {
    char frase[ARRAY_SIZE];

    printf("Digite uma sequência de palavras:\n> ");
    fgets(frase, ARRAY_SIZE, stdin);

    printf("Antes da remoção dos espaços:\n");
    printf("%s\n", frase);

    removerEspacos(frase);

    printf("Depois da remoção dos espaços:\n");
    printf("%s", frase);

    return 0;
}

void removerEspacos(char *frase) {
    int tamanhoFrase = strlen(frase);
    for (int i = 0; i < tamanhoFrase - 1; i++) {
        if (frase[i] == ' ' && frase[i + 1] == ' ') {
            for (int j = i; j < tamanhoFrase - 1; j++) {
                frase[j] = frase[j + 1];
            }
            tamanhoFrase--;
            i--;
        }
    }
}