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
int menu2(){
    int escolha;
    printf("\n\n-------------------------------------------------------");
    printf("\nMenu\n\n");
    printf("1. reposicionar cartas\n");
    printf("2. embaralhar cartas\n");
    printf("3. Sair\n");
    printf("Escolha uma opcao: ");
    scanf("%d", &escolha);
    return escolha;
}