#include "interfacecirc.h"
#include <stdlib.h>
#include <stdio.h>

//funçoes da lista circular 
//repare que ate um certo momento as funçoes são iguais as lista estatica
//pode fazer ate as create igual a estatica
typedef struct no{
    int info;
    struct no* prox;
}Tno;
//aux->prox → endereço do próximo nó
//aux->info → valor armazenado no nó

typedef struct lista{
    Tno* inicio;
}TCLista;

Tno* criarNo (int info){
    Tno* novoNo = malloc (sizeof(Tno));

    if(novoNo!=NULL){
        novoNo->info=info;
        novoNo->prox=NULL;
    }
    return novoNo;
}

TCLista* criarLista(){
    TCLista* novaLista = malloc (sizeof(TCLista));
    //se nova lista é diferente de vazia, esvazie
    if(novaLista!=NULL){
        novaLista->inicio=NULL;
    }
    return novaLista;
}

int inserir(TCLista* lista, int info){
    Tno* novo= criarNo(info);
    //se novo for vazio/nao existente, erro
    if(novo==NULL){
        return 0; //verifica se a lista existe
    }
    //se inicio for vazio, inicio da lista recebe novo
    if(lista->inicio==NULL){
        lista->inicio=novo;
    }else{
        Tno *aux = &(lista->inicio);
        //enquanto o inicio for diferente do final ...
        while(aux->prox!=lista->inicio){
            //...final recebe o proximo no
            aux = aux->prox;
            aux->prox=novo;
        }
    }
    novo->prox = lista->inicio;
    return 1;
}

int print(TCLista* lista){
    Tno* aux = lista->inicio;
    //verifica se não estar vazio e ...
    //(boa pratica de programação)
    if(aux!=NULL){
        //faça ... enquanto o final for diferente do inicio
        do{
            printf("%d->", aux->info);
            //aux recebe informação do proximo aux
            aux=aux->prox;
        }while(aux!=lista->inicio);    
    }
    putchar('\n');
}