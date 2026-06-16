#include "interfaceed.h"
#include <stdio.h>
#include <stdlib.h>

//uso de lista circular encadeada

typedef struct no{
    int info;
    struct no* prox;
}Tno;

typedef struct lista{
    Tno* inicio;
}Tlista;

Tno* criarNo(int info){
    Tno* novoNO = malloc(sizeof(Tno));
    if(novoNO!=NULL){
        novoNO->info=info;
        novoNO->prox=NULL;
    }
    return novoNO;
}

Tlista* criarLista(){
    Tlista* novaLista = malloc(sizeof(Tlista));
    if(novaLista!=NULL){
        novaLista->inicio=NULL;
    }
    return novaLista;
}

Tlista* inserir(Tlista* lista, int info){
    //cria um novo no para adicionar na lista e ele vai ter tal informação que veio da main
    Tno* novo = criarNo(info);
    //se novo for vazia, erro
    if(novo==NULL){
        return 0; //erro
    }
    //se inicio for vazio, então preencha com novo
    if(lista->inicio==NULL){
        lista->inicio=novo;
    // se não for vazio...    
    }else{
        //vai criar uma nova variavel chamada aux e pegar o endereço do inicio
        Tno* aux =lista->inicio;
        //enquanto final for diferente do inicio (foca nos campos inicio e prox(fim))
        //prox tambem é fim
        while(aux->prox!=lista->inicio){
            aux=aux->prox;  
        }
        aux->prox=novo;
    }
    novo->prox=lista->inicio;
    return lista;
}


int edMundo(int N, int M){
    int i;
    Tlista* lista = criarLista();
   //if para inserir os n soldados
    for(i=1;i<=N;i++){
    inserir(lista, i);
   }
   
   Tno* atual = lista->inicio;// pra saber quem estar com a moeda atual e ja inicializa no inicio da fila
   Tno* ant = lista->inicio; // pra saber o anterior de quem estar com a moeda atual (porque quando vai 
   //remover alguem na encadeada, precisa saber quem é o no anterior)
  
   while(ant->prox!=lista->inicio){
        ant=ant->prox;
   }

   //enquanto houver mais de um soldado
   while(atual->prox!=atual){
        //conta m-1 passos
        for(i=1;i<M;i++){
            ant = atual;
            atual = atual->prox;
        }
        ant->prox = atual->prox;
        //se caso o atual for inicio...
        if(atual == lista->inicio){
            //...inicio recebe o proximo
            lista->inicio=atual->prox;
        }
        free(atual);
        //continua a partir do proximo
        atual=ant->prox;
    }
    printf(" o soldado que restou: %d\n", atual->info);
    
}
