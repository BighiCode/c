#include "Opcoes.h"

int main()
{
    time_t currentTime = time(NULL);
    srand((unsigned int)currentTime);
    
    int numeroCartas, escolha, numeroCartasRestantes = 52;
    int p1,p2;

    Tno* Tcabeca = NULL;


    TCarta cartas[52],carta;
    TCarta* mao = malloc(5 * sizeof(TCarta));

    numeroCartas = lerArquivo(cartas);
    printf("Numero de cartas lidas: %d\n", numeroCartas);

    inserirCartas(&Tcabeca, cartas, numeroCartas);
    

    while(1){
        escolha = menu1();
        switch(escolha){
            case 1:
                sortearCartas(&Tcabeca, 5,numeroCartasRestantes);
                numeroCartasRestantes-= 5;
                break;
            case 2:
                return 0;
            default:
                break;
        }
        break;
    }

    while (1)
    {
        imprimirCartas(Tcabeca,5);
        escolha = menu2();
        switch(escolha){
            case 1:
                printf("Reposicionar cartas\n");
                printf("Posicao 1: ");
                scanf("%d", &p1);
                printf("Posicao 2: ");
                scanf("%d", &p2);
                reposicionarCartas(&Tcabeca, p1 - 1, p2 - 1);
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