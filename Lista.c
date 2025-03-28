#include "Lista.h"
#include <stdlib.h>
#include <stdio.h>

void inserirNoInicio(Tno** cabeca, TCarta carta) {
    Tno* novoNo = (Tno*)malloc(sizeof(Tno));
    if (novoNo == NULL) {
        printf("Erro ao alocar memoria para o novo no\n");
        return;
    }
    novoNo->carta = carta;
    novoNo->prox = *cabeca;
    *cabeca = novoNo;
}

void inserirNoFinal(Tno** cabeca, TCarta carta) {
    Tno* novoNo = (Tno*)malloc(sizeof(Tno));
    if (novoNo == NULL) {
        printf("Erro ao alocar memoria para o novo no\n");
        return;
    }
    novoNo->carta = carta;
    novoNo->prox = NULL;
    if (*cabeca == NULL) {
        *cabeca = novoNo;
    } else {
        Tno* atual = *cabeca;
        while (atual->prox != NULL) {
            atual = atual->prox;
        }
        atual->prox = novoNo;
    }
}


 void inserirCartas(Tno** cabeca, TCarta* cartas, int numCartas) {
    for (int i = 0; i < numCartas; i++) {
        // insere a carta na lista
        inserirNoInicio(cabeca, cartas[i]);
    }
}


void imprimirCartas(Tno* cabeca, int quantidade) {
    Tno* atual = cabeca;
    TCarta *cartas = malloc( quantidade*sizeof(TCarta));
    while (atual != NULL && quantidade > 0) {
        //printf("|%s-%c|\t", atual->carta.face, atual->carta.naipe);
        printGrandesCartas(atual->carta, getPosicaoCarta(cabeca,atual->carta));
        atual = atual->prox;
        quantidade--;
    }


    //printf("\nposicao:");
    printf("\n-------------------------------------------------------");
}

int getPosicaoCarta(Tno* cabeca, TCarta carta) {
    int posicao = 0;
    Tno* atual = cabeca;
    while (atual != NULL) {
        if (strcmp(atual->carta.face, carta.face) == 0 && atual->carta.naipe == carta.naipe) {
            return posicao + 1;
        }
        posicao++;
        atual = atual->prox;
    }
    return -1; // carta não encontrada
}


void printGrandesCartas(TCarta carta, int pos) {
    
    printf("\n _________");
    printf("\n|\t  |");
    printf("\n| %-2s\t  |", carta.face);
    printf("\n|\t  |");
{
    if(carta.naipe == 'C'){
        printf("\n|    ♥\t  |");
    }
    if(carta.naipe == 'E'){
        printf("\n|    ♠\t  |",4);
    }
    if(carta.naipe == 'P'){
        printf("\n|    ♣\t  |",2);
    }
    if(carta.naipe == 'O'){
        printf("\n|    ♦\t  |",1);
    }
}
    printf("\n|\t  |");
    printf("\n|\t%-2s|", carta.face);
    printf("\n|_________|" );
    printf("\n%d°",pos);

}



void removerCartas(Tno** cabeca, Tno* carta) {
    
    Tno* atual = *cabeca;
    Tno* anterior = NULL;
    
    while (atual != NULL && atual != carta) {
        anterior = atual;
        atual = atual->prox;
    }
    
    if (atual == NULL) {
        return;
    }
    
    if (anterior == NULL) {
        *cabeca = atual->prox;
    } else {
        anterior->prox = atual->prox;
    }
    
    free(atual);
    
}

void copiarPrimeiroParaMao(Tno** cabeca, Tno** mao) {
    if (*cabeca == NULL) {
        return;
    }
    Tno* atualcabeca = *cabeca;
    inserirNoFinal(mao, atualcabeca->carta);
    *cabeca = atualcabeca->prox;
    free(atualcabeca);
}

int getTamanhoLista(Tno* cabeca) {
    int tamanho = 0;
    Tno* atual = cabeca;
    while (atual != NULL) {
        tamanho++;
        atual = atual->prox;
    }
    return tamanho;
}