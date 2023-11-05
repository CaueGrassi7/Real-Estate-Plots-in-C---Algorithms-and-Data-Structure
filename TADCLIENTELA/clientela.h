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

