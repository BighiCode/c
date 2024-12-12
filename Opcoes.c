#include "Opcoes.h"


/**
 * ARQ opcoes
 * 
 * @return ponteiro para a nova mão
 */
void sortearCartas(Tno** cabeca, int quantidade, int numCartasRestantes) {

    TCarta mao[quantidade];

    for(int i = 0; i < quantidade; i++){
        mao[i] = sortearCarta(cabeca, numCartasRestantes);
        numCartasRestantes--;
    }

    inserirCartas(cabeca, mao, quantidade);

}

/**
 * ARQ opcoes
 * 
 * sorteia as cartas da mão
 * dps remove elas da lista
 * @return cartas sorteadas
 */
TCarta sortearCarta(Tno** cabeca, int numCartasRestantes) {
    if (*cabeca == NULL) {
        printf("Erro: lista de cartas vazia\n");
        exit(EXIT_FAILURE);
    }

    Tno *temp = *cabeca;
    if(numCartasRestantes == 0){printf("Erro1: lista de cartas menor que a quantidade solicitada\n"); return temp->carta;}
    int posicao = rand() % numCartasRestantes;
    for (int i = 0; i < posicao; i++) {
        if (temp->prox == NULL) {
            printf("Erro2: lista de cartas menor que a quantidade solicitada\n");
            exit(EXIT_FAILURE);
        }
        temp = temp->prox;
    }
    
    TCarta carta = (temp)->carta;
    removerCartas(cabeca, temp);
    return carta;
}

void reposicionarCartas(Tno** cabeca, int p1, int p2) {
    if (*cabeca == NULL || p1 == p2) {
        return;
    }

    Tno* carta1 = *cabeca;
    Tno* carta2 = *cabeca;
    Tno* anterior1 = NULL;
    Tno* anterior2 = NULL;

    // Encontra a carta na posição p1
    for (int i = 0; i < p1; i++) {
        if (carta1 == NULL) {
            return;
        }
        anterior1 = carta1;
        carta1 = carta1->prox;
    }


    // Encontra a carta na posição p2
    for (int i = 0; i < p2; i++) {
        if (carta2 == NULL) {
            return;
        }
        anterior2 = carta2;
        carta2 = carta2->prox;
    }


    // Troca as cartas
    if (anterior1 == NULL) {
        *cabeca = carta2;
    } else {
        anterior1->prox = carta2;
    }

    if (anterior2 == NULL) {
        *cabeca = carta1;
    } else {
        anterior2->prox = carta1;
    }

    // Troca os próximos ponteiros
    Tno* prox1 = carta1->prox;
    carta1->prox = carta2->prox;
    carta2->prox = prox1;
}


void descartarCartas(Tno** cabeca, int quantidade, Bonus* bonus) {
    if (*cabeca == NULL) {
        return;
    }

    Tno* atual = *cabeca;
    TCarta descarte[quantidade];

    for (int i = 0; i < quantidade; i++) {
        descarte[i] = atual->carta;
        atual = atual->prox;
    }

    printf("Cartas descartadas:\n");
    for (int i = 0; i < quantidade; i++)
    {
        printf("%s %c\t", descarte[i].face, descarte[i].naipe);
    }
    printf("\n");

    for (int i = 0; i < quantidade; i++) {
         removerCartas(cabeca, *cabeca);
    }

    for (int i = 0; i < quantidade; i++)
    {
        if(descarte[i].naipe == 'C'){
            bonus->copas += descarte[i].valor;
        }
        if(descarte[i].naipe == 'E'){
            bonus->espadas += descarte[i].valor;
        }
        if(descarte[i].naipe == 'O'){
            bonus->ouros += descarte[i].valor;
        }
        if(descarte[i].naipe == 'P'){
            bonus->paus += descarte[i].valor;
        }
    }

    int face[quantidade],naipe[quantidade],sequencia = 0;

    for (int i = 0; i < quantidade; i++)
    {
        face[i] = 0;
        naipe[i] = 0;
    }
    
    int streak = 0;

    for(int i = 0; i < quantidade; i++){
        for (int j = 0; j < quantidade; j++)
        {
            if(descarte[i].face == descarte[j].face){
                face[i] += 1;
            }
            if(descarte[i].naipe == descarte[j].naipe){
                naipe[i] += 1;
            }
        }
        
    }

    for(int i = 0; i < quantidade; i++){
        int val;
        for(int j = 0; j < quantidade; j++){
            if((descarte[i].valor == val+1) || (descarte[i].valor == 1 && val == 13) || i == 0){
                val = descarte[i].valor;
                sequencia++;
            }
        }
    }
    sequencia++;

    int maiorFace = 0, maiorNaipe = 0;
    for (int i = 0; i < quantidade; i++){
        if(face[i] > maiorFace){
            maiorFace = face[i];
        }
        if(naipe[i] > maiorNaipe){
            maiorNaipe = naipe[i];
        }
    }

    if(maiorFace >= 4){
        char c;
        printf("escolha um naipe para receber a bonificiacao(C,E,O,P) quadra:\n");
        scanf(" %c", &c);
        if(c == 'C'){
            bonus->copas += 20;
        }
        if(c == 'E'){
            bonus->espadas += 20;
        }
        if(c == 'O'){
            bonus->ouros += 20;
        }
        if(c == 'P'){
            bonus->paus += 20;
        }
        return;
    }

    if(maiorNaipe >= 3){
        char c;
        printf("escolha um naipe para receber a bonificiacao(C,E,O,P) Mesmo naipe:\n");
        scanf(" %c", &c);
        if(c == 'C'){
            bonus->copas += 3*maiorNaipe;
        }
        if(c == 'E'){
            bonus->espadas += 3*maiorNaipe;
        }
        if(c == 'O'){
            bonus->ouros += 3*maiorNaipe;
        }
        if(c == 'P'){
            bonus->paus += 3*maiorNaipe;
        }
        return;
    }

    if(sequencia >= 3){
        char c;
        printf("escolha um naipe para receber a bonificiacao(C,E,O,P) sequencia:\n");
        scanf(" %c", &c);
        if(c == 'C'){
            bonus->copas += 2*sequencia;
        }
        if(c == 'E'){
            bonus->espadas += 2*sequencia;
        }
        if(c == 'O'){
            bonus->ouros += 2*sequencia;
        }
        if(c == 'P'){
            bonus->paus += 2*sequencia;
        }
        return;
    }

    

    if(maiorFace == 3){
        char c;
        printf("escolha um naipe para receber a bonificiacao(C,E,O,P) trinca:\n");
        scanf(" %c", &c);
        if(c == 'C'){
            bonus->copas += 5;
        }
        if(c == 'E'){
            bonus->espadas += 5;
        }
        if(c == 'O'){
            bonus->ouros += 5;
        }
        if(c == 'P'){
            bonus->paus += 5;
        }
        return;
    }

    if (maiorFace == 2)
    {
        char c;
        printf("escolha um naipe para receber a bonificiacao(C,E,O,P) par:\n");
        scanf(" %c", &c);
        if(c == 'C'){
            bonus->copas += 2;
        }
        if(c == 'E'){
            bonus->espadas += 2;
        }
        if(c == 'O'){
            bonus->ouros += 2;
        }
        if(c == 'P'){
            bonus->paus += 2;
        }
        return;
    }
    

    
}