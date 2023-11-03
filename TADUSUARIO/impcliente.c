#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"cliente.h"

struct Corretor
{
    char nome[50];
    char cpf[15];
    char email[50];
    char endereco[50];
    char senha[30];
    char creci[20];
};

typedef struct Corretor corretor;

struct NO {
    struct Corretor valor;
    struct NO *prox;
};

typedef struct NO no;

struct Lista {
    struct NO *inicio;
};

int listaVazia (lista *l) {
    if (l == NULL) return -1;
    if (l->inicio == NULL) return 1;
}

lista * criar () {
    lista *l = (lista*) malloc(sizeof(lista));
    if (l != NULL) {
        l->inicio = NULL;
    }
    return l;
}

int tamanho (lista *l) {
    if (l == NULL) {
        return -1;
    }
    int cont = 0;
    struct NO *aux = l->inicio;
    while (aux != NULL) {
        cont++;
        aux = aux->prox;
    }
    return cont;
}

int novoCadastro (lista *l, corretor c) {
    if (l == NULL) return -1;
    no *noLista = l->inicio;
    while (noLista-> prox != NULL) {
        noLista = noLista->prox;
    }
    no * no = (no*) malloc(sizeof(no));
    no->valor = c;
    no->prox = NULL;
    noLista->prox = no;
    return 1;   
}

int existeCadastro (lista *l, char* email) {
    if (l == NULL) return -1;
    no *noLista = l->inicio;
    while (noLista != NULL) {

        if (strcmp(noLista->valor.email, email) == 0) {
            return 1;
        }
        noLista = noLista->prox;

    }
    return 0;
}

/* 
void login (lista *l, char cpf[15]) {
    if (l == NULL) return 1;
    if (existeCadastro(l, cpf) == 0) {
        printf("Bem vindo, %s", cpf);
    } else {
        printf("Cadastro não encontrado");
    }
    
}
*/

void visualizarUsuarios (lista *l) {
    if (l != NULL) {
        printf ("[");
        no *noLista = l->inicio;
        while (noLista != NULL) {
            printf("[%s ", noLista->valor.nome);
            printf("%s ", noLista->valor.cpf);
            printf("%s]\n", noLista->valor.email);
            noLista = noLista->prox;
        }
        printf("]\n");
    }
}

/*
int excluirUsuario (lista *l, char cpf[15]) {
    if (l == NULL) return 1;
    if (listaVazia(l) == 0) return 2;
    no *noLista = l->inicio;
    while (noLista->valor.cpf != cpf) {
        if (noLista == NULL) return 3;
        noLista = noLista->prox;
    }
        noLista->ant->prox = noLista->prox;
        noLista->prox->ant = noLista->ant;
        free(noLista);
        return 0;

}
*/

int VerificaUsuario(lista* l, char* usuario, char* senha){
    if(l == NULL) return -1;
    if(listaVazia(l)) return 0;
    if(existeCadastro(l, usuario)){
    no* aux = l->inicio;
    while(aux != NULL){
    if(strcmp(aux->valor.email, usuario)==0) return 1;
    aux = aux->prox;
    }
    }
    return 0;
}


int LoginUsuario(corretor* a, lista* l, char* email){
    if(l == NULL) return -1;
    no* aux;
    aux = l->inicio;
    while(aux!= NULL){
        if(strcmp(aux->valor.email, email)==0){
            *a = aux->valor;
            return 1;
        }
        aux = aux->prox;

    }
    
return 0;

}