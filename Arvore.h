#ifndef ARVORE_H
#define ARVORE_H

#include <stdio.h>
#include <stdlib.h>
#include "Cartas.h"

typedef struct no{
    TCarta valor;
    struct no *esq;
    struct no *dir;
}NoArvore;


NoArvore *inserir(NoArvore *raiz, TCarta valor);
void imprimir(NoArvore *raiz);
void destruir(NoArvore *raiz);
NoArvore *criarArvore();
NoArvore *buscar(NoArvore *raiz, TCarta valor);
NoArvore *remover(NoArvore *raiz, TCarta valor);
NoArvore *balancear(NoArvore *raiz);
NoArvore *inserirvetorNaArvore(  NoArvore *raiz, TCarta *vetor, int tamanho);
void imprimirForaDeOrdem(NoArvore *raiz);

void imprimirEmformatoDeArvore(NoArvore *raiz);

int altura(NoArvore * raiz);
void escrever_arvore(NoArvore* raiz, char **buffer, int profundidade, int pos, int desloc);
NoArvore *construirArvoreBalanceada(NoArvore **array, int inicio, int fim);
void armazenarNosEmOrdem(NoArvore *raiz, NoArvore **array, int *indice);
int contarNos(NoArvore *raiz);

int profundidadeMinima(NoArvore* raiz);

#endif