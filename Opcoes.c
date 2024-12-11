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

void reposionarCartas(Tno** cabeca, int p1, int p2){

    Tno* temp1 = *cabeca;
    Tno* temp2 = *cabeca;

    for(int i = 0; i < p1; i++){
        temp1 = temp1->prox;
    }

    for(int i = 0; i < p2; i++){
        temp2 = temp2->prox;
    }
    

}
