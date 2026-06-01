#ifndef INTERFACECIRC_H
#define INTERFACECIRC_H

typedef struct no Tno;
typedef struct lista TCLista;
Tno* criarNo (int);
TCLista* criarLista();
int inserir(TCLista*, int);
int print(TCLista* lista);

#endif