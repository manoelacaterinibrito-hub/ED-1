#include <stdio.h>
#include "interfacedance.h"

int main(){
    int C, T;

    printf("informe a quantidade de cadeira:\n");
    scanf("%d", &C);
    printf("informe o tempo do dj\n");
    scanf("%d", &T);
    EDdanca(C, T);
}