#include "Opcoes.h"

int main()
{
     time_t currentTime = time(NULL);
    srand((unsigned int)currentTime);
    
    TCarta cartas[52],carta;
    int numeroCartas, escolha;
    Tno* Tcabeca = NULL;
    TCarta **cabeca = NULL;
    TCarta* mao = malloc(5 * sizeof(TCarta));
    numeroCartas = lerArquivo(cartas);

    inserirCartas(&Tcabeca, cartas, numeroCartas);
    

    while(1){
        escolha = menu1();
        switch(escolha){
            case 1:
                sortearCartas(&Tcabeca, mao, 5);
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
        mostrarMao(mao);
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