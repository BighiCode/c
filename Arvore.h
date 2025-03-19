#ifndef ARVORE_H
#define ARVORE_H

#include <stdio.h>
#include <stdlib.h>


typedef struct no{
    int valor;
    struct no *esq;
    struct no *dir;
}NoArvore;


NoArvore *inserir(NoArvore *raiz, int valor);
void imprimir(NoArvore *raiz);
void destruir(NoArvore *raiz);
NoArvore *criarArvore();


#endif