#include <stdio.h>

/*
    Ler um vetor N[20]. Encontrar o menor elemento do vetor N e a sua posição dentro
    do vetor, mostrando: “O menor elemento de N é “, M, “e sua posição dentro do vetor é ", P

*/

int main() {
    int N[20];
    int nSize = sizeof(N) / sizeof(N[0]);

    for (int i = 0; i < nSize; i++) {
        printf("Digite o número %d:\n> ", i);
        scanf("%d", &N[i]);
    }

    int menorElemento = N[0];
    int posicao;

    for (int i = 0; i < nSize; i++) {
        if (menorElemento > N[i]) {
            menorElemento = N[i];
            posicao = i;
        }
    }
    
    printf("O menor elemento de N é %d, e sua posição no vetor é %d", menorElemento, posicao);
    

    return 0;
}