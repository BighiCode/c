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

Fila *criarFila()
{
    Fila* f = malloc(sizeof(Fila));
    f->head = NULL;
    f->tail = NULL;
    f->tamanho = 0;
    return f;
}

int tamanhoFila(Fila *f)
{
    return f->tamanho;
}

bool estaVazia(Fila *f){
    return (f->tamanho == 0);
}

Tarefa espiarFila(Fila *f, bool *status){

    Tarefa defaultTarefa = {0};

    if (estaVazia(f)){
        *status = false;
        return defaultTarefa;
    }else{
        *status = true;
        return f->head->tarefa;
    }

}

void adicionarFila(Fila *f, Tarefa tarefa){
    Node *novo = malloc(sizeof(Node));
    novo->tarefa = tarefa;
    novo->next = NULL;
    if (estaVazia(f)){
        f->head = novo;
        f->tail = novo;
    }else{
        f->tail->next = novo;
        f->tail = novo;
    }
    f->tamanho++;
}

Tarefa removerFila(Fila *f, bool *status){

    if (estaVazia(f)){
        *status = false;
        return f->head->tarefa;
    }else{
        *status = true;
        Node *aux = f->head;
        f->head = f->head->next;
        f->tamanho--;
        return aux->tarefa;
    }
}

void diminuirPrazo(Fila *f){

    if (estaVazia(f)) {
        printf(" Nenhuma tarefa na fila.\n");
        return;
    }

    Node* atual = f->head;
    while (atual != NULL) {
        Tarefa *t = &atual->tarefa;
        t->prazo = t->prazo - 1;
        atual = atual->next;
    }

}

void fiscalizador(Fila *f, Bonus *desbonus) {

    if(estaVazia(f)){
        printf(" Nenhuma tarefa na fila.\n");
        return;
    }
    bool status;
    if(f->head->tarefa.prazo <= 0){
        desbonus->copas += f->head->tarefa.copasDemandadas;
        desbonus->espadas += f->head->tarefa.espadasDemandadas;
        desbonus->ouros += f->head->tarefa.ourosDemandados;
        desbonus->paus += f->head->tarefa.pausDemandados;
        removerFila(f, &status);
    }

}


