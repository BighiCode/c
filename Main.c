#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "Arquivo.h"
#include "Opcoes.h"
int main(int argc, char const *argv[])
{
    TCarta cartas[52], carta;
    lerArquivo(cartas);

    carta = sorteiaCarta(cartas);
    
    printf("\nnome: %s \nface: %s \nnaipe: %c \nvalor: %d",carta.nome, carta.face, carta.naipe, carta.valor);

    return 0;
}