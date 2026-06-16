#ifndef INTERFACEED_H
#define INTERFACEED_H

typedef struct no Tno;
typedef struct lista Tlista;
Tno* criarNo(int);
Tlista* criarLista();
Tlista* inserir(Tlista*, int);
int edMundo(int N, int M);

#endif