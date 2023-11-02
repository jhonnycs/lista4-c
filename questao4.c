#include <stdio.h>
#include <ctype.h>

/*
    Ler um vetor G de 10 caracteres que representa o gabarito de uma prova.
    Depois, para cada um dos 50 alunos da turma, ler o vetor de respostas R
    do aluno e contar a quantidade de acertos.
    Mostrar o número de acertos do aluno e a mensagem APROVADO, se a número de
    acertos for maior ou igual a 6; ou a mensagem REPROVADO, caso contrário.

*/

#define GABARITO_SIZE 10
#define RESPOSTA_SIZE 10

int main() {
    char gabarito[GABARITO_SIZE];

    for (int i = 0; i < GABARITO_SIZE; i++) {
        printf("Digite o gabarito da questão %d:\n> ", i+1);
        scanf(" %c", &gabarito[i]);

        while (!isalpha(gabarito[i])) {
            printf("Por favor, digite uma letra:\n> ");
            scanf(" %c", &gabarito[i]);
        }
    }

    for (int i = 0; i < GABARITO_SIZE; i++) {
        
    }
        
    return 0;
}