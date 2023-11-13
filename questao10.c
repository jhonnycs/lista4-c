#include <stdio.h>

/*
    Ler um vetor de 15 posições de números inteiros e multiplicar todos os elementos pelo 
    maior valor do vetor. Mostrar o vetor após os cálculos.
*/

#define ARRAY_SIZE 15

int main() {
    int array[ARRAY_SIZE];

    for (int i = 0; i < ARRAY_SIZE; i++) {
        printf("Digite o valor %d:\n> ", i+1);
        scanf("%d", &array[i]);
    }

    int max = array[0];
    for (int i = 0; i < ARRAY_SIZE; i++) {
        if (array[i] > max) {
            max = array[i];
        }
    }

    for (int i = 0; i < ARRAY_SIZE; i++) {
        array[i] = array[i] * max;
    }
    
    printf("Vetor após a multiplicação:\n");

    printf("\n[");
    for (int i = 0; i < ARRAY_SIZE; i++) {
        printf("%d%s", array[i], i+1==ARRAY_SIZE ? "]" : ", ");
    }
    
    
    return 0;
}