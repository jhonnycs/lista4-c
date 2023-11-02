#include <stdio.h>

/*
    Ler um vetor de 20 posições e mostrar. Em seguida, trocar o primeiro elemento com o
    último, o segundo com o penúltimo, o terceiro com o antepenúltimo, e assim sucessivamente.
    Mostrar o novo vetor depois da troca.
    Observação: deve-se usar apenas um vetor no algoritmo.

*/

int main() {
    int vetor[20];
    int vetorSize = sizeof(vetor) / sizeof(vetor[0]);

    for (int i = 0; i < vetorSize; i++) {
        printf("Digite o número %d:\n> ", i);
        scanf("%d", &vetor[i]);
    }

    printf("Vetor antes da troca:\n\n");
    for (int i = 0; i < vetorSize; i++) {
        printf("%d\n", vetor[i]);
    }

    for (int i = 0; i < vetorSize; i++) {
        if (i >= vetorSize / 2) break;

        int aux = vetor[i];
        vetor[i] = vetor[vetorSize-i-1];
        vetor[vetorSize-i-1] = aux;

    }
    
    printf("\nVetor depois da troca:\n\n");
    for (int i = 0; i < vetorSize; i++) {
        printf("%d\n", vetor[i]);
    }
        
    return 0;
}