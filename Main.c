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
    NoArvore* arvoreDescarte = NULL;
    int PontuacaoFinal = 0;
    int PMin = 1;
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

    //limpa tela
    REPEAT(100, "\n");

//menu 1
    while(escolha != 1){

        escolha = menu1();

        switch(escolha){
            case 1:
                //numeroCartasRestantes+= comprarCartas(&TCmao, &Tcabeca, 5);
                numeroCartasRestantes+= comprarCartasDaPilha(&TCmao, pilha, 5 - getTamanhoLista(TCmao));
                break;
            case 2:
                return 0;
            default:
                printf("Opcao invalida\n");
        }
        
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
                printf("Qual carta quer reposicionar?\n");
                scanf("%d", &p1);
                printf("Para qual posicao?\n");
                scanf("%d", &p2);
                reposicionarCartas(&TCmao, p1 - 1, p2 - 1);
                break;

            case 2:
                printf("Remover cartas\n");
                printf("Quantidade: ");
                scanf("%d", &quantidade);
                if (getTamanhoLista(TCmao) < quantidade) {
                    printf("Quantidade de cartas insuficiente para descarte.\n");
                    break;
                }else{

                    numeroDeCartasDescartadas += quantidade;
                
                    descartados = (TCarta*)malloc(quantidade*sizeof(TCarta));
                    descartarCartas(&TCmao, quantidade, bonus, descartados);
                    inserirCartasNaPilha(descarte, descartados, quantidade);
                    free(descartados);
                    break;
                }
                

            case 3:
                bonusReembaralhamento = cumprirTarefas(bonus,bonusUSADO,fila,antecedencia);
                break;

            case 4:
//-------------------------------------------------------------------------------------
                    //shold change
                if(bonusReembaralhamento > 0){
                    bonusReembaralhamento -= 1;
                    
                    descartados = (TCarta*)malloc(getTamanhoLista(TCmao)*sizeof(TCarta));
                    printf("Descartados: %d\n",getTamanhoLista(TCmao));
                    int auxdescarte = getTamanhoLista(TCmao);
                    descartesSemPontos(&TCmao, auxdescarte, descartados);
                    printf("Descartados: %d\n",getTamanhoLista(TCmao));
                    inserirCartasNaPilha(descarte, descartados, auxdescarte);
                    free(descartados);
                    TranferirPilha(pilha, descarte, numeroCartasRestantes);
                    numeroCartasRestantes = 0;

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
                    printf("Nao foi possivel reembaralhar, falta bonus!");
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
                diminuirPrazo(fila, desbonusTarefas);
                //fiscalizador(fila, desbonusTarefas);
                break;
                
            case 6:

                arvoreDescarte = TranferirPilhaParaArvore(descarte, arvoreDescarte);
                
                PMin = profundidadeMinima(arvoreDescarte);

                //PMin ok
                //atencedencia ok
                //somaBonus(bonusUSADO) ok
                //somaBonus(bonus)/2 ok
                //somaBonus(desbonusTarefas) ok

                PontuacaoFinal = PMin * ( ((*antecedencia) * (somaBonus(bonusUSADO))) + (somaBonus(bonus)/2) ) - somaBonus(desbonusTarefas);  
                printf("\n\nPontuacao final: %d\n", PontuacaoFinal);
                return 0;
                
            default:
                printf("Opcao invalida.\n");
                break;
            
        }
    }
}