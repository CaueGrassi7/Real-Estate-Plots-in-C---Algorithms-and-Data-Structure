typedef struct cliente{

    char nome[30];
    char cpf[15];
    //endereço
    //email

}Cliente;

typedef struct lista listacliente;

listacliente *criar();

int listaVazia(listacliente *l);

int listaCheia(listacliente *l);

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

void mostrarListaClienteNome(listacliente *l, char *nome);

