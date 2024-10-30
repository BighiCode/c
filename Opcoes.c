#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "Arquivo.h"
#include "Opcoes.h"

/**
 * @param cartas Um ponteiro para um array do tipo TCartas
 * @returns A carta sorteada
 * @brief Funcao que sorteia uma carta aleatoriamente do array
 * @author BIGHI
 */
TCarta sorteiaCarta(TCarta *cartas){
     srand(time(NULL));
     int i = rand() % 52;
     return *(cartas+i);
}