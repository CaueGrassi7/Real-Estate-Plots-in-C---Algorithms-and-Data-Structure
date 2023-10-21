typedef struct cliente{

    char nome[30];
    char cpf[15];
    //endereço
    //email

}Cliente;

typedef struct lista Lista;

Lista *criar();

int listaVazia(Lista *l);

void limpar(Lista *l);

int adicionarClienteInicio(Lista *l, Cliente c);

int adicionarClienteFinal(Lista *l, Cliente c);

int ordemAlfabetica(Lista *l);

int removerClienteCPF(Lista *l, char *cpf);

int removerClienteInicio(Lista *l);

int removerClienteFinal(Lista *l);

int existeClienteCPF(Lista *l, char *cpf);

int retornaClienteCPF(Lista *l, Cliente *retorno, char *cpf);

int tamanho(Lista *l);

void mostrar(Lista *l);

void mostrarListaClienteNome(Lista *l, char *nome);

