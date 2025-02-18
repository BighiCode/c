#include "Pilha.h"

// Inicializa a pilha vazia
void inicializarPilha(Pilha* p) {
    p->topo = -1;
}

// Verifica se a pilha está vazia
int pilhaVazia(Pilha* p) {
    return p->topo == -1;
}

// Verifica se a pilha está cheia
int pilhaCheia(Pilha* p) {
    return p->topo == MAX - 1;
}

// Empilha uma carta
void empilhar(Pilha* p, TCarta carta) {
    if (pilhaCheia(p)) {
        printf("Erro: Pilha cheia!\n");
        return;
    }
    p->topo++;
    p->itens[p->topo] = carta;
    printf("Carta %s empilhada.\n", carta.nome);
}

// Desempilha uma carta
TCarta desempilhar(Pilha* p) {
    TCarta cartaVazia = {"", '\0', 0, ""};  // Carta vazia para retorno em erro

    if (pilhaVazia(p)) {
        printf("Erro: Pilha vazia!\n");
        return cartaVazia;
    }
    
    TCarta cartaRemovida = p->itens[p->topo];
    p->topo--;
    return cartaRemovida;
}

// Exibe as cartas na pilha
void exibirPilha(Pilha* p) {
    if (pilhaVazia(p)) {
        printf("Pilha vazia!\n");
        return;
    }

    printf("\nCartas na pilha:\n");
    for (int i = p->topo; i >= 0; i--) {
        printf("[%s de ", p->itens[i].face);

        switch (p->itens[i].naipe) {
            case 'C': printf("Copas"); break;
            case 'E': printf("Espadas"); break;
            case 'P': printf("Paus"); break;
            case 'O': printf("Ouros"); break;
        }
        printf("]\n");
    }
}