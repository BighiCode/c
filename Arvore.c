#include   "Arvore.h"

NoArvore *inserir(NoArvore *raiz, int valor) {
    if (raiz == NULL) {
        raiz = malloc(sizeof(NoArvore));
        raiz->valor = valor;
        raiz->esq = NULL;
        raiz->dir = NULL;
    } else if (valor < raiz->valor) {
        raiz->esq = inserir(raiz->esq, valor);
    } else if (valor > raiz->valor) {
        raiz->dir = inserir(raiz->dir, valor);
    }
    return raiz;
}

void imprimir(NoArvore *raiz) {
    if (raiz != NULL) {
        imprimir(raiz->esq);
        printf("%d ", raiz->valor);
        imprimir(raiz->dir);
    }
}