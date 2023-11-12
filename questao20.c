#include <stdio.h>
#include <string.h>

/*
    Ler uma frase (uma sequência de palavras separadas por espaços em branco) de
    até 100 caracteres e determinar a palavra mais longa na frase. Considerar
    que as palavras na frase são compostas apenas por letras (maiúsculas e
    minúsculas) e espaços em branco. Se houver duas ou mais palavras com o mesmo
    comprimento máximo, imprimir apenas a primeira palavra encontrada com esse
    comprimento.
*/

#define ARRAY_SIZE 102

void removerEnter(char *string);
void addEspacoFinal(char *string);
void exibirMaiorPalavra(char *frase);

int main() {
    char frase[ARRAY_SIZE];

    printf("Digite uma frase de até 100 caracteres:\n> ");
    fgets(frase, ARRAY_SIZE - 1, stdin);

    removerEnter(frase);
    addEspacoFinal(frase);

    exibirMaiorPalavra(frase);
    return 0;
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

void exibirMaiorPalavra(char *frase) {
    int tamanhoFrase = strlen(frase);

    int tamanhoPalavraTemp = 0;
    int indexInicialTemp = 0;

    int tamanhoMaiorPalavra = 0;
    int indexInicial = 0;

    for (int i = 0; i < tamanhoFrase; i++) {
        if (frase[i] == ' ') {
            if (tamanhoMaiorPalavra < tamanhoPalavraTemp) {
                indexInicial = indexInicialTemp;
                tamanhoMaiorPalavra = tamanhoPalavraTemp;
            }
            indexInicialTemp = i + 1;
            tamanhoPalavraTemp = 0;
        }
        tamanhoPalavraTemp++;
    }
    if (indexInicial > 0) tamanhoMaiorPalavra--;

    char maiorPalavra[tamanhoMaiorPalavra + 1];
    maiorPalavra[tamanhoMaiorPalavra] = '\0';
    for (int i = 0; i < tamanhoMaiorPalavra; i++) {
        maiorPalavra[i] = frase[i + indexInicial];
    }

    printf("A maior palavra é \"%s\"\n", maiorPalavra);
    printf("ela possui %d letras", tamanhoMaiorPalavra);
}