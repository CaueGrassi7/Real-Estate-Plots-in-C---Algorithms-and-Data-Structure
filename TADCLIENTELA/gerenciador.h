#ifndef GERENCIADOR_H_INCLUDED
#define GERENCIADOR_H_INCLUDED

//TAD LOTES

struct Lote{

int id;
int tamanho;
char rua[50];
int quadra;
int num;
int status;
char* cliente;
char* creci;
float preco;
};

typedef struct Lote lote;

typedef struct nolote{
    lote valor;
    struct nolote* prox;
}nolote;

typedef struct listaLotes{
nolote* inicio;
int cod;

}listalotes;

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
int lotevendido(listalotes* l, int id, Cliente a, int creci, float preco);

//TAD USUARIO //////////////////////////////////////////////////////////////////////////

typedef struct Corretor corretor;

typedef struct NO no;

typedef struct Lista lista;

lista* criarlistacorretor();
void login();
void visualizarClientes();
int listaVazia(lista* l);
int tamanhoUsuario(lista* l);
int novoCadastro(lista* l, corretor c);
int excluirCliente();
int VerificaUsuario(lista* l, char* usuario, char* senha);
int LoginUsuario(corretor* a, lista* l, char* email);

//TAD CLIENTE //////////////////////////////////////////////////////////////////////////

typedef struct cliente{

    char nome[50];
    char cpf[15];
    char endereco[50];
    char email[40];

}Cliente;

typedef Cliente cliente;

typedef struct listacliente listacliente;

listacliente *criar();

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
