#include "Menu.h"

/**
 * PRINTA AS OPÇÕES DO MENU	1
 * 1. Sortear
 * 2. Sair
 * @returns escolha
 */
int menu1(){
    int escolha;
    printf("\n\n-------------------------------------------------------");
    printf("\nMenu\n\n");
    printf("1. Sortear\n");
    printf("2. Sair\n");
    printf("Escolha uma opcao: ");
    scanf("%d", &escolha);
    return escolha;
}


/**
 * PRINTA AS OPÇÕES DO MENU	2
 * 1. reposicionar cartas
 * 2. embaralhar cartas
 * 3. Sair
 * @returns escolha
 */
int menu2(Bonus* bonus, int bonusReembaralhamento){
    int escolha;
    int n = 0;
    printf("\n-------------------------------------------------------");
    printf("\nbonus de reembaralhamento:\t %d\n", bonusReembaralhamento);
    printf("bonus de cartas:\t\t copas:%d espadas:%d ouros:%d paus:%d\n", bonus->copas, bonus->espadas, bonus->ouros, bonus->paus);
    printf("-------------------------------------------------------");
    printf("\nMenu\n\n");
    n++;printf("%d. reposicionar cartas\t",n);
    n++;printf("%d. descartar cartas\t",n);
    n++;printf("%d. cumprir tarefas\t",n);
    n++;printf("%d. reenbaralhar tudo\t",n);
    n++;printf("%d. finalizar turno\t",n);
    n++;printf("%d. sair\t",n);

    printf("Escolha uma opcao: ");
    scanf("%d", &escolha);
    
    return escolha;
}

void menuTurno(int turno, Fila *fila) {
    printf("-------------------------------------------------------");
    printf("\nTurno: %d", turno + 1);
    printf("\nTarefas: ");

    if (estaVazia(fila)) {
        printf(" Nenhuma tarefa na fila.\n");
        return;
    }

    Node* atual = fila->head;
    while (atual != NULL) {
        Tarefa t = atual->tarefa;
        printf("%d (P-%d E-%d O-%d C-%d) ", 
               t.prazo, t.pausDemandados, t.espadasDemandadas, 
               t.ourosDemandados, t.copasDemandadas);
        atual = atual->next;
    }

    printf("\n-------------------------------------------------------\n");
}

void menuMonte(int numeroCartas, int descarte) {
    printf("-------------------------------------------------------");
    printf("\nMonte(%d)\tDescarte(%d)\n", numeroCartas, descarte);
    printf("-------------------------------------------------------\n");
}
