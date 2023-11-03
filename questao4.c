#include <stdio.h>
#include <ctype.h>

/*
    Ler um vetor G de 10 caracteres que representa o gabarito de uma prova.
    Depois, para cada um dos 50 alunos da turma, ler o vetor de respostas R
    do aluno e contar a quantidade de acertos.
    Mostrar o número de acertos do aluno e a mensagem APROVADO, se a número de
    acertos for maior ou igual a 6; ou a mensagem REPROVADO, caso contrário.

*/

#define GABARITO_RESPOSTA_SIZE 10
#define NUM_ALUNOS 50

int main() {
    char gabarito[GABARITO_RESPOSTA_SIZE];
    char respostas[GABARITO_RESPOSTA_SIZE];

    for (int i = 0; i < GABARITO_RESPOSTA_SIZE; i++) {
        printf("Digite o gabarito da questão %d:\n> ", i+1);
        scanf(" %c", &gabarito[i]);

        while (isalpha(gabarito[i]) != 2) {
            printf("Por favor, digite uma letra minúscula:\n> ");
            scanf(" %c", &gabarito[i]);
        }
    }
    printf("\n");
    for (int i = 0; i < NUM_ALUNOS; i++) {
        int nota = 0;
        for (int j = 0; j < GABARITO_RESPOSTA_SIZE; j++) {
            printf("Digite a resposta da questão %d do aluno número %d:\n> ", j+1, i+1);
            scanf(" %c", &respostas[j]);

            while (isalpha(respostas[j]) != 2) {
            printf("Por favor, digite uma letra minúscula:\n> ");
            scanf(" %c", &respostas[j]);
        }
        }

        for (int j = 0; j < GABARITO_RESPOSTA_SIZE; j++) {
            if (gabarito[j] == respostas[j]) nota++;
        }

        printf("\nNota do aluno %d: %d\n", i+1, nota);

        if (nota >= 6) {
            printf("Aluno %d aprovado", i+1);
        } else {
            printf("Aluno %d reprovado", i+1);
        }

        nota = 0;
        printf("\n");
    }
    return 0;
}