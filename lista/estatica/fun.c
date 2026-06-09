#include "interface.h"
#include <stdlib.h>
#include <stdio.h>

typedef struct no{
    int info;
    struct no* prox;
}Tno;
//aux->prox → endereço do próximo nó
//aux->info → valor armazenado no nó

typedef struct lista{
    Tno* inicio;
}TLista;

//lista->inicio->endereço do primeiro no da lista

Tno* criarNo(int info){
    Tno* novoNo = malloc (sizeof(Tno));

    if(novoNo!=NULL){
        novoNo->info=info;
        novoNo->prox=NULL;
    }
    return novoNo;
}

TLista* criarLista(){
    TLista* novaLista = malloc (sizeof(TLista));
    //se nova lista é diferente de vazia, esvazie
    if(novaLista!=NULL){
        novaLista->inicio=NULL;
    }
    return novaLista;
}

//insere apenas no final
int inserir(TLista* lista, int info){
    //Crie um novo nó contendo info e guarde o endereço dele em novaLista
    //novaLista não é uma lista inteira, é apenas um no
    Tno* novaLista = criarNo(info);
    if(novaLista==NULL){
        return 0; //se nao der certo a iserção aparece a mensagem da main
    }
    //cria uma variavei tipo no chamada aux e so existe dentro dessa função
    Tno** aux = &(lista->inicio);  
    while(*aux!=NULL){
        aux = &(*aux)->prox;
    }
     *aux = novaLista;
        return 1;
}
// Função auxiliar para inserir no início da lista - usada na questao 6
void inserirInicio(TLista* lista, int info){
    Tno* novo = criarNo(info);

    if(novo == NULL){
        return;
    }

    // O novo nó aponta para o antigo primeiro nó da lista
    novo->prox = lista->inicio;

    // Agora o novo nó passa a ser o primeiro da lista
    lista->inicio = novo;
}

int print(TLista* lista){
    Tno* aux = lista->inicio;
    //enquanto aux for diferente de vazia, printar informação de info que esta dentro de aux 
    while(aux!=NULL){
        printf("%d->", aux->info);
        //aux recebe a informação do proprio aux que aponta pro prox (endereço do proximo nó)
        aux = aux->prox;
    }
    putchar('\n');
}

//nao pediu mas coloquei 
int remover(TLista* lista){
    if(lista==NULL || lista->inicio==NULL){
        return 0;
    }
    //ponteiro auxiliar que vai guardar no que sera removido
    Tno* aux= lista->inicio;
    lista->inicio=aux->prox;

    free(aux);
    return 1;
}

//1. Faça uma função para concatenar duas listas em uma terceira lista que deverá ser retornada
//pela função. Faça duas versões: uma que utilize das funções já implementadas e outra que não usa
//qualquer função já feita do TAD.

TLista* concatenarListas(TLista* lista1, TLista* lista2){
    //cria uma nova lista para adicionar as novas informaçoes juntadas das duas listas
    TLista* lista3 = criarLista();
    //cria uma variavel ponteiro que vai acessar a primeira informação da lista 1
    Tno* aux = lista1->inicio;
    //aqui ela vai inserir as informaçoes enquanto o ponteiro não for vazio
    while(aux!=NULL){
        inserir(lista3, aux->info);
        //o novo ponteiro vai receber o proximo ponteiro
        aux = aux->prox;
    }
    //faz a mesma coisa pra segunda lista 
    aux = lista2->inicio;
    while(aux!=NULL){
        inserir(lista3, aux->info);
        aux=aux->prox;
    }

    return lista3;
}

//2.Faça uma função para remover os n primeiros elementos de uma lista. A função deve retornar se
//a operação foi possível ou não.
int removerElementos(TLista* lista, int n){
    int i;
    if(lista == NULL || lista->inicio == NULL){
        return 0;// erro se a lista n existir 
    }
    Tno* aux;
    //
    for(int i = 0; i < n; i++){
        if(lista->inicio == NULL){
            return 0;
        }
        //aqui guarda o no que sera removido
        aux = lista->inicio;
        //aqui o inicio anda pro proximo no
        lista->inicio = lista->inicio->prox;
        //llibera espaço
        free(aux);
    }
    return 1;
}

//3. Faça uma função para buscar a posição e o valor do maior elemento da lista, os quais
//deverão ser retornados por referência. A função deve retornar se a operação foi possível ou
//não.
int maiorElemento (TLista* lista, int* valor, int* posicao){
    if(lista==NULL || lista->inicio==NULL){
        return 0;//erro
    }

    Tno* aux = lista->inicio;
    int maior = aux->info;
    int posMaior =0;
    int pos=0;

    while(aux != NULL){
        if(aux->info>maior){
            maior=aux->info;
            posMaior=pos;
        }
        aux = aux->prox;
        pos++;
    }
    *valor=maior;
    *posicao=posMaior;
    return 1; 
    
}


//4. Considere uma lista contendo números inteiros positivos. Faça uma função que retorne uma
//nova lista contendo apenas os números pares da lista.
TLista* pares(TLista* lista){
    TLista* ListaPares=criarLista();
    Tno* aux = lista->inicio;
    while(aux!=NULL){
        if(aux->info%2==0){
        inserir(ListaPares, aux->info);
        }
        aux=aux->prox;
    }
    return ListaPares;
}

//5. Fazer uma função para realizar cópia uma lista L1 em outra L2, eliminando os elementos
//repetidos. L2 deverá ser retornada pela função.
TLista* juncao(TLista* lista){
    TLista* L2 = criarLista();
    //acessa o primeiro inicio e guarda em aux
    Tno* aux = lista->inicio;
    //enquanto aux for diferente de vazio, continua
    while(aux!=NULL){
        //para verificar se vai estar repetido mais tarde
       int rep=0;
       //uma variavel pra comparar com a primeira auxliadora
       Tno* aux2=L2->inicio;
       while(aux2!=NULL){
        if(aux->info==aux2->info){
            rep=1;
            break;
        }
        aux2=aux2->prox;
       }
       //se rep for igual a zero 
       if(rep==0){
        //usa a função de inserir na nova lista
        inserir(L2, aux->info);
       }
       //vai pro proximo elemento
       aux=aux->prox;
    }

    return L2;
}

//6. Fazer uma função para inverter uma lista L1 colocando o resultado em L2. L2 deverá ser
//retornada pela função.
TLista* inverte(TLista* lista){
    TLista* L2 = criarLista();
    Tno* aux = lista->inicio;
    
    while(aux!=NULL){
        inserirInicio(L2, aux->info);
        aux=aux->prox;
    }
    return L2;
}

//7. Fazer uma função que realiza o merge de duas listas ordenadas, gerando uma lista única
//ordenada e sem elementos repetidos. A função deverá receber as duas listas por parâmetro e
//criar e retornar uma terceira lista com o resultado.
TLista* merge(TLista* lista, TLista* lista2){
    TLista* L3;
    Tno* aux = lista->inicio;
    Tno* aux2 = lista2->inicio;

    //variaveis:
    int ultimo; //guarda o ultimo valor a ser inserido
    int primeiro=1; // indica se ainda não foi inserido nenhum elemento

    //percorre as duas listas ao mesmo tempo
    while(aux!=NULL && aux2!=NULL){
        int valor;
        //se auxiliadora 1 for menor então
        if(aux->info < aux2->info){
            //guarda valor
            //avança na lista
            valor = aux->info;
            aux = aux->info;
        //se não, a auxliador 2 for maior
        }else if(aux->info > aux2->info){
            //guarda valor
            //avança na lista
            valor = aux->info;
            aux2=aux2->info;
        //se não, as duas forem iguais    
        }else if(aux->info == aux2->info){
            //guarda valor 
            //e avança nas duas
            valor=aux->info;
            aux=aux->info;
            aux2=aux2->info;
        }
        //aqui começa a inserir
        // e so vai inserir se é o primeiro elemento ou diferente do ultimo
        if(primeiro || valor!=ultimo){
        inserir(L3, valor);
        //atualiza o ultimo valor pro proximo loop
        ultimo = valor;
        //a partir daqui ja existe elemento na lista
        primeiro = 0;
        }
    }
    // Caso ainda sobrem elementos na lista1
    while(aux!=NULL){
        // Evita inserir valores repetidos
        if(primeiro || aux->info != ultimo){
            inserir(L3, aux->info);
            ultimo = aux->info;
            primeiro = 0;
        }
        aux = aux->prox;
    }

   //mesma coisa com a lista 2
    while(aux2!=NULL){
        if(primeiro || aux2->info!=ultimo){
            inserir(L3, aux2->info);
            ultimo = aux2->info;
            primeiro=0;
        }
        aux2=aux2->info;
    }
    return L3;
}