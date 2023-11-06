#include <stdio.h>

/*
    Dado um vetor com N números inteiros (máximo 10 elementos), ordenar crescentemente os 
    números nesse vetor.
*/

int main() {
    int quantNumeros;

    printf("Digite quantos elementos você quer ordenar (máximo de 10 elementos):\n> ");
    scanf("%d", &quantNumeros);

    while (quantNumeros < 1 || quantNumeros > 10) {
        printf("Por favor, digite uma quantidade válida (de 1 a 10):\n> ");
        scanf("%d", &quantNumeros);
    }
    
    int array[quantNumeros];

    for (int i = 0; i < quantNumeros; i++) {
        printf("Digite o número %d:\n> ", i+1);
        scanf("%d", &array[i]);
    }

    printf("Array antes de ser ordenado:\n");
    for (int i = 0; i < quantNumeros; i++) {
        printf("%d%s", array[i], i == quantNumeros ? "]" : ", ");
    }

    for (int i = 1; i < quantNumeros; i++) {
        if (array[i-1] > array[i]) {
            int aux = array[i];
            int j = i;
            while (j > 0 && array[j-1] > array[j])  {
                array[j] = array[j-1];
                array[j-1] = aux;
                j--;
            }
        }
    }

    printf("\n\nArray depois de ser ordenado:\n[");
    for (int i = 0; i < quantNumeros; i++) {
        printf("%d%s", array[i], i == quantNumeros ? "]" : ", ");
    }

    return 0;
}