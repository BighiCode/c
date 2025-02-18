#include "Opcoes.h"
#include "Pilha.h"


#define REPEAT(n, str) for (int i = 0; i < (n); i++) printf(str)

int main()
{
//inicializando funcoes de bibliotecas
    SetConsoleOutputCP(65001);
    time_t currentTime = time(NULL);
    srand((unsigned int)currentTime);
    
//inicializando variaveis
    TCarta cartas[52],carta;
    Tarefa Tarefas[10];
    int numeroCartas, escolha, numeroCartasRestantes = 52;
    int p1,p2, quantidade, turno = 0;
    Tno* Tcabeca = NULL;
    Tno* TCmao = NULL;
    TCarta *descartados;
    int bonusReembaralhamento = 0;

//lendo arquivos 
    lerArquivoTarefas(Tarefas);
    numeroCartas = lerArquivo(cartas);
    printf("Numero de cartas lidas: %d\n", numeroCartas);
        
//chamando funções   
    Fila* fila = criarFila();
    Pilha* pilha = (Pilha*) malloc(sizeof(Pilha));
    Pilha* descarte = (Pilha*) malloc(sizeof(Pilha));
    inicializarPilha(descarte);
    inicializarPilha(pilha);
    Bonus *bonus = (Bonus*)malloc(sizeof(Bonus));
    bonus->copas = 0;
    bonus->espadas = 0;
    bonus->ouros = 0;
    bonus->paus = 0;

//inserindo 
    //inserirCartas(&Tcabeca, cartas, numeroCartas); legacy
    inserirCartasNaPilha(pilha, cartas, numeroCartas);


//menu 1
    while(1){

        escolha = menu1();

        switch(escolha){
            case 1:
                //numeroCartasRestantes+= comprarCartas(&TCmao, &Tcabeca, 5);
                numeroCartasRestantes+= comprarCartasDaPilha(&TCmao, pilha, 5 - getTamanhoLista(TCmao));
                break;
            case 2:
                return 0;
            default:
                break;
        }
        break;
    }

//menu2
    while (1)
    {
        //"limpa tela"
        REPEAT(100, "\n");

        menuMonte(numeroCartasRestantes);

        menuTurno(turno, fila);

        printf("\nMao:\t");

        imprimirCartas(TCmao,5);
        
        escolha = menu2(bonus, bonusReembaralhamento);

    
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
                numeroCartasRestantes -= quantidade;
                descartados = (TCarta*)malloc(quantidade*sizeof(TCarta));
                descartarCartas(&TCmao, quantidade, bonus, descartados);
                inserirCartasNaPilha(descarte, descartados, quantidade);
                free(descartados);
                break;

            case 3:
                bonusReembaralhamento = cumprirTarefas(bonus,fila);
                break;

            case 4:
                if(bonusReembaralhamento > 0){
                    bonusReembaralhamento -= 1;
                    //
                    break;
                }

            case 5:
                turno++;
                //numeroCartasRestantes+= comprarCartas(&TCmao, &Tcabeca, 5 - getTamanhoLista(TCmao));
                numeroCartasRestantes+= comprarCartasDaPilha(&TCmao, pilha, 5 - getTamanhoLista(TCmao));
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