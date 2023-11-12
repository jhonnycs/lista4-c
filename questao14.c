#include <stdio.h>

/*
    Dado pelo usuário uma sequência de n números inteiros, determinar um
    segmento de soma máxima. Ou seja, dentro de todos os segmentos (subarays
    sem pular nenhum número) possíveis de se formar com um array, busca-se
    determinar a maior soma que um determinado segmento entregará. Exemplo: Na
    sequência 5, 2, -2, -7, 3, 14, 10, -3, 9, -6, 4, 1 A soma do segmento é 33.
*/

void lerTamanhoSequencia(int *tamanho);
void lerArray(int *array, int tamanho);
int somarSegmentoMaximo(int *array, int tamanho);
int kadane(int *array, int tamanho);

int main() {
    int tamanho;
    lerTamanhoSequencia(&tamanho);

    int sequencia[tamanho];
    lerSequencia(sequencia, tamanho);

    int somaSegmento = somarSegmentoMaximo(sequencia, tamanho);
    printf("\nA soma do segmento de soma máxima é %d", somaSegmento);

    int somaSegmentoKadane = kadane(sequencia, tamanho);
    printf("\n\nUsando kadane, a soma máxima é %d", somaSegmentoKadane);

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

void lerArray(int *array, int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        printf("Digite o número %d:\n> ", i + 1);
        scanf("%d", &array[i]);
    }
}
// maneira mais intuitiva e menos eficiente
int somarSegmentoMaximo(int *array, int tamanho) {
    int maxSoma = array[0];
    for (int i = 0; i < tamanho; i++) {
        int somaTemp = 0;
        for (int j = i; j < tamanho; j++) {
            somaTemp = somaTemp + array[j];
            if (maxSoma < somaTemp) {
                maxSoma = somaTemp;
            }
        }
    }
    return maxSoma;
}
// algoritmo mais eficiente, porém menos intuitivo
int kadane(int *array, int tamanho) {
    int maxSoma = array[0];
    int somaAtual = 0;
    for (int i = 0; i < tamanho; i++) {
        somaAtual = somaAtual + array[i];
        if (array[i] > somaAtual) {
            somaAtual = array[i];
        }
        if (somaAtual > maxSoma) {
            maxSoma = somaAtual;
        }
    }
    return maxSoma;
}