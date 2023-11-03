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

#define arrySize 5

int main() {
    int n;
    int vetor[arrySize];

    printf("Digite o número para tomar uma ação:");
    printf("0- finalizar o programa;");
    printf("1- mostrar o vetor na ordem como ele foi lido;");
    printf("2- mostrar o vetor na ordem inversa, do último até o primeiro;");
    printf("3- apresentar a mediana do vetor;");
    printf("4- informar o produto dos 50 números;");
    printf("5- mostrar a porcentagem dos valores que são pares positivos;");
    printf("6- mostrar os números ímpares e sua soma;");
    printf("7- se possui números repetidos (e quais são).");
    printf("\n> ");

    scanf("%d", &n);

    while (n < 0 || n > 7) {
        printf("Por favor, digite uma opção válida:");
        scanf("%d", &n);
    }
    
    switch (n) {
    case 1:
        break;
    case 2:
        break;
    case 3:
        break;
    case 4:
        break;
    case 5:
        break;
    case 6:
        break;
    case 7:
        break;
    }

    return 0;
}