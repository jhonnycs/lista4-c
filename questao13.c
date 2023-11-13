#include <stdio.h>

/*
    Dado pelo usuário uma seqüência de n números reais, determinar os números
    que compõem a seqüência e a quantidade de vezes que cada um ocorre na
    mesma. Exemplo:
    n = 8
    Seqüência: -1.7, 3.0, 0.0, 1.5, 0.0, -1.7, 2.3, -1.7
    Saída: -1.7 ocorre 3 vezes
            3.0 ocorre 1 vezes
            0.0 ocorre 2 vezes
            1.5 ocorre 1 vezes
            2.3 ocorre 1 vezes

*/

void ordenarArray(float *array, int arraySize);
void lerTamanhoSequencia(int *tamanho);
void lerArray(float *array, int tamanho);
void contarOcorrencias(float *array, int tamanho);

int main() {
    int quantValores;
    lerTamanhoSequencia(&quantValores);

    float sequencia[quantValores];
    lerArray(sequencia, quantValores);

    ordenarArray(sequencia, quantValores);

    contarOcorrencias(sequencia, quantValores);

    return 0;
}

void lerTamanhoSequencia(int *tamanho) {
    int n;
    printf("Digite o número de dígitos da sequência de números:\n> ");
    scanf("%d", &n);

    while (n < 1) {
        printf("Por favor, digite um número válido de dígitos:\n> ");
        scanf("%d", &n);
    }

    *tamanho = n;
}

void lerArray(float *array, int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        printf("Digite o número %d:\n> ", i + 1);
        scanf("%f", &array[i]);
    }
}

void ordenarArray(float *array, int arraySize) {
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

void contarOcorrencias(float *array, int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        int quantOcorrencias = 0;

        for (int j = 0; j < tamanho; j++) {
            if (array[i] == array[j]) {
                quantOcorrencias++;
            }
        }

        printf("\nO número %.2f ocorre %d vezes", array[i], quantOcorrencias);
        i += quantOcorrencias - 1;
    }
}