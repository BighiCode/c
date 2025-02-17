#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <windows.h>

/*
* Definição do tipo TCarta
*
    *char face[3] - Face da Carta
    *char naipe - Naipe da Carta
    *int valor - Valor da Carta
    *char nome[20] - Nome da Carta
*/
typedef struct TCarta {
    char face[3];
    char naipe;
    int valor;
    char nome[20];
} TCarta;

typedef struct bonus {
    int copas;
    int espadas;
    int ouros;
    int paus;
} Bonus;

int lerArquivo(TCarta *cartas);
void embaralhar(TCarta *vetor, int tamanho);