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

#define ARRAY_SIZE 100

void buscarMaiorPalavra(char *frase, char *maiorPalavra);

int main() {
    char frase[ARRAY_SIZE];

    printf("Digite uma frase de até 100 caracteres:\n> ");
    fgets(frase, ARRAY_SIZE, stdin);

    char maiorPalavra[ARRAY_SIZE];

    buscarMaiorPalavra(frase, maiorPalavra);
    return 0;
}

void buscarMaiorPalavra(char *frase, char *maiorPalavra) {
    char maiorPalavraTemp[ARRAY_SIZE];
    int tamanhoFrase = strlen(frase);
    int tamanhoPalavraTemp = 0;
    int tamanhoMaiorPalavra = 0;
    int in, fi;

    for (int i = 0; i < tamanhoFrase; i++) {
        }

    printf("%d", tamanhoMaiorPalavra);
}