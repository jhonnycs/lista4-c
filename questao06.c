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

void mostrarArray();
void mostrarOpcoes();
void lerOpcao(int *opt);
void mostrarArrayReverso(int *vetor);
void mostrarMediana(int *vetor);
int produtoTodosOsNumeros(int *vetor);
float porcentagemPares(int *vetor);
int verificaSeAindaHaImpar(int iteradorAtual, int *vetor);
void mostrarImpares();
int somaDosImpares(int *vetor);
void numerosRepetidos(int *vetor, float *vetorNumerosRepetidos);
void mostrarArrayComRepetidos(float *vetorNumerosRepetidos);
void preencherArray(int *vetor);
void inserirNoArray(float element, float *array);

#define ARRAY_SIZE 4
float valorGenerico = 0.1;

int main() {
    int opt;
    int vetor[ARRAY_SIZE];
    mostrarOpcoes();

    lerOpcao(&opt);

    if (opt > 0) {
        preencherArray(vetor);
    }

    switch (opt) {
    case 0:
        printf("Finalizando programa");
        break;
    case 1:
        mostrarArray(vetor);
        break;
    case 2:
        mostrarArrayReverso(vetor);
        break;
    case 3:
        mostrarMediana(vetor);
        break;
    case 4:
        printf("Produto de todos os valores: %d", produtoTodosOsNumeros(vetor));
        break;
    case 5:
        printf("Porcentagem de valores pares positivos: %.1f%%", porcentagemPares(vetor));
        break;
    case 6:
        printf("Números ímpares:\n");
        mostrarImpares(vetor);
        printf("Soma de todos os números ímpares: %d", somaDosImpares(vetor));
        break;
    case 7:
        float vetorNumerosRepetidos[ARRAY_SIZE];
        numerosRepetidos(vetor, vetorNumerosRepetidos);
        float valorGenerico = 0.1;
        if (vetorNumerosRepetidos[0] != valorGenerico) {
            printf("O array digitado possui números repetidos. São eles:\n");
            mostrarArrayComRepetidos(vetorNumerosRepetidos);
        } else {
            printf("O vetor digitado não possui números repetidos.\n");
        }
        break;
    }

    return 0;
}

void mostrarOpcoes() {
    printf("\nDigite o número para tomar uma ação (você poderá digitar o vetor logo em seguida):\n");
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

void lerOpcao(int *opt) {
    int n;
    scanf("%d", &n);

    while (n < 0 || n > 7) {
        printf("Por favor, digite uma opção válida:");
        scanf("%d", &n);
    }
    *opt = n;
}

void preencherArray(int *vetor) {
    for (int i = 0; i < ARRAY_SIZE; i++) {
        printf("Digite o valor %d:\n> ", i+1);
        scanf("%d", &vetor[i]);
    }
    printf("\n");
}

void mostrarArray(int *vetor) {
    for (int i = 0; i < ARRAY_SIZE; i++) {
        printf("%d ", vetor[i]);
    }
}

void mostrarArrayReverso(int *vetor) {
    for (int i = ARRAY_SIZE-1; i >= 0; i--) {
        printf("%d ", vetor[i]);
    }
}

void ordenarArray(int *vetor) {
    for (int i = 1; i < ARRAY_SIZE; i++) {
        if (vetor[i-1] > vetor[i]) {
            int aux = vetor[i];
            int j = i;
            while (j > 0 && vetor[j-1] > vetor[j])  {
                vetor[j] = vetor[j-1];
                vetor[j-1] = aux;
                j--;
            }
        }
    }
}

void mostrarMediana(int *vetor) {
    ordenarArray(vetor);
    float mediana;
    if (ARRAY_SIZE % 2 == 0) {
        mediana = (vetor[ARRAY_SIZE / 2 - 1] + vetor[ARRAY_SIZE/2]) / (float)2;
    } else {
        mediana = vetor[ARRAY_SIZE / 2];
    }
    printf("A mediana é %.1f", mediana);
}

int produtoTodosOsNumeros(int *vetor) {
    int result = 1;

    for (int i = 0; i < ARRAY_SIZE; i++) {
        result = result * vetor[i];
    }

    return result;
}

float porcentagemPares(int *vetor) {
    float quantNums = 0.0;
    for (int i = 0; i < ARRAY_SIZE; i++) {
        if (vetor[i] % 2 == 0 && vetor[i] > 0) quantNums++;
    }
    return quantNums / ARRAY_SIZE * 100.0;
}

int verificaSeAindaHaImpar(int iteradorAtual, int *vetor) {
    for (int i = iteradorAtual+1; i < ARRAY_SIZE; i++) {
        if (vetor[i] % 2 == 1) return 1;
    }
    return 0;
}

void mostrarImpares(int *vetor) {
    for (int i = 0; i < ARRAY_SIZE; i++) {
        if (vetor[i] % 2 == 1) {
            printf("%d%s", vetor[i], verificaSeAindaHaImpar(i, vetor) ? ", " : "\n");
        }
    }   
}

int somaDosImpares(int *vetor) {
    int sum = 0;
    for (int i = 0; i < ARRAY_SIZE; i++) {
        if (vetor[i] % 2 == 1) {
            sum = sum + vetor[i];
        }
    }
    return sum;
}

void inserirNoArray(float element, float *array) {
    for (int i = 0; i < ARRAY_SIZE; i++) {
        if (array[i] == valorGenerico) {
            array[i] = element;
            break;
        }       
    }
}

int estaNoArray(float num, float *vetor) {
    for (int i = 0; i < ARRAY_SIZE; i++) {
        if (num == vetor[i]) return 1;
    }
    return 0;
}

void numerosRepetidos(int *vetor, float *vetorNumerosRepetidos) {
    int num;

    for (int i = 0; i < ARRAY_SIZE; i++) {
        vetorNumerosRepetidos[i] = valorGenerico;
    }

    for (int i = 0; i < ARRAY_SIZE; i++) {
        num = vetor[i];
        for (int j = 0; j < ARRAY_SIZE; j++) {
            if (vetor[j] == num && j != i && !estaNoArray((float)num, vetorNumerosRepetidos)) {
                inserirNoArray((float)num, vetorNumerosRepetidos);
            }
        }
    }
}

void mostrarArrayComRepetidos(float *vetorNumerosRepetidos) {
    for (int i = 0; i < ARRAY_SIZE; i++) {
        if (vetorNumerosRepetidos[i] == valorGenerico) break;
        printf("%.0f%s", vetorNumerosRepetidos[i], vetorNumerosRepetidos[i+1] == valorGenerico ? "\n" : ", ");
    }
}
