#include "interfacedance.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct no{
    int info;
    struct no* prox;
}Tno;

typedef struct lista{
    Tno* inicio;
}TLista;

Tno* criarNo(int info){
    Tno* novoNo = malloc(sizeof(Tno));

    if(novoNo!=NULL){
        novoNo->info=info;
        novoNo->prox=NULL;
    }
    return novoNo;
}

TLista* criarLista(){
    TLista* novaLista = malloc(sizeof(TLista));
    if(novaLista!=NULL){
        novaLista->inicio=NULL;
    }
    return novaLista;
}

int inserir(TLista* lista, int info){
    Tno* novo = criarNo(info);
    if(novo==NULL){
        return 0;
    }
    if(lista->inicio == NULL){
        lista->inicio = novo;
        novo->prox = novo;
    }
    Tno *aux=lista->inicio;
    while(aux->prox!=lista->inicio){
            aux=aux->prox; 
        }
    aux->prox=novo;
    novo->prox=lista->inicio;
    return 1;
}

int EDdanca(int N, int Q){
    int i, S;
    TLista* lista = criarLista();
    TLista* tempoDj = criarLista();

    for(i=1; i<=N ; i++){
        inserir(lista, i);
    }

    for(i=1; i<=Q; i++){
        printf("digite o tempo: (tem q ser menor que o anterior)");
        scanf("%d", &S);
        inserir(tempoDj, S);
    }

    Tno* atual = lista->inicio;
    Tno* tempoAtual=tempoDj->inicio;

    Tno* ant = lista->inicio;

    while(ant->prox!=lista->inicio){
        ant=ant->prox;
    }

    while(atual->prox!=atual){
        S = tempoAtual->info;

        for(i=1;i<S;i++){
            ant = atual;
            atual = atual->prox;
        }
        ant->prox = atual->prox;

        if(atual==lista->inicio){
            lista->inicio=atual->prox;
        }
        free(atual);
        atual=ant->prox;
        tempoAtual = tempoAtual->prox;
    }
    printf("a cadeira que sobrou: %d\n", lista->inicio->info);
}