#include <math.h>
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
int estaNoArray(float num, float *vetor, int tamanho);
void popularArray(float num, float *array, int tamanho);

int main() {
    int quantValores;
    float sequencia[quantValores];
    float sequenciaSemRepeticao[quantValores];
    int totalOcorrencias[quantValores];

    printf("Digite o número de dígitos das sequências de números:\n> ");
    scanf("%d", &quantValores);

    while (quantValores < 1) {
        printf("Por favor, digite um número válido de dígitos:\n> ");
        scanf("%d", &quantValores);
    }

    for (int i = 0; i < quantValores; i++) {
        printf("Digite o número %d:\n> ", i + 1);
        scanf("%f", &sequencia[i]);
        totalOcorrencias[i] = -1;
    }

    popularArray(M_PI, sequenciaSemRepeticao, quantValores);

    for (int i = 0; i < quantValores; i++) {
        int quantOcorrencias = 0;

        for (int j = 0; j < quantValores; j++) {
            if (sequencia[i] == sequencia[j]) {
                quantOcorrencias++;
            }
        }

        if (!estaNoArray(sequencia[i], sequencia, quantValores)) {
            for (int j = 0; j < quantValores; j++) {
                if (sequenciaSemRepeticao[j] == (float)M_PI) {
                    sequenciaSemRepeticao[j] = sequencia[i];
                }
                if (totalOcorrencias[j] == -1) {
                    totalOcorrencias[j] = quantOcorrencias;
                    break;
                }
            }
        }
    }

    for (int i = 0; i < quantValores; i++) {
        printf("%.2f %d", sequenciaSemRepeticao[i], totalOcorrencias[i]);
        if (sequenciaSemRepeticao[i] != M_PI && totalOcorrencias[i] != -1) {
            printf("\nO número %.2f ocorre %d vezes", sequencia[i],
                   totalOcorrencias[i]);
        } else {
            break;
        }
    }

    return 0;
}

void popularArray(float num, float *array, int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        array[i] = num;
    }
}

int estaNoArray(float num, float *vetor, int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        if (num == vetor[i]) return 1;
    }
    return 0;
}