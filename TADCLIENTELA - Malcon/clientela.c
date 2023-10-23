#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "clientela.h"

typedef struct no{

    Cliente pessoa;
    struct no *prox;

}No;

typedef struct lista{

    No *inicio;

}Lista;

//////////////////////////////////////////

Lista *criar(){

    Lista *l = (Lista*) malloc(sizeof(Lista));

    if(l != NULL){

        l->inicio = NULL;

    }

    return l;
}

//////////////////////////////////////////

int listaVazia(Lista *l){

    if(l == NULL) return 2;
    if(l->inicio == NULL) return 0;
    else return 1;

}

//////////////////////////////////////////

int listaCheia(Lista *l){

    return 1;

}

//////////////////////////////////////////

void limpar(Lista *l){

    while(listaVazia(l) != 0){

        removerClienteInicio(l);

    }

}

//////////////////////////////////////////

int adicionarClienteInicio(Lista *l, Cliente c){

    if(l == NULL) return 2;
    if(listaCheia(l) == 0) return -1;

    No *no = (No*) malloc(sizeof(No));

        no->pessoa = c;
        no->prox = l->inicio;
        l->inicio = no;

    return 0;
}

//////////////////////////////////////////

int adicionarClienteFinal(Lista *l, Cliente c){

    if(l == NULL) return 2;
    if(listaCheia(l) == 0) return -1;

    No *no = (No*) malloc(sizeof(No));
    no->pessoa = c;
    no->prox = NULL;

    if(listaVazia(l) == 0){

        l->inicio = no;
        return 0;

    }

    No *noLista = l->inicio;

    while(noLista->prox != NULL){

        noLista = noLista->prox;

    }

    noLista->prox = no;

    return 0;
}

//////////////////////////////////////////

int adicionarClientePosicao(Lista *l, Cliente c, int pos){

    if(l == NULL) return 2;
    if(listaCheia(l) == 0) return 1;
    if(pos < 0) return -2;

    if((listaVazia(l) == 0) || (pos == 0)) return adicionarClienteInicio(l, c);

    No *noLista = l->inicio;
    int p = 1;

    while((noLista != NULL) && (p < pos)){

        noLista = noLista->prox;
        p++;

    }

    /*
    if(pos != p)
        return -3; //posicao nao encontrada
    */

    No *no = (No*) malloc(sizeof(No));
    no->pessoa = c;

    no->prox = noLista->prox;
    noLista->prox = no;

    return 0;
}

//////////////////////////////////////////

int ordemAlfabetica(Lista *l){

    if(l == NULL) return 2;
    if(listaVazia(l) == 0) return 1; //Não há o que ordenar
    if(tamanho(l) == 1) return 3; //A lista tem apenas um elemento

    No *noAux; //Nó para o primeiro elemento
    No *noLista; //Nó para o segundo elemento
    Cliente temp; //espaço temporario para o deslocamento de um cliente

    for(noAux = l->inicio; noAux != NULL; noAux = noAux->prox){ //o primeiro for controla o primeiro nó até que chegue ao final da lista

        for(noLista = noAux->prox; noLista != NULL; noLista = noLista->prox){ //o segundo, que fica sempre a frente do primeiro, também anda até o final da lista

            if(strcmp(noAux->pessoa.nome, noLista->pessoa.nome) > 0){ //se o nó da frente for alfabeticamente menor que o de trás:

                temp = noAux->pessoa; //guarda o de trás em no espaço temporario
                noAux->pessoa = noLista->pessoa; //passa o da frente pra trás
                noLista->pessoa = temp; //coloca o temporario na frente

            }
        }
    }

    return 0;

}

//////////////////////////////////////////

int removerClienteCPF(Lista *l, char *cpf){

    if(l == NULL) return 2;
    if(listaVazia(l) == 0) return 1;

    No *noAux = NULL;
    No *noLista = l->inicio;

    while(noLista != NULL){

        if(strcmp(noLista->pessoa.cpf, cpf) == 0){

            if(noAux == NULL){

               if(noLista->prox == NULL){

                    free(noLista);
                    l->inicio = NULL;
                    return 0;

               }

                l->inicio = noLista->prox;
                free(noLista);
                return 0;

            }

            noAux->prox = noLista->prox;
            free(noLista);
            return 0;

        }

        noAux = noLista;
        noLista = noLista->prox;

    }

    return 1;
}

//////////////////////////////////////////

int removerClientePosicao(Lista *l, int pos){

    if(l == NULL) return 2;
    if(listaVazia(l) == 0) return 1;
    if(pos < 0) return -2;

    if(pos == 0) return removerClienteInicio(l);

    No *noAux = NULL;
    No *noLista = l->inicio;
    int p = 0;

    while((noLista != NULL) && (pos < p)){

        noAux = noLista;
        noLista = noLista->prox;
        p++;

    }

    /*
    if(pos < p)
        return -3; //posicao nao encontrada
    */

    if(noAux == NULL){

        l->inicio = noLista->prox;
        free(noLista);
        return 0;

    }

    noAux->prox = noLista->prox;
    free(noLista);

    return 0;

}

//////////////////////////////////////////

int existeClienteCPF(Lista *l, char *cpf){

    if(l == NULL) return 2;
    if(listaVazia(l) == 0) return 1;

    No *noLista = l->inicio;

    while(noLista != NULL){

        if(strcmp(noLista->pessoa.cpf, cpf) == 0){

            return 0;

        }

        noLista = noLista->prox;

    }

    return 1;

}

//////////////////////////////////////////

int removerClienteInicio(Lista *l){

    if(l == NULL) return 2;
    if(listaVazia(l) == 0) return 1;

    No *noLista = l->inicio;

    if(noLista->prox == NULL){

        free(noLista);
        l->inicio = NULL;
        return 0;

    }

    l->inicio = noLista->prox;
    free(noLista);

    return 0;
}

//////////////////////////////////////////

int removerClienteFinal(Lista *l){

    if(l == NULL) return 2;
    if(listaVazia(l) == 0) return 1;

    No *noAux = NULL;
    No *noLista = l->inicio;

    while(noLista->prox != NULL){

        noAux = noLista;
        noLista = noLista->prox;

    }

    if(noAux == NULL) l->inicio = NULL;
    else noAux->prox = NULL;

    free(noLista);

    return 0;
}

//////////////////////////////////////////

int retornaClienteCPF(Lista *l, Cliente *retorno, char *cpf){

    if(l == NULL) return 2;
    if(listaVazia(l) == 0) return 1;

    No *noLista = l->inicio;

    while(noLista != NULL){

        if(strcmp(noLista->pessoa.cpf, cpf) == 0){

            *retorno = noLista->pessoa;
            return 0;

        }

        noLista = noLista->prox;

    }

    return 1;
}

//////////////////////////////////////////

int tamanho(Lista *l){

    if(l == NULL) return 2;
    if(listaVazia(l) == 0) return 0;

    No *noLista = l->inicio;
    int contador = 0;

    while(noLista != NULL){

        contador++;
        noLista = noLista->prox;

    }

    return contador;
}

//////////////////////////////////////////

void mostrar(Lista *l){

    if(l != NULL){

        printf("Lista de Clientes:\n\n");

        if(listaVazia(l) != 0){

            No *noLista = l->inicio;
            int i = 1;

            while(noLista != NULL){

                printf("Cliente %d:\n", i);
                printf("Nome: %s\n", noLista->pessoa.nome);
                printf("CPF: %s\n", noLista->pessoa.cpf);
                printf("\n");
                noLista = noLista->prox;
                i++;

            }
        }
    }
}

//////////////////////////////////////////

void mostrarListaClienteNome(Lista *l, char *nome){

    if(l != NULL){

        printf("Lista de Clientes com nome %s:\n\n", nome);

        if(listaVazia(l) != 0){

            No *noLista = l->inicio;
            int i = 1;

            while(noLista != NULL){

                if(strcmp(noLista->pessoa.nome, nome) == 0){

                printf("Cliente %d:\n", i);
                printf("Nome: %s\n", noLista->pessoa.nome);
                printf("CPF: %s\n", noLista->pessoa.cpf);
                printf("\n");
                i++;

                }

                noLista = noLista->prox;

            }
        }
    }
}

//////////////////////////////////////////
