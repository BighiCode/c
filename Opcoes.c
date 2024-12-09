#include "Opcoes.h"


/**
 * ARQ opcoes
 * 
 * @return ponteiro para a nova mão
 */
void sortearCartas(Tno** cabeca, TCarta *mao, int quantidade){

    for(int i = 0; i < quantidade; i++){
        mao[i] = sortearCarta(cabeca);
    }

}

TCarta sortearCarta(Tno** cabeca){
    
    Tno carta;
    Tno* atual = *cabeca;
    int posicao = rand() % 52;
    for(int i = 0; i < posicao; i++){
        atual = atual->prox;
    }
    carta = *atual;
    *cabeca = atual->prox;
    return carta.carta;
}