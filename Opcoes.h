#ifndef OPCOES_H
#define OPCOES_H

#include "Lista.h"


void reposicionarCartas(Tno** cabeca, int p1, int p2);
void descartarCartas(Tno** cabeca, int quantidade, Bonus* bonus, TCarta* descarte);
int cumprirTarefas(Bonus *bonus,Bonus *bonusUsado,Fila* fila, int * antecendencia);
int comprarCartas(Tno** mao, Tno **cabeca,int n);
void descartesSemPontos(Tno** cabeca, int quantidade, TCarta* descarte);
void iniciaBonus(Bonus* bonus);
int somaBonus(Bonus* bonus);
#endif