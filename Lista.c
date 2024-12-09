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
        inserirNoFinal(cabeca, cartas[i]);
    }
}

void imprimirCartas(Tno* cabeca) {
    Tno* atual = cabeca;
    while (atual != NULL) {
        printf("%s %c %d %s\n", atual->carta.face, atual->carta.naipe, atual->carta.valor, atual->carta.nome);
        atual = atual->prox;
    }
}
