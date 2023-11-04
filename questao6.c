#include <stdio.h>

/*
    Ler um número inteiro N e um vetor de 50 posições de números. Se o número for:
    0- finalizar o programa;
    1- mostrar o vetor na ordem como ele foi lido;
    2- mostrar o vetor na ordem inversa, do último até o primeiro;
    3- apresentar a mediana do vetor;
    4- informar o produto dos 50 números;
    5- mostrar a porcentagem dos valores que são pares positivos;
    6- mostrar os números ímpares e sua soma;
    7- dizer se possui números repetidos (e quais são).
*/

void showArray();
void showOptions();
void readOption(int *opt);
void showReverseArray(int *vetor);
void showMediana(int *vetor);
int product(int *vetor);
int percentageEvenNumbers(int *vetor);
void showOddNumbers();
int sumOddNumbers(int *vetor);

#define ARRAY_SIZE 5

int main() {
    int opt;
    int vetor[ARRAY_SIZE];
    showOptions();

    readOption(&opt);

    switch (opt) {
    case 0:
        printf("Programa finalizado");
        break;
    case 1:
        showArray(vetor);
        break;
    case 2:
        showReverseArray(vetor);
        break;
    case 3:
        showMediana(vetor);
        break;
    case 4:
        printf("Produto de todos os valores: %d", product(vetor));
        break;
    case 5:
        printf("Porcentagem de valores pares positivos: %d", percentageEvenNumbers(vetor));
        break;
    case 6:
        printf("Números ímpares:\n");
        showOddNumbers(vetor);
        printf("Soma de todos os números ímpares: %d", sumOddNumbers(vetor));
        break;
    case 7:

        break;
    }

    return 0;
}

void showArray(int *vetor) {
    for (int i = 0; i < ARRAY_SIZE; i++) {
        printf("Elemento %d: %d", i, vetor[i]);
    }
}

void showOptions() {
    printf("\nDigite o número para tomar uma ação:\n");
    printf("0- finalizar o programa;\n");
    printf("1- mostrar o vetor na ordem como ele foi lido;\n");
    printf("2- mostrar o vetor na ordem inversa, do último até o primeiro;\n");
    printf("3- apresentar a mediana do vetor;\n");
    printf("4- informar o produto dos 50 números;\n");
    printf("5- mostrar a porcentagem dos valores que são pares positivos;\n");
    printf("6- mostrar os números ímpares e sua soma;\n");
    printf("7- se possui números repetidos (e quais são).\n");
    printf("\n> ");   
}

void readOption(int *opt) {
    int n;
    scanf("%d", &n);

    while (n < 0 || n > 7) {
        printf("Por favor, digite uma opção válida:");
        scanf("%d", &n);
    }
    *opt = n;
}

void showReverseArray(int *vetor) {
    for (int i = 0; i < ARRAY_SIZE / 2; i++) {
        int aux = vetor[i];
        vetor[i] = vetor[ARRAY_SIZE-i];
        vetor[ARRAY_SIZE-i] = aux;
    }
}

void showMediana(int *vetor) {
    int mediana;
    if (ARRAY_SIZE % 2 == 0) {
        mediana = (vetor[ARRAY_SIZE / 2 - 1] + vetor[ARRAY_SIZE/2]) / 2;
    } else {
        mediana = vetor[ARRAY_SIZE / 2];
    }
}

int product(int *vetor) {
    int result = 1;

    for (int i = 0; i < ARRAY_SIZE; i++) {
        result = result * vetor[i];
    }

    return result;
}

int percentageEvenNumbers(int *vetor) {
    float quantNums = 0.0;
    for (int i = 0; i < ARRAY_SIZE; i++) {
        if (vetor[i] % 2 == 0 && vetor[i] > 0) quantNums++;
    }
    return quantNums / (float)ARRAY_SIZE * 100;
}

void showOddNumbers(int *vetor) {
    for (int i = 0; i < ARRAY_SIZE; i++) {
        if (vetor[i] % 2 == 1) {
            printf("%d\n", vetor[i]);
        }
    }   
}

int sumOddNumbers(int *vetor) {
    int sum = 0;
    for (int i = 0; i < ARRAY_SIZE; i++) {
        sum = sum + vetor[i];
    }
    return sum;
}
