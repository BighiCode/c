#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "Arquivo.h"
#include "Opcoes.h"
int main()
{
    TCarta cartas[52], carta;
    lerArquivo(cartas);

    int escolha = 1;

    while(escolha != 9){
        printf("\n\nEscolha uma opcao: \n1 - Sortear \n9 - Sair\n");
        scanf("%d", &escolha);
        if(escolha == 1){
            carta = sorteiaCarta(cartas);
            printf("\nnome: %s \nface: %s \nnaipe: %c \nvalor: %d",carta.nome, carta.face, carta.naipe, carta.valor);
        }
    }
    return 0;
}