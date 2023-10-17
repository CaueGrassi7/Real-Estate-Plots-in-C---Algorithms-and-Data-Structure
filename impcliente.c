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
    char numeroEndereco[5]; 
};


struct NO {
    struct Corretor valor;
    struct NO *prox;
    struct NO *ant;
};

struct Lista {
    struct NO *inicio;
};

int listaVazia (lista *l) {
    if (l == NULL) return 1;
    if (l->inicio == NULL) return 0;
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
        return 1;
    }
    int cont = 0;
    struct NO *aux = l->inicio;
    while (aux != NULL) {
        cont++;
        aux = aux->prox;
    }
    return cont;
}

int OrdenarAlfabetico (lista *l) {
    
}

int novoCadastro (lista *l, corretor c) {
    if (l == NULL) return 1;
    no *noLista = l->inicio;
    while (noLista-> prox != NULL) {
        noLista = noLista->prox;
    }
        no * no = (no*) malloc(sizeof(no));
    no->valor = c;
    no->prox = NULL;
    no->ant = noLista;
    noLista->prox = no;
    return 0;   
}

int existeCadastro (lista *l, char cpf[15]) {
    if (l == NULL) return 1;
    no *noLista = l->inicio;
    while (noLista != NULL) {
        if (strcmp(noLista->valor.cpf, cpf) == 0) {
            return 0;
        }
        noLista = noLista->prox;
    }
    return 1;
}

void login (lista *l, char cpf[15]) {
    if (l == NULL) return 1;
    if (existeCadastro(l, cpf) == 0) {
        printf("Bem vindo, %s", cpf);
    } else {
        printf("Cadastro não encontrado");
    }
    
}

void visualizarClientes (lista *l) {
    if (l != NULL) {
        printf ("[");
        no *noLista = l->inicio;
        while (noLista != NULL) {
            printf("%s", noLista->valor.nome);
            printf("%s", noLista->valor.cpf);
            printf("%s", noLista->valor.email);
            noLista = noLista->prox;
        }
        printf("]\n");
    }
}

int excluirCliente (lista *l, char cpf[15]) {
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
