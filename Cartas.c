#include "Cartas.h"

/**
 * 
 * @param cartas Um ponteiro para um array do tipo TCartas
 * 
 * Função que lê o arquivo cartas.txt e armazena as informações em um array;
 * Ela modifica diretamente o arquivo passado, ja que usa passagem por referencia;
 * Ele lê até o final do arquivo mas o vetor tem tamanho fixo;
 * 
 * @returns NumeroDeCartas
 */
int lerArquivo(TCarta *cartas)
{
    FILE* arqCartas;
    arqCartas = fopen("cartas.txt", "r");
    if (arqCartas == NULL)
    {
        printf("Erro ao abrir o arquivo");
        return 0;       
    }else{
        int i = 0;
        while(fscanf(arqCartas, "%2s %c %d %[^\n]", cartas[i].face, &cartas[i].naipe, &cartas[i].valor, cartas[i].nome) == 4){
            i++;
        }
        fclose(arqCartas);
        embaralhar(cartas, 52);
        return i;
    }

    

}

void embaralhar(TCarta *vetor, int tamanho) {
    srand(time(NULL)); // Inicializa a semente do gerador de números aleatórios

    for (int i = tamanho - 1; i > 0; i--) {
        int j = rand() % (i + 1); // Sorteia um índice entre 0 e i

        // Troca vetor[i] com vetor[j] corretamente
        TCarta temp = vetor[i];
        vetor[i] = vetor[j];
        vetor[j] = temp;
    }
}
