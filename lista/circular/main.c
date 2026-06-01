#include "interfacecirc.h"
#include <stdio.h>

int main(){
    TCLista* lista1 = criarLista();
    TCLista* lista2 = criarLista();
    int V[] = {1, 2, 3, 4, 5}, i;
    for(i = 0; i<5; i++)
        if(!inserir(lista1, V[i]))
            printf("Ocorreu um erro ao inserir o V[%i]=%i\n", i, V[i]);
    print(lista1);

    for(i = 4; i>=0; i--)
        if(!inserir(lista2, V[i]))
            printf("Ocorreu um erro ao inserir o V[%i]=%i\n", i, V[i]);
 print(lista2);
    return 0;
}