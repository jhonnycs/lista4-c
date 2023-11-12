#include <stdio.h>
#include <string.h>

/*
    Dada  uma  string  digitada  pelo  usuário, eliminar  os  espaços  em
    brancos repetidos (em seqüência).
*/

#define ARRAY_SIZE 101

void removerEnter(char *string);
void removerEspacosRepetidos(char *frase);

int main() {
    char frase[ARRAY_SIZE];

    printf("Digite uma sequência de palavras:\n");
    printf("(máximo de %d caracteres):\n> ", ARRAY_SIZE - 1);
    fgets(frase, ARRAY_SIZE, stdin);

    removerEnter(frase);

    removerEspacosRepetidos(frase);

    printf("Frase depois da remoção de espaços repetidos, caso houvesse:\n");
    printf("%s", frase);

    return 0;
}

void removerEnter(char *string) {
    int tamanho = strlen(string);

    if (string[tamanho - 1] == '\n') {
        string[tamanho - 1] = string[tamanho];
    }
}

void removerEspacosRepetidos(char *frase) {
    int tamanhoFrase = strlen(frase);

    for (int i = 0; i < tamanhoFrase - 1; i++) {
        if (frase[i] == ' ' && frase[i + 1] == ' ') {
            for (int j = i; j < tamanhoFrase; j++) {
                frase[j] = frase[j + 1];
            }
            tamanhoFrase--;
            i--;
        }
    }
}