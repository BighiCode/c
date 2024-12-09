#include "Lista.h"
#include <stdlib.h>


createLista(){
    Tno* cabeca = (Tno*)malloc(sizeof(Tno));
    cabeca->prox = NULL;
    return cabeca;
}
Tno* criaNoh(TCarta carta){
    Tno* noh = (Tno*)malloc(sizeof(Tno));
    noh->carta = carta;
    noh->prox = NULL;
    return noh;
}