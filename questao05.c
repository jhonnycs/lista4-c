#include <stdio.h>

/*
    Ler um vetor K(15) de valores inteiros não negativos.
    Criar, em seguida, um vetor P, que contenha todos os
    números primos de K. Escrever o vetor P na tela.
*/

#define K_P_SIZE 15

void inserirNoArray(int element, int* array);
void popularArrayPrimos(int* P);
void lerVetor(int* K);

int main() {
    int K[K_P_SIZE];
    int P[K_P_SIZE];

    popularArrayPrimos(P);

    lerVetor(K);

    for (int i = 0; i < K_P_SIZE; i++) {
        int isntPrime = 0;
        for (int j = 2; j <= K[i] / 2; j++) {
            if (K[i] % j == 0) {
                isntPrime = 1;
                break;
            }
        }

        if (!isntPrime && K[i] != 1) {
            inserirNoArray(K[i], P);
        }
    }

    printf("\nVetor com os números primos:\n[ ");
    for (int i = 0; i < K_P_SIZE; i++) {
        if (P[i] == -1) break;

        printf("%d%s", P[i], P[i + 1] == -1 ? " " : ", ");
    }
    printf("]");

    return 0;
}

void inserirNoArray(int element, int* array) {
    for (int i = 0; i < K_P_SIZE; i++) {
        if (array[i] == -1) {
            array[i] = element;
            break;
        }
    }
}

void popularArrayPrimos(int* P) {
    for (int i = 0; i < K_P_SIZE; i++) {
        P[i] = -1;
    }
}

void lerVetor(int* K) {
    for (int i = 0; i < K_P_SIZE; i++) {
        printf("Digite o elemento número %d:\n> ", i + 1);
        scanf("%d", &K[i]);

        while (K[i] < 0) {
            printf("Por favor, digite número positivo:\n> ");
            scanf("%d", &K[i]);
        }
    }
}