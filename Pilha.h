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
