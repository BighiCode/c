#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "Arquivo.h"
#include "Opcoes.h"
#include "Menu.h"
int main()
{
    TCarta cartas[52], carta;
    lerArquivo(cartas);
    int escolha;

    while(1){
        escolha = menu1();
        switch(escolha){
            case 1:
                break;
            case 2:
                return 0;
            default:
                printf("Opcao invalida\n");
                break;
        }
    }
    
    while (1)
    {
        escolha = menu2();
        switch(escolha){
            case 1:
                break;
            case 2:
                break;
            case 3:
                return 0;
            default:
                printf("Opcao invalida\n");
                break;
        }
    }
    
    return 0;
}