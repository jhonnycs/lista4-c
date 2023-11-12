#include <stdio.h>

/*
    Ler um vetor de 20 posições e mostrar. Em seguida, trocar o primeiro
    elemento com o último, o segundo com o penúltimo, o terceiro com o
    antepenúltimo, e assim sucessivamente. Mostrar o novo vetor depois da troca.
    Observação: deve-se usar apenas um vetor no algoritmo.

*/

int main() {
    int vetor[20];
    int vetorSize = sizeof(vetor) / sizeof(vetor[0]);

    for (int i = 0; i < vetorSize; i++) {
        printf("Digite o elemento número %d:\n> ", i + 1);
        scanf("%d", &vetor[i]);
    }

    printf("Vetor antes da troca:\n");
    printf("[");
    for (int i = 0; i < vetorSize; i++) {
        printf("%d%s", vetor[i], i+1 == vetorSize ? "]" : ", ");
    }

    for (int i = 0; i < vetorSize / 2; i++) {
        int aux = vetor[i];
        vetor[i] = vetor[vetorSize - i - 1];
        vetor[vetorSize - i - 1] = aux;
    }

    printf("\n\nVetor depois da troca:\n");
    printf("[");
    for (int i = 0; i < vetorSize; i++) {
        printf("%d%s", vetor[i], i+1 == vetorSize ? "]" : ", ");
    }

    return 0;
}