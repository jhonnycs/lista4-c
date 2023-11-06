#include <stdio.h>
#include <string.h>

/*
    Dados  dois  strings  (um  contendo  uma  frase  e  outro  contendo  uma
    palavra),  determinar  o  número  de  vezes  que  a palavra ocorre na frase.
    Exemplo: Para a palavra ANA e a frase “ANA E MARIANA GOSTAM DE BANANA.”
    Saída: Temos que a palavra ocorre 4 vezes na frase.
*/

#define FRASE_SIZE 500
#define PALAVRA_SIZE 40

int contarPalavras(char *palavra, char *frase);
int contarPalavras2(char *palavra, char *frase);

int main() {
    char frase[FRASE_SIZE];
    char palavra[PALAVRA_SIZE];

    printf("Digite a frase para analisar:\n> ");
    fgets(frase, FRASE_SIZE, stdin);
    printf("\nDigite a palavra para contá-la na frase:\n> ");
    fgets(palavra, PALAVRA_SIZE, stdin);

    int quantPalavras = contarPalavras(palavra, frase);

    frase[strcspn(frase, "\n")] = '\0';
    palavra[strcspn(palavra, "\n")] = '\0';

    printf("\nA palavra %s apareceu %d vezes na frase.", palavra,
           quantPalavras);

    quantPalavras = contarPalavras2(palavra, frase);

    printf("A palavra %s apareceu %d vezes na frase.", palavra, quantPalavras);

    return 0;
}

int contarPalavras(char *palavra, char *frase) {
    int tamanhoPalavra = strlen(palavra);
    int tamanhoFrase = strlen(frase);
    int quantPalavras = 0;
    for (int i = 0; i < tamanhoFrase - tamanhoPalavra; i++) {
        int coincidiu = 1;

        for (int j = 0; j < tamanhoPalavra; j++) {
            if (frase[i + j] != palavra[j]) {
                coincidiu = 0;
                break;
            }
        }

        if (coincidiu) quantPalavras++;
    }
    return quantPalavras;
}

int contarPalavras2(char *palavra, char *frase) {
    int quantPalavras = 0;
    char *posicao = frase;

    while ((posicao = strstr(posicao, palavra)) != NULL) {
        quantPalavras++;
        posicao += strlen(palavra);
    }

    return quantPalavras;
}