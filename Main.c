#include "Opcoes.h"
#include "Pilha.h"


#define REPEAT(n, str) for (int i = 0; i < (n); i++) printf(str)

int main()
{
    SetConsoleOutputCP(65001);

    time_t currentTime = time(NULL);
    srand((unsigned int)currentTime);
    


    Tarefa Tarefas[10];
    Fila* fila = criarFila();

    int numeroCartas, escolha, numeroCartasRestantes = 52;
    int p1,p2, quantidade, turno = 0;

    Tno* Tcabeca = NULL;
    Tno* TCmao = NULL;

    Bonus *bonus = (Bonus*)malloc(sizeof(Bonus));
    bonus->copas = 0;
    bonus->espadas = 0;
    bonus->ouros = 0;
    bonus->paus = 0;

    TCarta cartas[52],carta;
   
    //lendo arquivos
    lerArquivoTarefas(Tarefas);
    numeroCartas = lerArquivo(cartas);
    printf("Numero de cartas lidas: %d\n", numeroCartas);

    inserirCartas(&Tcabeca, cartas, numeroCartas);

    while(1){
        escolha = menu1();

        

        switch(escolha){
            case 1:
                numeroCartasRestantes+= comprarCartas(&TCmao, &Tcabeca, 5);
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
        REPEAT(100, "\n");
        menuTurno(turno, fila);
        //imprimirTarefas(Tarefas, 10, turno);
        printf("\n-------------------------------------------------------");
        printf("\nMao:\t");
        imprimirCartas(TCmao,5);
        escolha = menu2(bonus);
    
        switch(escolha){
            case 1:
                printf("Reposicionar cartas\n");
                printf("Posicao 1: ");
                scanf("%d", &p1);
                printf("Posicao 2: ");
                scanf("%d", &p2);
                reposicionarCartas(&TCmao, p1 - 1, p2 - 1);
                break;
            case 2:
                printf("Remover cartas\n");
                printf("Quantidade: ");
                scanf("%d", &quantidade);
                descartarCartas(&TCmao, quantidade, bonus);
                break;
            case 3:
                cumprirTarefas( bonus,fila);
                break;
            case 5:
            
                turno++;

                numeroCartasRestantes+= comprarCartas(&TCmao, &Tcabeca, 5 - getTamanhoLista(TCmao));

                for(int i = 0; i < 10; i++){
                   
                    if(Tarefas[i].turnoDeAparecimento == turno){
                        adicionarFila(fila, Tarefas[i]);
                    }
                }

                diminuirPrazo(fila);
                fiscalizador(fila);

                break;
                
            case 6:
                return 0;
            default:
                printf("Opcao invalida\n");
                break;
            
        }
    }
    
    return 0;
}