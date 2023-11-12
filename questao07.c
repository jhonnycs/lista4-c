#include <stdio.h>

/*
    Dado um vetor com N números inteiros (máximo 10 elementos), ordenar
    crescentemente os números nesse vetor.
*/

void ordenarArray(int *array, int arraySize);
void lerQuantNumeros(int *quantNumeros);
void lerArray(int *array, int tamanho);
void mostrarArray(int *array, int quantNumeros);

int main() {
    int quantNumeros;
    int array[quantNumeros];

    lerQuantNumeros(&quantNumeros);
    lerArray(array, quantNumeros);

    printf("Array antes de ser ordenado:\n");
    mostrarArray(array, quantNumeros);

    ordenarArray(array, quantNumeros);

    printf("\n\nArray depois de ser ordenado:\n");
    mostrarArray(array, quantNumeros);

    return 0;
}

void lerQuantNumeros(int *quantNumeros) {
    int n;
    printf(
        "Digite quantos elementos você quer ordenar (máximo de 10 "
        "elementos):\n> ");
    scanf("%d", &n);

    while (n < 1 || n > 10) {
        printf("Por favor, digite uma quantidade válida (de 1 a 10):\n> ");
        scanf("%d", &n);
    }

    *quantNumeros = n;
}

void lerArray(int *array, int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        printf("Digite o elemento número %d:\n> ", i + 1);
        scanf("%d", &array[i]);
    }
}

void mostrarArray(int *array, int quantNumeros) {
    printf("[");
    for (int i = 0; i < quantNumeros; i++) {
        printf("%d%s", array[i], i + 1 == quantNumeros ? "]" : ", ");
    }
}

void ordenarArray(int *array, int arraySize) {
    for (int i = 1; i < arraySize; i++) {
        if (array[i - 1] > array[i]) {
            int aux = array[i];
            int j = i;
            while (j > 0 && array[j - 1] > array[j]) {
                array[j] = array[j - 1];
                array[j - 1] = aux;
                j--;
            }
        }
    }
}