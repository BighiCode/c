#include "Menu.h"

typedef struct Tno {
    TCarta carta;
    struct Tno *prox; 
} Tno;

void inserirNoInicio(Tno** cabeca, TCarta carta);
void inserirNoFinal(Tno** cabeca, TCarta carta);
void inserirCartas(Tno** cabeca, TCarta* cartas, int numCartas);
void imprimirCartas(Tno* cabeca, int quantidade);
void removerCartas(Tno** head,Tno *nodeToRemove);
void copiarParaMao(Tno** cabeca, Tno** mao);