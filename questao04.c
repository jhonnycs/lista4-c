#include <ctype.h>
#include <stdio.h>

/*
    Ler um vetor G de 10 caracteres que representa o gabarito de uma prova.
    Depois, para cada um dos 50 alunos da turma, ler o vetor de respostas R
    do aluno e contar a quantidade de acertos.
    Mostrar o número de acertos do aluno e a mensagem APROVADO, se a número de
    acertos for maior ou igual a 6; ou a mensagem REPROVADO, caso contrário.

*/

#define GABARITO_RESPOSTA_SIZE 10
#define NUM_ALUNOS 3

void capturarGabaritoQuestao(char *gabarito);
void capturarRespostaAluno(char *respostas, int aluno);
int compararRespostaComGabarito(char *gabarito, char *respostas);
void calcularNotaAlunos(char *gabarito, char *respostas);

int main() {
    char gabarito[GABARITO_RESPOSTA_SIZE];
    char respostas[GABARITO_RESPOSTA_SIZE];

    capturarGabaritoQuestao(gabarito);

    printf("\n");

    calcularNotaAlunos(gabarito, respostas);

    return 0;
}

void capturarGabaritoQuestao(char *gabarito) {
    for (int i = 0; i < GABARITO_RESPOSTA_SIZE; i++) {
        printf("Digite o gabarito da questão %d:\n> ", i + 1);
        scanf(" %c", &gabarito[i]);

        while (isalpha(gabarito[i]) != 2) {
            printf("Por favor, digite uma letra minúscula:\n> ");
            scanf(" %c", &gabarito[i]);
        }
    }
}

void capturarRespostaAluno(char *respostas, int aluno) {
    for (int i = 0; i < GABARITO_RESPOSTA_SIZE; i++) {
        printf("Digite a resposta da questão %d do aluno número %d:\n> ", i + 1,
               aluno + 1);
        scanf(" %c", &respostas[i]);

        while (isalpha(respostas[i]) != 2) {
            printf("Por favor, digite uma letra minúscula:\n> ");
            scanf(" %c", &respostas[i]);
        }
    }
}

int compararRespostaComGabarito(char *gabarito, char *respostas) {
    int nota = 0;

    for (int i = 0; i < GABARITO_RESPOSTA_SIZE; i++) {
        if (gabarito[i] == respostas[i]) nota++;
    }
    return nota;
}

void calcularNotaAlunos(char *gabarito, char *respostas) {
    for (int i = 0; i < NUM_ALUNOS; i++) {
        capturarRespostaAluno(respostas, i);
        int nota = compararRespostaComGabarito(gabarito, respostas);

        printf("\nNota do aluno %d: %d\n", i + 1, nota);

        if (nota >= 6) {
            printf("Aluno %d aprovado", i + 1);
        } else {
            printf("Aluno %d reprovado", i + 1);
        }
    }
    printf("\n");
}