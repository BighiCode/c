#include "Tarefas.h"

void lerArquivoTarefas(Tarefa *Tarefas)
{
    FILE* arqTarefas;
    arqTarefas = fopen("tarefas.dat", "r");
    if (arqTarefas == NULL)
    {
        printf("Erro ao abrir o arquivo");     
    }else{
        int i = 0;
        while(fscanf(arqTarefas, "%d %d %d %d %d %d %d" ,&Tarefas[i].turnoDeAparecimento, &Tarefas[i].prazo, &Tarefas[i].pausDemandados, &Tarefas[i].espadasDemandadas, &Tarefas[i].ourosDemandados, &Tarefas[i].copasDemandadas, &Tarefas[i].premioDeRembaralhamento) == 7){
            i++;
        }
        fclose(arqTarefas);
    }
}

void imprimirTODASTarefas(Tarefa *Tarefas, int quantidade){

    for (int i = 0; i < 10; i++)
    {
        printf(" %d (P-%d E-%d O-%d C-%d)\t", Tarefas[i].prazo, Tarefas[i].pausDemandados, Tarefas[i].espadasDemandadas, Tarefas[i].ourosDemandados, Tarefas[i].copasDemandadas);
    }

}

//--------------------------------------------------------------------------


