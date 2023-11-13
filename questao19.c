#include <stdio.h>
#include <string.h>

/*
    Dados  dois  strings  (um  contendo  uma  frase  e  outro  contendo  uma
    palavra),  determinar  o  número  de  vezes  que  a palavra ocorre na frase.
    Exemplo: Para a palavra ANA e a frase “ANA E MARIANA GOSTAM DE BANANA.”
    Saída: Temos que a palavra ocorre 4 vezes na frase.
*/

#define FRASE_SIZE 200
#define PALAVRA_SIZE 40

int contarPalavras(char *palavra, char *frase);
void removerEnter(char *string);

int main() {
    char frase[FRASE_SIZE];
    char palavra[PALAVRA_SIZE];

    printf("Digite a frase para analisar (máximo de %d caracteres):\n> ", FRASE_SIZE-1);
    fgets(frase, FRASE_SIZE, stdin);
    printf("\nDigite a palavra para contá-la na frase (máximo de %d caracteres):\n> ", PALAVRA_SIZE-1);
    fgets(palavra, PALAVRA_SIZE, stdin);

    removerEnter(frase);
    removerEnter(palavra);

    int quantPalavras = contarPalavras(palavra, frase);

    printf("\nA palavra %s apareceu %d vezes na frase.", palavra,
           quantPalavras);

    return 0;
}

void removerEnter(char *string) {
    int tamanho = strlen(string);

    if (string[tamanho - 1] == '\n') {
        string[tamanho - 1] = string[tamanho];
    }
}

int contarPalavras(char *palavra, char *frase) {
    int tamanhoPalavra = strlen(palavra);
    int tamanhoFrase = strlen(frase);

    int quantPalavras = 0;
    for (int i = 0; i < tamanhoFrase - tamanhoPalavra + 1; i++) {
        int coincidiu = 1;

        for (int j = 0; j < tamanhoPalavra - 1; j++) {
            if (frase[i + j] != palavra[j]) {
                coincidiu = 0;
                break;
            }
        }
        if (coincidiu) quantPalavras++;
    }
    return quantPalavras;
}