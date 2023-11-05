#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "clientela.h"

typedef struct no{

    Cliente pessoa;
    struct no *prox;

}No;

typedef struct listacliente{

    No *inicio;

}listacliente;

//////////////////////////////////////////

listacliente *criar(){

    listacliente *l = (listacliente*) malloc(sizeof(listacliente));

    if(l != NULL){

        l->inicio = NULL;

    }

    return l;
}

//////////////////////////////////////////

int listaclienteVazia(listacliente *l){

    if(l == NULL) return 2;
    if(l->inicio == NULL) return 0;
    else return 1;

}

//////////////////////////////////////////

int listaclienteCheia(listacliente *l){

    return 1;

}

//////////////////////////////////////////

void limpar(listacliente *l){

    while(listaclienteVazia(l) != 0){

        removerClienteInicio(l);

    }

}

//////////////////////////////////////////

int adicionarClienteInicio(listacliente *l, Cliente c){

    if(l == NULL) return 2;
    if(listaclienteCheia(l) == 0) return -1;

    No *no = (No*) malloc(sizeof(No));

        no->pessoa = c;
        no->prox = l->inicio;
        l->inicio = no;

    return 0;
}

//////////////////////////////////////////

int adicionarClienteFinal(listacliente *l, Cliente c){

    if(l == NULL) return 2;
    if(listaclienteCheia(l) == 0) return -1;

    No *no = (No*) malloc(sizeof(No));
    no->pessoa = c;
    no->prox = NULL;

    if(listaclienteVazia(l) == 0){

        l->inicio = no;
        return 0;

    }

    No *nolistacliente = l->inicio;

    while(nolistacliente->prox != NULL){

        nolistacliente = nolistacliente->prox;

    }

    nolistacliente->prox = no;

    return 0;
}

//////////////////////////////////////////

int adicionarClientePosicao(listacliente *l, Cliente c, int pos){

    if(l == NULL) return 2;
    if(listaclienteCheia(l) == 0) return 1;
    if(pos < 0) return -2;

    if((listaclienteVazia(l) == 0) || (pos == 0)) return adicionarClienteInicio(l, c);

    No *nolistacliente = l->inicio;
    int p = 1;

    while((nolistacliente != NULL) && (p < pos)){

        nolistacliente = nolistacliente->prox;
        p++;

    }

    /*
    if(pos != p)
        return -3; //posicao nao encontrada
    */

    No *no = (No*) malloc(sizeof(No));
    no->pessoa = c;

    no->prox = nolistacliente->prox;
    nolistacliente->prox = no;

    return 0;
}

//////////////////////////////////////////

int ordemAlfabetica(listacliente *l){

    if(l == NULL) return 2;
    if(listaclienteVazia(l) == 0) return 1; //Não há o que ordenar
    if(tamanho(l) == 1) return 3; //A listacliente tem apenas um elemento

    No *noAux; //Nó para o primeiro elemento
    No *nolistacliente; //Nó para o segundo elemento
    Cliente temp; //espaço temporario para o deslocamento de um cliente

    for(noAux = l->inicio; noAux != NULL; noAux = noAux->prox){ //o primeiro for controla o primeiro nó até que chegue ao final da listacliente

        for(nolistacliente = noAux->prox; nolistacliente != NULL; nolistacliente = nolistacliente->prox){ //o segundo, que fica sempre a frente do primeiro, também anda até o final da listacliente

            if(strcmp(noAux->pessoa.nome, nolistacliente->pessoa.nome) > 0){ //se o nó da frente for alfabeticamente menor que o de trás:

                temp = noAux->pessoa; //guarda o de trás em no espaço temporario
                noAux->pessoa = nolistacliente->pessoa; //passa o da frente pra trás
                nolistacliente->pessoa = temp; //coloca o temporario na frente

            }
        }
    }

    return 0;

}

//////////////////////////////////////////

int removerClienteCPF(listacliente *l, char *cpf){

    if(l == NULL) return 2;
    if(listaclienteVazia(l) == 0) return 1;

    No *noAux = NULL;
    No *nolistacliente = l->inicio;

    while(nolistacliente != NULL){

        if(strcmp(nolistacliente->pessoa.cpf, cpf) == 0){

            if(noAux == NULL){

               if(nolistacliente->prox == NULL){

                    free(nolistacliente);
                    l->inicio = NULL;
                    return 0;

               }

                l->inicio = nolistacliente->prox;
                free(nolistacliente);
                return 0;

            }

            noAux->prox = nolistacliente->prox;
            free(nolistacliente);
            return 0;

        }

        noAux = nolistacliente;
        nolistacliente = nolistacliente->prox;

    }

    return 1;
}

//////////////////////////////////////////

int removerClientePosicao(listacliente *l, int pos){

    if(l == NULL) return 2;
    if(listaclienteVazia(l) == 0) return 1;
    if(pos < 0) return -2;

    if(pos == 0) return removerClienteInicio(l);

    No *noAux = NULL;
    No *nolistacliente = l->inicio;
    int p = 0;

    while((nolistacliente != NULL) && (pos < p)){

        noAux = nolistacliente;
        nolistacliente = nolistacliente->prox;
        p++;

    }

    /*
    if(pos < p)
        return -3; //posicao nao encontrada
    */

    if(noAux == NULL){

        l->inicio = nolistacliente->prox;
        free(nolistacliente);
        return 0;

    }

    noAux->prox = nolistacliente->prox;
    free(nolistacliente);

    return 0;

}

//////////////////////////////////////////

int existeClienteCPF(listacliente *l, char *cpf){

    if(l == NULL) return 2;
    if(listaclienteVazia(l) == 0) return 1;

    No *nolistacliente = l->inicio;

    while(nolistacliente != NULL){

        if(strcmp(nolistacliente->pessoa.cpf, cpf) == 0){

            return 0;

        }

        nolistacliente = nolistacliente->prox;

    }

    return 1;

}

//////////////////////////////////////////

int removerClienteInicio(listacliente *l){

    if(l == NULL) return 2;
    if(listaclienteVazia(l) == 0) return 1;

    No *nolistacliente = l->inicio;

    if(nolistacliente->prox == NULL){

        free(nolistacliente);
        l->inicio = NULL;
        return 0;

    }

    l->inicio = nolistacliente->prox;
    free(nolistacliente);

    return 0;
}

//////////////////////////////////////////

int removerClienteFinal(listacliente *l){

    if(l == NULL) return 2;
    if(listaclienteVazia(l) == 0) return 1;

    No *noAux = NULL;
    No *nolistacliente = l->inicio;

    while(nolistacliente->prox != NULL){

        noAux = nolistacliente;
        nolistacliente = nolistacliente->prox;

    }

    if(noAux == NULL) l->inicio = NULL;
    else noAux->prox = NULL;

    free(nolistacliente);

    return 0;
}

//////////////////////////////////////////

int retornaClienteCPF(listacliente *l, Cliente *retorno, char *cpf){

    if(l == NULL) return 2;
    if(listaclienteVazia(l) == 0) return 1;

    No *nolistacliente = l->inicio;

    while(nolistacliente != NULL){

        if(strcmp(nolistacliente->pessoa.cpf, cpf) == 0){

            *retorno = nolistacliente->pessoa;
            return 0;

        }

        nolistacliente = nolistacliente->prox;

    }

    return 1;
}

//////////////////////////////////////////

int tamanho(listacliente *l){

    if(l == NULL) return 2;
    if(listaclienteVazia(l) == 0) return 0;

    No *nolistacliente = l->inicio;
    int contador = 0;

    while(nolistacliente != NULL){

        contador++;
        nolistacliente = nolistacliente->prox;

    }

    return contador;
}

//////////////////////////////////////////

void mostrar(listacliente *l){

    if(l != NULL){

        printf("Lista de Clientes:\n\n");

        if(listaclienteVazia(l) != 0){

            No *nolistacliente = l->inicio;
            int i = 1;

            while(nolistacliente != NULL){

                printf("Cliente %d:\n\n", i);
                printf("Nome: %s", nolistacliente->pessoa.nome);
                printf("CPF: %s\n", nolistacliente->pessoa.cpf);
                printf("\n");
                nolistacliente = nolistacliente->prox;
                i++;

            }
        }
    }
}

//////////////////////////////////////////

void mostrarlistaclienteClienteNome(listacliente *l, char *nome){

    if(l != NULL){

        printf("listacliente de Clientes com nome %s:\n\n", nome);

        if(listaclienteVazia(l) != 0){

            No *nolistacliente = l->inicio;
            int i = 1;

            while(nolistacliente != NULL){

                if(strcmp(nolistacliente->pessoa.nome, nome) == 0){

                printf("Cliente %d:\n", i);
                printf("Nome: %s\n", nolistacliente->pessoa.nome);
                printf("CPF: %s\n", nolistacliente->pessoa.cpf);
                printf("\n");
                i++;

                }

                nolistacliente = nolistacliente->prox;

            }
        }
    }
}

//////////////////////////////////////////
