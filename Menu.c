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
    printf("\n\n-------------------------------------------------------");
    printf("\nbonus:\n");
    printf("copas:%d espadas:%d ouros:%d paus:%d\n", bonus->copas, bonus->espadas, bonus->ouros, bonus->paus);
    printf("\n\n-------------------------------------------------------");
    printf("\nMenu\n\n");
    printf("1. reposicionar cartas\n");
    printf("2. descartar cartas\n");
    printf("3. Sair\n");
    printf("Escolha uma opcao: ");
    scanf("%d", &escolha);
    return escolha;
}