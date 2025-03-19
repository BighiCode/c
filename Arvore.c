#include   "Arvore.h"


NoArvore *criarArvore() {
    return NULL;
}

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

NoArvore *buscar(NoArvore *raiz, int valor) {
    if (raiz == NULL || raiz->valor == valor) {
        return raiz;
    } else if (valor < raiz->valor) {
        return buscar(raiz->esq, valor);
    } else {
        return buscar(raiz->dir, valor);
    }
}

NoArvore *remover(NoArvore *raiz, int valor) {
    if (raiz == NULL) {
        return NULL;
    } else if (valor < raiz->valor) {
        raiz->esq = remover(raiz->esq, valor);
    } else if (valor > raiz->valor) {
        raiz->dir = remover(raiz->dir, valor);
    } else {
        if (raiz->esq == NULL && raiz->dir == NULL) {
            free(raiz);
            raiz = NULL;
        } else if (raiz->esq == NULL) { 
            NoArvore *temp = raiz;
            raiz = raiz->dir;
            free(temp);
        } else if (raiz->dir == NULL) {
            NoArvore *temp = raiz;
            raiz = raiz->esq;
            free(temp);
        } else {
            NoArvore *temp = raiz->dir;
            while (temp->esq != NULL) {
                temp = temp->esq;
            }
            raiz->valor = temp->valor;
            raiz->dir = remover(raiz->dir, temp->valor);
        }
    }
    return raiz;
}

void destruir(NoArvore *raiz) {
    if (raiz != NULL) {
        destruir(raiz->esq);
        destruir(raiz->dir);
        free(raiz);
    }
}

NoArvore *balancear(NoArvore *raiz) {
    if (raiz == NULL) {
        return NULL;
    }
    raiz->esq = balancear(raiz->esq);
    raiz->dir = balancear(raiz->dir);
    return raiz;
}