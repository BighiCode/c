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
int menu2(Bonus* bonus){
    int escolha;
    int n = 0;
    printf("\n-------------------------------------------------------");
    printf("\nbonus:\n");
    printf("copas:%d espadas:%d ouros:%d paus:%d\n", bonus->copas, bonus->espadas, bonus->ouros, bonus->paus);
    printf("-------------------------------------------------------");
    printf("\nMenu\n\n");
    n++;printf("%d. reposicionar cartas\n",n);
    n++;printf("%d. descartar cartas\n",n);
    n++;printf("%d. cumprir tarefas\n",n);
    n++;printf("%d. #reenbaralhar tudo\n",n);
    n++;printf("%d. finalizar turno\n",n);
    n++;printf("%d. Sair\n",n);

    printf("Escolha uma opcao: ");
    scanf("%d", &escolha);
    return escolha;
}

void menuTurno(int turno){

    printf("-------------------------------------------------------");
    printf("\nTurno: %d", turno);
    printf("\nTarefas: ");


}