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
    printf("\nBonus de reembaralhamento:\t %d\n", bonusReembaralhamento);
    printf("Bonus de cartas:\t Copas:%d Espadas:%d Ouros:%d Paus:%d\n", bonus->copas, bonus->espadas, bonus->ouros, bonus->paus);
    printf("-------------------------------------------------------");
    printf("\nMenu:\n\n");
    n++;printf("%d - Reposicionar cartas\t",n);
    n++;printf("%d - Descartar cartas\t",n);
    n++;printf("%d - Cumprir tarefas\t",n);
    n++;printf("%d - Reembaralhar tudo\t",n);
    n++;printf("%d - Finalizar turno\t",n);
    n++;printf("%d - Encerrar o jogo\n",n);

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
        printf("%d (Copas: %d Espadas: %d Ouros: %d Paus: %d) ", 
               t.prazo, t.copasDemandadas, t.espadasDemandadas, 
               t.ourosDemandados, t.pausDemandados);
        atual = atual->next;
    }

    printf("\n-------------------------------------------------------\n");
}

void menuMonte(int numeroCartas, int descarte) {
    printf("-------------------------------------------------------");
    printf("\nMonte: %d\tDescarte:%d\n", numeroCartas, descarte);
}
