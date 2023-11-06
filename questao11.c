#include <stdio.h>

/*
    Ler dois vetores A e B de 10 posições com números inteiros. 
    Subtrair o primeiro elemento de A do último de B,
    subtrair o segundo elemento de A do penúltimo e assim por diante,
    acumulando o resultado em um terceiro vetor C, que deve ser impresso.
*/

#define ARRAYS_SIZE 10

int main() {
    int A[ARRAYS_SIZE], B[ARRAYS_SIZE], C[ARRAYS_SIZE];

    for (int i = 0; i < ARRAYS_SIZE; i++) {
        printf("Digite o elemento %d do array A:\n> ", i+1);
        scanf("%d", &A[i]);
    }
    
    for (int i = 0; i < ARRAYS_SIZE; i++) {
        printf("Digite o elemento %d do array B:\n> ", i+1);
        scanf("%d", &B[i]);
    }

    for (int i = 0; i < ARRAYS_SIZE; i++) {
        C[i] = A[i] - B[ARRAYS_SIZE-i-1];
    }
    
    printf("\n[");
    for (int i = 0; i < ARRAYS_SIZE; i++) {
        printf("%d%s", C[i], i+1 == ARRAYS_SIZE ? "]" : ", ");
    }
    
    return 0;
}