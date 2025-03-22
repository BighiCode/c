#ifndef TAREFAS_H
#define TAREFAS_H

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "Cartas.h"

typedef struct tarefa {
    int turnoDeAparecimento;
    int prazo;
    int pausDemandados;
    int espadasDemandadas;
    int ourosDemandados;
    int copasDemandadas;
    int premioDeRembaralhamento;
} Tarefa;


void lerArquivoTarefas(Tarefa *Tarefas);
void imprimirTODASTarefas(Tarefa *Tarefas, int quantidade);

typedef struct Node {
    Tarefa tarefa;
    struct Node* next;
} Node;

typedef struct{
    Node* head;
    Node* tail;
    int tamanho;
} Fila;

Fila* criarFila();
int tamanhoFila(Fila* fila);
bool estaVazia(Fila* fila);
Tarefa espiarFila(Fila* fila, bool *status);
void adicionarFila(Fila* fila, Tarefa tarefa);
Tarefa removerFila(Fila* fila, bool *status);
void diminuirPrazo(Fila *f);
void fiscalizador(Fila *f, Bonus *desbonus);

#endif