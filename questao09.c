#include <stdio.h>
/*
    Ler um vetor com 15 posições, calcular e mostrar:
        i) o maior elemento do vetor e em que posição esse elemento se encontra
        ii) o menor elemento do vetor e em que posição esse elemento se encontra.
*/

#define ARRAY_SIZE 15

int main() {
    int array[ARRAY_SIZE];

    for (int i = 0; i < ARRAY_SIZE; i++) {
        printf("Digite o valor %d:\n> ", i+1);
        scanf("%d", &array[i]);
    }

    int min = array[0];
    int posMin = 0;
    int max = array[0];
    int posMax = 0;

    for (int i = 0; i < ARRAY_SIZE; i++) {
        if (array[i] < min) {
            min = array[i];
            posMin = i;
        }
        if (array[i] > max) {
            max = array[i];
            posMax = i;
        }
    }

    printf("\nO menor valor do vetor é: %d\n", min);
    printf("sua posição no vetor é: %d\n", posMin);
    printf("\nO maior valor do vetor é: %d\n", max);
    printf("sua posição é no vetor é: %d", posMax);

    return 0;
}