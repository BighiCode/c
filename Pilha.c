#include "Pilha.h"

// Função para inicializar a pilha
void inicializarPilha(Pilha* p) {
    p->topo = -1;  // Pilha vazia
}

// Função para verificar se a pilha está vazia
int pilhaVazia(Pilha* p) {
    return p->topo == -1;  // Se topo for -1, a pilha está vazia
}

// Função para verificar se a pilha está cheia
int pilhaCheia(Pilha* p) {
    return p->topo == MAX - 1;  // Se topo atingir o máximo, a pilha está cheia
}

// Função para empilhar (inserir um item)
void empilhar(Pilha* p, int item) {
    if (pilhaCheia(p)) {
        printf("Erro: Pilha cheia!\n");
        return;
    }
    p->topo++;  // Avança o topo
    p->itens[p->topo] = item;  // Adiciona o item na pilha
    printf("Item %d empilhado.\n", item);
}

// Função para desempilhar (remover um item)
int desempilhar(Pilha* p) {
    if (pilhaVazia(p)) {
        printf("Erro: Pilha vazia!\n");
        return -1;  // Retorna -1 se a pilha estiver vazia
    }
    int item = p->itens[p->topo];  // Pega o item no topo
    p->topo--;  // Retrocede o topo
    return item;  // Retorna o item removido
}

// Função para visualizar o topo da pilha
int topoPilha(Pilha* p) {
    if (pilhaVazia(p)) {
        printf("Erro: Pilha vazia!\n");
        return -1;  // Retorna -1 se a pilha estiver vazia
    }
    return p->itens[p->topo];  // Retorna o item no topo
}

// Função para exibir os itens da pilha
void exibirPilha(Pilha* p) {
    if (pilhaVazia(p)) {
        printf("Pilha vazia!\n");
        return;
    }
    printf("Itens da pilha: ");
    for (int i = 0; i <= p->topo; i++) {
        printf("%d ", p->itens[i]);
    }
    printf("\n");
}