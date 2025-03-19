#include "Opcoes.h"
#include "Pilha.h"
#include "Arvore.h"

#define REPEAT(n, str) for (int i = 0; i < (n); i++) printf(str)

int main()
{
//inicializando funcoes de bibliotecas
    SetConsoleOutputCP(65001);
    time_t currentTime = time(NULL);
    srand((unsigned int)currentTime);
    
//inicializando variaveis
    int PontuacaoFinal = 0;
    int *antecedencia = (int*)malloc(sizeof(int));
    *antecedencia = 0;
    TCarta cartas[52],aux[52],carta;
    Tarefa Tarefas[10];
    int numeroCartas, escolha, numeroCartasRestantes = 52;
    int p1,p2, quantidade, turno = 0;
    Tno* Tcabeca = NULL;
    Tno* TCmao = NULL;
    TCarta *descartados;
    int bonusReembaralhamento = 0;
    int numeroDeCartasDescartadas = 0;

//lendo arquivos 
    lerArquivoTarefas(Tarefas);
    numeroCartas = lerArquivo(cartas);
    printf("Numero de cartas lidas: %d\n", numeroCartas);
        
//chamando funções   
    Fila* fila = criarFila();
    Pilha* pilha = (Pilha*) malloc(sizeof(Pilha));

    Pilha* descarte = (Pilha*) malloc(sizeof(Pilha));
    NoArvore *arvoreDescarte = criarArvore();// aponta pra NULL kkkkkkkkk

    inicializarPilha(descarte);
    inicializarPilha(pilha);
    Bonus *bonus = (Bonus*)malloc(sizeof(Bonus));
    Bonus *bonusUSADO = (Bonus*)malloc(sizeof(Bonus));
    Bonus *desbonusTarefas = (Bonus*)malloc(sizeof(Bonus));
    iniciaBonus(bonus);
    iniciaBonus(bonusUSADO);
    iniciaBonus(desbonusTarefas);

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

        menuMonte(numeroCartasRestantes,numeroDeCartasDescartadas);

        menuTurno(turno, fila);

        printf("\nMao:\t");

        imprimirCartas(TCmao,getTamanhoLista(TCmao));
        
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

                numeroDeCartasDescartadas += quantidade;
                
                
                descartados = (TCarta*)malloc(quantidade*sizeof(TCarta));
                descartarCartas(&TCmao, quantidade, bonus, descartados);
                inserirCartasNaPilha(descarte, descartados, quantidade);
                free(descartados);
                break;

            case 3:
                bonusReembaralhamento = cumprirTarefas(bonus,fila,antecedencia);
                break;

            case 4:
                if(bonusReembaralhamento > 0){
                    bonusReembaralhamento -= 1;
                    
                    descartados = (TCarta*)malloc(getTamanhoLista(TCmao)*sizeof(TCarta));
                    printf("descartados: %d\n",getTamanhoLista(TCmao));
                    int auxdescarte = getTamanhoLista(TCmao);
                    descartesSemPontos(&TCmao, auxdescarte, descartados);
                    printf("descartados: %d\n",getTamanhoLista(TCmao));
                    inserirCartasNaPilha(descarte, descartados, auxdescarte);
                    free(descartados);
                    TranferirPilha(pilha, descarte, numeroCartasRestantes);
                    numeroCartasRestantes = 0;
//-------------------------------------------------------------------------------------
                    //shold change
                    passarPilhaParaVetor(descarte,aux);
                    for(int z = 0; z<52;z++){
                        printf("%s\t%d\n",aux[z].nome,z);
                    }
                    

                    
                    embaralhar(aux,numeroCartas);


                    numeroCartasRestantes = numeroCartas;
                    numeroDeCartasDescartadas = 0;
                    inserirCartasNaPilha(pilha, aux, numeroCartas);
//-------------------------------------------------------------------------------------
                    numeroCartasRestantes += comprarCartasDaPilha(&TCmao, pilha, 5);
                    break;
                }else{
                    printf("não foi possivel reenbaralhar, falta bonus!");
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