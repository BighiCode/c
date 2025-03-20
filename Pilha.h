#ifndef PILHA_H
#define PILHA_H

#include <stdio.h>
#include <stdlib.h>
#include "Opcoes.h"

#define MAX 52  // Define o tamanho máximo da pilha

// Definição do tipo da pilha
typedef struct {
    TCarta itens[MAX];
    int topo;  // Índice do topo da pilha
} Pilha;

void inicializarPilha(Pilha* pilha);
void empilhar(Pilha* pilha, TCarta carta);
TCarta desempilhar(Pilha* pilha);
int pilhaVazia(Pilha* pilha);
int pilhaCheia(Pilha* pilha);
void exibirPilha(Pilha* pilha);
void limparPilha(Pilha* pilha);
void inserirCartasNaPilha(Pilha* pilha, TCarta* cartas, int numCartas);
int comprarCartasDaPilha(Tno** mao, Pilha *pilha,int n);
int getTamanhoPilha(Pilha* pilha);
int TranferirPilha(Pilha *pilha, Pilha *descarte,int n);
void passarPilhaParaVetor(Pilha *pilha, TCarta *v);

#endif