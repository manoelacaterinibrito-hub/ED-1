#include <stdio.h>
#include "interfaceed.h"

int main(){
    int N,M;
    printf("informe a quantidade de soldados:\n");
    scanf("%d", &N);
    printf("informe um numero inteiro positivo\n");
    scanf("%d", &M);
    edMundo(N, M);
}