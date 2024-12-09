#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "Opcoes.h"
#include "Menu.h"
#include "Lista.h"
int main()
{
    TCarta cartas[52], carta;
    int numeroCartas, escolha;
    Tno *cabeca = NULL;

    numeroCartas = lerArquivo(cartas);

    inserirCartas(&cabeca, cartas, numeroCartas);
    

    while(1){
        escolha = menu1();
        switch(escolha){
            case 1:
                imprimirCartas(cabeca);
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