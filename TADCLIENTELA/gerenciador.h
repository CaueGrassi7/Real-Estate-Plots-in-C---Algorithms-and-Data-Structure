#ifndef GERENCIADOR_H_INCLUDED
#define GERENCIADOR_H_INCLUDED


typedef struct Lote lote;

typedef struct nolote nolote;

typedef struct listaLotes listalotes;

typedef struct Corretor corretor;

typedef struct NO no;

typedef struct Lista lista;

typedef struct cliente cliente;

typedef struct no No;

typedef struct cliente{

    char nome[50];
    char cpf[15];
    char endereco[50];
    char email[40];

}Cliente;

typedef struct no{

    Cliente pessoa;
    struct no *prox;

};

typedef struct listacliente{

    No *inicio;

}listacliente;


struct Lote
{

    int id; // CODIGO DE IDENTIFICA��O DO LOTE. N�O REPRESENTA NADA ALEM DE IDENTIFICA��O.
    int tamanho; // DADOS               // (C�DIGO �NICO DE CADA LOTE, MESMO QUE EXCLUIDO)
    char rua[50]; // DO
    int quadra;   // LOTE
    int num;
    int status; // SITUA��O ATUAL DO LOTE (1 - LIVRE, 2 - RESERVADO, 3 -  VENDIDO);
    char* cliente;
    char* creci; // CORRETOR RESPONSAVEL
    float preco;
};
typedef struct Lote lote;


// N� DA LISTA
typedef struct nolote
{
    lote valor;
    nolote* prox;
} nolote;


// TIPO LISTA DE LOTES
typedef struct listaLotes
{
    nolote* inicio;
    int cod; // VARIAVEL PARA CONTROLE DE LOTES E PARA ATRIBUIR OS C�DIGOS DE CADA LOTE.
}listalotes;

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

typedef struct listacliente listacliente;

//TAD LOTES //////////////////////////////////////////////////////////////////////////

listalotes* crialistalote();

int inserelote(listalotes* l, lote a);
int buscalote(listalotes* l, lote a);
int statuslote(listalotes* l, int id);
int mudastatus(listalotes* l, int id, int status);
int removelote(listalotes* l, int id);
void mostrarlotes(listalotes* l);
void mostrardisponivel(listalotes* l);
void mostrarreservados(listalotes* l);
void mostrarvendidos(listalotes* l);
void mostrarua(listalotes* l, char* rua);
void mostraid(listalotes* l, int id);
void mostracorretor(listalotes* l, char* creci);
void mostracliente(listalotes* l, Cliente a);
int lotevendido(listalotes* l, int id, Cliente a, char* creci, float preco);
int tamanholote(listalotes* l, int id);


//TAD USUARIO //////////////////////////////////////////////////////////////////////////

lista* criarlistacorretor();
void login();
int existeCadastro (lista *l, char* email);
void visualizarUsuarios (lista *l);
void visualizarClientes();
int listaVazia(lista* l);
int tamanhoUsuario(lista* l);
int novoCadastro(lista* l, corretor c);
int excluirCliente();
int VerificaUsuario(lista* l, char* usuario, char* senha);
int LoginUsuario(corretor* a, lista* l, char* email);


//TAD CLIENTE //////////////////////////////////////////////////////////////////////////

listacliente *criarlistacliente();
int listaclienteVazia(listacliente *l);
int listaclienteCheia(listacliente *l);
void limpar(listacliente *l);
int adicionarClienteInicio(listacliente *l, Cliente c);
int adicionarClienteFinal(listacliente *l, Cliente c);
int adicionarClientePosicao(listacliente *l, Cliente c, int pos);
int ordemAlfabetica(listacliente *l);
int removerClienteCPF(listacliente *l, char *cpf);
int removerClienteInicio(listacliente *l);
int removerClienteFinal(listacliente *l);
int removerClientePosicao(listacliente *l, int pos);
int existeClienteCPF(listacliente *l, char *cpf);
int retornaClienteCPF(listacliente *l, Cliente *retorno, char *cpf);
int tamanho(listacliente *l);
void mostrar(listacliente *l);
void mostrarlistaclienteClienteNome(listacliente *l, char *nome);


#endif // GERENCIADOR_H_INCLUDED
