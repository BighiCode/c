#include "Lista.h"

void sortearCartas(Tno** cabeca, int quantidade, int numCartasRestantes);
TCarta sortearCarta(Tno** cabeca, int numCartasRestantes);
void reposicionarCartas(Tno** cabeca, int p1, int p2);
void descartarCartas(Tno** cabeca, int quantidade, Bonus* bonus);
void cumprirTarefas(Bonus *bonus,Fila* fila);