#include "Pilha.h"

// Inicializa a pilha vazia
void inicializarPilha(Pilha* p) {
    if (p != NULL) {
        p->topo = -1;
    } else {
        // Você pode querer tratar o erro de alguma forma, por exemplo:
        printf("Erro: ponteiro nulo\n");
    }
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
    //printf("Carta %s empilhada.\n", carta.nome);
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
        printf("] %d\n",i);
    }
}


void inserirCartasNaPilha(Pilha* pilha, TCarta* cartas, int numCartas){
    for (int i = 0; i < numCartas; i++) {
        empilhar(pilha, cartas[i]);
    }
}

int comprarCartasDaPilha(Tno** mao, Pilha *pilha ,int n) {
    if (pilhaVazia(pilha)) {
        return 0;
    }

    for (int i = 0; i < n; i++) {
        inserirNoFinal(mao, desempilhar(pilha));
    }

    return (-1*n);
}

int TranferirPilha(Pilha *pilha, Pilha *descarte,int n) {
   
    for(int i = 0; i < n; i++){
        empilhar(descarte, desempilhar(pilha));
    }

}

int getTamanhoPilha(Pilha* pilha){
    return pilha->topo + 1;
}

void passarPilhaParaVetor(Pilha *pilha, TCarta *v){
    for (int i = pilha->topo; i >= 0; i--){
        v[i] = desempilhar(pilha);
    }
}

void embaralharPilha(Pilha *pilha){
    passarPilhaParaVetor(pilha, pilha->itens);
    embaralhar(pilha->itens, pilha->topo + 1);
    inserirCartasNaPilha(pilha, pilha->itens, pilha->topo + 1);
}