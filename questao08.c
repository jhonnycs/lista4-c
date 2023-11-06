#include <stdio.h>
#include <math.h>

/*
    Ler um vetor A de dimensão 20. Calcular e imprimir o valor de S, onde:
    S = (A1 - A20)² + (A2 - A19)² + ... + (A10 - A11)²
*/

#define ARRAY_SIZE 20

int main() {
    int A[ARRAY_SIZE];
    int S = 0;

    for (int i = 0; i < ARRAY_SIZE; i++) {
        printf("Digite o valor %d:\n> ", i+1);
        scanf("%d", &A[i]);
    }

    for (int i = 0; i < ARRAY_SIZE/2; i++) {
        S = S + pow(A[i] - A[ARRAY_SIZE-i-1], 2);
    }

    printf("\nO resultado de S é %d", S);

    return 0;
}