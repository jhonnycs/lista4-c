#include <stdio.h>

/*
    Ler um vetor K[30]. Trocar, em seguida, todos os elementos de ordem ímpar
    do vetor com os elementos de ordem par imediatamente posterior.
*/

int main() {
    int K[30];
    int kSize = sizeof(K) / sizeof(K[0]);

    for (int i = 0; i < kSize; i++) {
        printf("Digite o número %d:\n> ", i + 1);
        scanf("%d", &K[i]);
    }

    for (int i = 0; i < kSize-1; i++) {
        if (i % 2 == 1) {
            int aux = K[i];
            K[i] = K[i + 1];
            K[i + 1] = aux;
        }
    }

    for (int i = 0; i < kSize; i++) {
        printf("Elemento %d\n", K[i]);
    }

    return 0;
}