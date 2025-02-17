#include <stdio.h>
#include <stdlib.h>

#define MAX 52  // Define o tamanho máximo da pilha

// Definição do tipo da pilha
typedef struct {
    int itens[MAX];
    int topo;  // Índice do topo da pilha
} Pilha;

void inicializarPilha(Pilha* pilha);
void empilhar(Pilha* pilha, int item);
int desempilhar(Pilha* pilha);
int topo(Pilha* pilha);
int pilhaCheia(Pilha* pilha);
int pilhaVazia(Pilha* pilha);
void imprimirPilha(Pilha* pilha);