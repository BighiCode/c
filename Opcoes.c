#include "Opcoes.h"


/**
 * ARQ opcoes
 * 
 * @return ponteiro para a nova mão
 */
void sortearCartas(Tno** cabeca, int quantidade, int numCartasRestantes) {

    TCarta mao[quantidade];

    for(int i = 0; i < quantidade; i++){
        mao[i] = sortearCarta(cabeca, numCartasRestantes);
        numCartasRestantes--;
    }

    inserirCartas(cabeca, mao, quantidade);

}

/**
 * ARQ opcoes
 * 
 * sorteia as cartas da mão
 * dps remove elas da lista
 * @return cartas sorteadas
 */
TCarta sortearCarta(Tno** cabeca, int numCartasRestantes) {
    if (*cabeca == NULL) {
        printf("Erro: lista de cartas vazia\n");
        exit(EXIT_FAILURE);
    }

    Tno *temp = *cabeca;
    if(numCartasRestantes == 0){printf("Erro1: lista de cartas menor que a quantidade solicitada\n"); return temp->carta;}
    int posicao = rand() % numCartasRestantes;
    for (int i = 0; i < posicao; i++) {
        if (temp->prox == NULL) {
            printf("Erro2: lista de cartas menor que a quantidade solicitada\n");
            exit(EXIT_FAILURE);
        }
        temp = temp->prox;
    }
    
    TCarta carta = (temp)->carta;
    removerCartas(cabeca, temp);
    return carta;
}

void reposicionarCartas(Tno** cabeca, int p1, int p2) {
    if (*cabeca == NULL || p1 == p2) {
        return;
    }

    Tno* carta1 = *cabeca;
    Tno* carta2 = *cabeca;
    Tno* anterior1 = NULL;
    Tno* anterior2 = NULL;

    // Encontra a carta na posição p1
    for (int i = 0; i < p1; i++) {
        if (carta1 == NULL) {
            return;
        }
        anterior1 = carta1;
        carta1 = carta1->prox;
    }


    // Encontra a carta na posição p2
    for (int i = 0; i < p2; i++) {
        if (carta2 == NULL) {
            return;
        }
        anterior2 = carta2;
        carta2 = carta2->prox;
    }


    // Troca as cartas
    if (anterior1 == NULL) {
        *cabeca = carta2;
    } else {
        anterior1->prox = carta2;
    }

    if (anterior2 == NULL) {
        *cabeca = carta1;
    } else {
        anterior2->prox = carta1;
    }

    // Troca os próximos ponteiros
    Tno* prox1 = carta1->prox;
    carta1->prox = carta2->prox;
    carta2->prox = prox1;
}
