#ifndef CLIENTE_H_INCLUDED
#define CLIENTE_H_INCLUDED

typedef struct Corretor corretor;

typedef struct NO no;

typedef struct Lista lista;

lista* criarlistacorretor();

void login();

void visualizarClientes();

int listaVazia(lista* l);

int tamanho(lista* l);

int novoCadastro(lista* l, corretor c);

int excluirCliente();

int VerificaUsuario(lista* l, char* usuario, char* senha);

int LoginUsuario(corretor* a, lista* l, char* email);

#endif 
