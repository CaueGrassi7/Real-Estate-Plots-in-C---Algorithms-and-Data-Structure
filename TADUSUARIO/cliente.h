#ifndef CLIENTE_H_INCLUDED
#define CLIENTE_H_INCLUDED

typedef struct Corretor corretor;

typedef struct NO no;

typedef struct Lista lista;

lista* criar ();

void login ();

void visualizarClientes ();

int listaVazia (lista* l);

int ordenarAlfabetico (lista* l);


int tamanho (lista* l);

int novoCadastro ();

int excluirCliente ();

#endif 
