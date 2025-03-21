#include   "Arvore.h"
#include <math.h>

NoArvore *criarArvore() {
    return NULL;
}

NoArvore *inserir(NoArvore *raiz, TCarta valor) {

    if (raiz == NULL) {
        raiz = malloc(sizeof(NoArvore));
        raiz->valor.valor = valor.valor;
        raiz->esq = NULL;
        raiz->dir = NULL;
    } else if (valor.valor <= raiz->valor.valor) {
        raiz->esq = inserir(raiz->esq, valor);
    } else if (valor.valor >= raiz->valor.valor) {
        raiz->dir = inserir(raiz->dir, valor);
    }
    return raiz;
}

NoArvore *inserirvetorNaArvore(  NoArvore *raiz, TCarta *vetor, int tamanho) {
    
    for(int i = 0; i < tamanho; i++) {
        
        raiz = inserir(raiz, vetor[i]);
        printf("%d ", vetor[i].valor);
    }
    return raiz;

}

void imprimir(NoArvore *raiz) {

    if (raiz != NULL) {
        imprimir(raiz->esq);
        printf("\n%d ", raiz->valor.valor);
        imprimir(raiz->dir);
    }
}

void imprimirForaDeOrdem(NoArvore *raiz) {

    if (raiz != NULL) {
        imprimirForaDeOrdem(raiz->esq);
        imprimirForaDeOrdem(raiz->dir);
        printf("\n%d ", raiz->valor.valor);
    }
}

int altura(NoArvore* raiz) {
    if (raiz == NULL) return 0;
    int alt_esq = altura(raiz->esq);
    int alt_dir = altura(raiz->dir);
    return (alt_esq > alt_dir ? alt_esq : alt_dir) + 1;
}

// Função para armazenar a árvore em um buffer antes da impressão
void escrever_arvore(NoArvore* raiz, char **buffer, int profundidade, int pos, int desloc) {
    if (raiz == NULL) return;

    // Escreve o valor do nó
    char str[10];
    sprintf(str, "%d", raiz->valor.valor);
    int len = strlen(str);
    strncpy(&buffer[profundidade][pos - len / 2], str, len);

    // Desenha as conexões "/ \"
    if (raiz->esq) {
        buffer[profundidade + 1][pos - desloc / 2] = '/';
        escrever_arvore(raiz->esq, buffer, profundidade + 2, pos - desloc, desloc / 2);
    }
    if (raiz->dir) {
        buffer[profundidade + 1][pos + desloc / 2] = '\\';
        escrever_arvore(raiz->dir, buffer, profundidade + 2, pos + desloc, desloc / 2);
    }
}

// Função principal para imprimir a árvore binária
void imprimirEmformatoDeArvore(NoArvore* raiz) {
    int h = altura(raiz);
    int largura = (1 << (h + 1)); // Largura baseada na profundidade

    // Criando um buffer para armazenar a árvore antes de imprimir
    char **buffer = (char**)malloc((h * 2) * sizeof(char*));
    for (int i = 0; i < h * 2; i++) {
        buffer[i] = (char*)malloc(largura * sizeof(char));
        memset(buffer[i], ' ', largura);
        buffer[i][largura - 1] = '\0'; // Garante que a linha termina corretamente
    }

    // Escreve a árvore no buffer
    escrever_arvore(raiz, buffer, 0, largura / 2, largura / 4);

    // Imprime o buffer na tela
    for (int i = 0; i < h * 2; i++) {
        printf("%s\n", buffer[i]);
        free(buffer[i]);
    }
    free(buffer);
}


NoArvore *buscar(NoArvore *raiz, TCarta valor) {
    if (raiz == NULL || raiz->valor.valor == valor.valor) {
        return raiz;
    } else if (valor.valor < raiz->valor.valor) {
        return buscar(raiz->esq, valor);
    } else {
        return buscar(raiz->dir, valor);
    }
}

NoArvore *remover(NoArvore *raiz, TCarta valor) {
    if (raiz == NULL) {
        return NULL;
    } else if (valor.valor < raiz->valor.valor) {
        raiz->esq = remover(raiz->esq, valor);
    } else if (valor.valor > raiz->valor.valor) {
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

// **PASSO 1: Contar os Nós na Árvore**
int contarNos(NoArvore *raiz) {
    if (raiz == NULL) return 0;
    return 1 + contarNos(raiz->esq) + contarNos(raiz->dir);
}

// **PASSO 2: Armazena os Nós em Ordem Crescente**
void armazenarNosEmOrdem(NoArvore *raiz, NoArvore **array, int *indice) {
    if (raiz == NULL) return;

    armazenarNosEmOrdem(raiz->esq, array, indice);
    array[*indice] = raiz;
    (*indice)++;
    armazenarNosEmOrdem(raiz->dir, array, indice);
}

// **PASSO 3: Constrói uma Árvore Balanceada**
NoArvore *construirArvoreBalanceada(NoArvore **array, int inicio, int fim) {
    if (inicio > fim) return NULL;

    int meio = (inicio + fim) / 2;
    NoArvore *raiz = array[meio];

    raiz->esq = construirArvoreBalanceada(array, inicio, meio - 1);
    raiz->dir = construirArvoreBalanceada(array, meio + 1, fim);

    return raiz;
}

// **Função Principal para Balancear a Árvore**
NoArvore *balancear(NoArvore *raiz) {
    if (raiz == NULL) return NULL;

    // 1️⃣ Conta os nós da árvore
    int n = contarNos(raiz);

    // 2️⃣ Armazena os nós em um array ordenado
    NoArvore **array = (NoArvore **)malloc(n * sizeof(NoArvore *));
    int indice = 0;
    armazenarNosEmOrdem(raiz, array, &indice);

    // 3️⃣ Resetamos os ponteiros antes de reconstruir
    for (int i = 0; i < n; i++) {
        array[i]->esq = array[i]->dir = NULL;
    }

    // 4️⃣ Constrói a árvore balanceada
    NoArvore *novaRaiz = construirArvoreBalanceada(array, 0, n - 1);

    free(array); // Libera o array auxiliar

    return novaRaiz;
}