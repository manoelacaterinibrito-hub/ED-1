#ifndef INTERFACE_H
#define INTERFACE_H

typedef struct no Tno;
typedef struct lista TLista;
Tno* criarNo (int);
TLista* criarLista();
int inserir(TLista*, int);
int print(TLista*);
TLista* concatenarListas(TLista*, TLista*);
TLista* removerElement(TLista*, int );

#endif