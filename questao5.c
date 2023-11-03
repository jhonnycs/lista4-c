#include <stdio.h>

/*
    Ler um vetor K(15) de valores inteiros não negativos.
    Criar, em seguida, um vetor P, que contenha todos os
    números primos de K. Escrever o vetor P na tela.
*/

void insertInArray(int element, int* array);

#define K_P_SIZE 15

int main() {
    int K[K_P_SIZE];
    int P[K_P_SIZE];

    for (int i = 0; i < K_P_SIZE; i++) {
        P[i] = -1;
    }

    for (int i = 0; i < K_P_SIZE; i++) {
        printf("Digite o valor %d:\n> ", i+1);
        scanf("%d", &K[i]);

        while (K[i] < 0) {
            printf("Por favor, digite número positivo:\n> ");
            scanf("%d", &K[i]);
        }
    }

    for (int i=0; i<K_P_SIZE; i++) {
        int isntPrime = 0;
        for (int j = 2; j <= K[i]/2; j++) {
            if (K[i] % j == 0) {
                isntPrime = 1;
                break;
            }
        }

        if (!isntPrime && K[i] != 1) {
            insertInArray(K[i], P);
        }
    }

    printf("\nVetor com os números primos:\n[ ");
    for (int i = 0; i < K_P_SIZE; i++) {
        if (P[i] == -1) break;

        printf("%d%s", P[i], P[i+1] == -1 ? " " : ", ");
    }
    printf("]");

    return 0;
}

void insertInArray(int element, int* array) {
    for (int i = 0; i < K_P_SIZE; i++) {
        if (array[i] == -1) {
            array[i] = element;
            break;
        }       
    }
}