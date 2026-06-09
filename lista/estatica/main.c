#include "interface.h"
#include <stdio.h>

int main(){
    //cria as listas vazias 
    TLista* lista1 = criarLista();
    TLista* lista2 = criarLista();

    int vetor[]={1,2,3,4,5}, i;
    
    for(i=0;i<5;i++){
        //aqui pega o numero do vetor e tenta inserir na listas
        if(!inserir(lista1, vetor[i])){
            printf("nao deu certo pra inserir o vetor[%i]=%i\n", i, vetor[i]);
        }
        print(lista1);
    }
    for(i=4;i>=0;i--){
        //coloca o valor ao contrario
        if(!inserir(lista2, vetor[i])){
            printf("nao deu certo pra inserir o vetor[%i]=%i\n", i, vetor[i]);
        }
        print(lista2);
    }
    //função de concatear as listas
    //tem q criar uma variavel que recebe o resultado da função e mandar printar dps
    TLista *listaconc = concatenarListas(lista1, lista2);
    print(listaconc);
    
    //questão 2
    printf("digite a quantidade que deseja retirar");
    int n;
    scanf("%d", &n);
    int resultado = removerElementos(lista1, n);
    if(resultado){
        printf("Removido com sucesso!\n");
    }else{
        printf("Nao foi possivel remover!\n");
    }

    //questão 3
    int valor, pos;

    if(maiorElemento(lista1, &valor, &pos)){
    printf("Maior valor: %d\n", valor);
    printf("Posicao: %d\n", pos);
    }else{
    printf("Lista vazia!\n");
    }
    //questão 4
    TLista* reposta1 = pares(lista1);
    print(reposta1);  

    //questão 5
    TLista* reposta2 = juncao(lista1);
    print(reposta2);    

    //questão 6
    TLista* reposta3 = inverte(lista1);
    print(reposta3);    

    //questão 7
    

}
 