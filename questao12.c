#include <stdio.h>

/*
    Dadas  duas  sequências  com  n  números  inteiros  entre  0  e  9,
    interpretadas  como  dois  números  inteiros  de  n algarismos, calcular
    a seqüência de números que representa a soma dos dois inteiros.
    Exemplo: n = 8,  1ª seqüência     8 2 4 3 4 2 5 1
                     2ª seqüência  +  3 3 7 5 2 3 3 7
                                    -----------------
                                    1 1 6 1 8 6 5 8 8
*/

int main() {
    int numDigitos;

    printf("Digite o número de dígitos das sequências de números:\n> ");
    scanf("%d", &numDigitos);

    while (numDigitos < 1) {
        printf("Por favor, digite um número válido de dígitos:\n> ");
        scanf("%d", &numDigitos);
    }

    int num1[numDigitos];
    int num2[numDigitos];
    int res[numDigitos + 1];

    for (int i = 0; i < numDigitos; i++) {
        printf("Digite o dígito %d do número 1:\n> ", i + 1);
        scanf("%d", &num1[i]);
    }

    for (int i = 0; i < numDigitos; i++) {
        printf("Digite o dígito %d do número 2:\n> ", i + 1);
        scanf("%d", &num2[i]);
    }

    int carryIn = 0;
    for (int i = numDigitos - 1; i >= 0; i--) {
        if (num1[i] + num2[i] + carryIn <= 9) {
            res[i + 1] = num1[i] + num2[i] + carryIn;
            carryIn = 0;
        } else if (num1[i] + num2[i] + carryIn > 9) {
            res[i + 1] = num1[i] + num2[i] + carryIn - 10;
            carryIn = 1;

            if (i == 0) {
                res[i] = carryIn;
            }
        }
    }

    printf("\n    ");
    for (int i = 0; i < numDigitos; i++) {
        printf("%d ", num1[i]);
    }
    printf("\n  + ");

    for (int i = 0; i < numDigitos; i++) {
        printf("%d ", num2[i]);
    }
    printf("\n  %s", res[0] == 1 ? "-" : " ");

    for (int i = 0; i < numDigitos; i++) {
        printf("%s-", i == 0 && !(res[0] == 1) ? " " : "-");
    }
    printf("\n  ");

    if (res[0] == 1) {
        for (int i = 0; i < numDigitos + 1; i++) {
            printf("%d ", res[i]);
        }
    } else {
        printf("  ");
        for (int i = 1; i < numDigitos + 1; i++) {
            printf("%d ", res[i]);
        }
    }

    return 0;
}