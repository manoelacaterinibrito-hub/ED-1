#ifndef INTERFACE_H
#define INTERFACE_H

typedef struct no Tno;
typedef struct lista TLista;
Tno* criarNo (int);
TLista* criarLista();
int inserir(TLista*, int);
void inserirInicio(TLista*, int);
int print(TLista*);
int remover(TLista* lista);
TLista* concatenarListas(TLista*, TLista*);
int removerElementos(TLista*, int);
int maiorElemento (TLista* lista, int*, int*);
TLista* pares(TLista*);
TLista* juncao(TLista*);
TLista* inverte(TLista*);


#endif