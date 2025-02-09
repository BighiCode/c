#include <stdlib.h>
#include <stdio.h>
#include <string.h>

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