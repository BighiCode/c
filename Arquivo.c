#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "Arquivo.h"

/**
 * @param cartas Um ponteiro para um array do tipo TCartas
 * @returns Void
 * @brief Função que lê o arquivo cartas.txt e armazena as informações em um array;
 * Ela modifica diretamente o arquivo passado, ja que usa passagem por referencia;
 * Ele lê até o final do arquivo mas o vetor tem tamanho fixo;
 * @author BIGHI
 */
void lerArquivo(TCarta *cartas)
{
    FILE* arqCartas;
    arqCartas = fopen("cartas.txt", "r");
    if (arqCartas == NULL)
    {
        printf("Erro ao abrir o arquivo");
        exit(1);        
    }else{
        int i = 0;
        while(fscanf(arqCartas, "%2s %c %d %[^\n]", cartas[i].face, &cartas[i].naipe, &cartas[i].valor, cartas[i].nome) == 4){
            i++;
        }
        fclose(arqCartas);
    }
}
