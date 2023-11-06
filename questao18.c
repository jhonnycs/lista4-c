#include <stdio.h>
#include <string.h>

/*
    Ler uma frase e contar quantas palavras existem na frase.
*/

#define ARRAY_SIZE 200
int contarPalavras(char *frase);

int main() {
    char frase[ARRAY_SIZE];

    printf("Digite uma frase:\n> ");
    fgets(frase, ARRAY_SIZE, stdin);

    int quantPalavras = contarPalavras(frase);

    printf("Há %d palavras na frase digitada.", quantPalavras);

    return 0;
}

int contarPalavras(char *frase) {
    int tamanho = strlen(frase);
    int counter = 0;
    for (int i = 0; i < tamanho; i++) {
        if (frase[i] == ' ' ||
            (frase[i] == '!' || frase[i] == '.' || frase[i] == '?')) {
            counter++;
        }
    }
    return counter;
}