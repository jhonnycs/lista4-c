#include <stdio.h>
#include <string.h>

/*
    Ler uma frase e contar quantas palavras existem na frase.
*/

#define ARRAY_SIZE 200
void addEspacoFinal(char *string);
void removerEnter(char *string);
void removerEspacosRepetidos(char *frase);
int contarPalavras(char *frase);

int main() {
    char frase[ARRAY_SIZE];

    printf("Digite uma frase (máximo de %d caracteres):\n> ", ARRAY_SIZE-2);
    fgets(frase, ARRAY_SIZE - 1, stdin);

    removerEspacosRepetidos(frase);
    removerEnter(frase);
    addEspacoFinal(frase);

    int quantPalavras = contarPalavras(frase);

    printf("Há %d palavras na frase digitada.", quantPalavras);

    return 0;
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

void removerEnter(char *string) {
    int tamanho = strlen(string);

    if (string[tamanho - 1] == '\n') {
        string[tamanho - 1] = string[tamanho];
    }
}

void addEspacoFinal(char *string) {
    int tamanho = strlen(string);

    if (string[tamanho - 1] != ' ') {
        string[tamanho] = ' ';
        string[tamanho + 1] = '\0';
    }
}
int contarPalavras(char *frase) {
    int tamanho = strlen(frase);
    int counter = 0;
    for (int i = 0; i < tamanho; i++) {
        if (frase[i] == ' ') {
            counter++;
        }
    }
    return counter;
}