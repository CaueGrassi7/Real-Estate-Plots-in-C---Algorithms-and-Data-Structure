#include "gerenciador.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

//// TADS

typedef struct cliente cliente;

typedef Cliente cliente;

typedef cliente Cliente;

typedef struct listacliente listacliente;

typedef struct Corretor corretor;

typedef struct NO no;

typedef struct Lista lista;




//LOTE////////////////////////////////////////////////////////////////////



// CRIA��O DA LISTA DE LOTES
listalotes *crialistalote()
{
    listalotes* l = (listalotes*) malloc (sizeof(listalotes)); // ALOCA A LISTA E CRIA A LISTA;
    l -> inicio = NULL; // COLOCA O INICIO PARA APONTAR PARA NADA;
    l -> cod = 0; // ZERA A QUANTIDADE DE LOTES;
    return l;
}



// INSER��O DO LOTE EM ORDEM (RUA).
int inserelote(listalotes* l, lote a)
{
    if(l == NULL) return 0;
    nolote* nolotevoLote = (nolote*)malloc(sizeof(nolote));
    nolotevoLote->valor = a;
    nolotevoLote->valor.id = l->cod;
    nolotevoLote->prox = NULL;

    nolotevoLote->valor.creci = (char*) malloc (sizeof(char)*20);
    nolotevoLote->valor.creci[0] = " ";
    nolotevoLote->valor.creci[1] = '\0';
    nolotevoLote->valor.cliente = " ";
    nolotevoLote->valor.preco = 0;

    if (l->inicio == NULL || strcmp(a.rua, l->inicio->valor.rua) < 0)
    {
        // Inserir nolote in�cio da lista
        nolotevoLote->prox = l->inicio;
        l->inicio = nolotevoLote;
    }
    else
    {
        nolote* atual = l->inicio;
        while (atual->prox != NULL && strcmp(a.rua, atual->prox->valor.rua) >= 0)
        {
            atual = atual->prox;
        }
        // Inserir ap�s o n� 'atual'
        nolotevoLote->prox = atual->prox;
        atual->prox = nolotevoLote;
    }

    nolotevoLote->valor.id == l->cod;
    l->cod++;
    return 1;
}





// FUN��O QUE BUSCA UM LOTE UTILIZANDO SEU ID
// RETORNA 1 SE ENCONTRA
// RETORNA 0 SE N�O
int buscalote(listalotes* l, lote a)
{
    if(l == NULL) return 0;
    nolote* cl = l->inicio;
    while(cl!=NULL)
    {
        if((cl->valor).id == a.id) return 1;
        cl = cl->prox;
    }
    return 0;
}



// FUN��O QUE RETORNA O STATUS DO LOTE
// (0 - LOTE N�O ENCONTRADO 1 - LIVRE, 2 - RESERVADO, 3 -  VENDIDO);
int statuslote(listalotes* l, int id)
{
    if(l == NULL) return 0;
    nolote* cl = l->inicio;
    while(cl!=NULL)
    {
        if((cl->valor).id == id) return ((cl->valor).status);
        cl = cl->prox;
    }
    return 0;
}



// FUN��O QUE ALTERA O STATUS DE UM DADO LOTE.
// RETORNA 0 SE N�O ENCONTRADO
// RETORNA 1 SE FUN��O FEITA COM SUCESSO
int mudastatus(listalotes* l, int id, int status)
{
    if(l == NULL) return 0;
    nolote* cl = l->inicio;
    while(cl!=NULL)
    {
        printf("aa");
        if((cl->valor).id == id)
        {
            printf("aa");
            (cl->valor).status = status;
            printf("aa");
            return 1;
        }
        cl = cl->prox;
    }
    return 0;
}


// FUN��O QUE REMOVE UM CERTO LOTE POR SUA IDENTIFICA��O
// RETORNA 1 SE OPERA��O REALIZADA
// RETORNA 0 SE N�O ENCONTRADO
int removelote(listalotes* l, int id)
{
    if(l == NULL) return 0;
    nolote* cl = l->inicio;
    if((cl->valor.id) == id)
    {
        l->inicio = cl->prox;
        free(cl);
        return 1;
    }
    else while(cl->prox!=NULL)
        {
            if((cl->prox->valor).id == id)
            {
                nolote* aux = cl->prox;
                cl->prox = cl->prox->prox;
                free(aux);
                return 1;
            }
            cl = cl->prox;
        }
    return 0;
}

// MOSTRA OS LOTES NA ORDEM EM QUE EST�O NA LISTA (ORDEM ALFAB�TICA PELA RUA)
// MODELO A SER MOSTRADO:
// [ID] [RUA] [QUADRA] [NUMERO] [STATUS] [CLIENTE] [CRECI]
void mostrarlotes(listalotes* l)
{
    printf("[ID] [RUA]                [QUADRA] [NUMERO] [STATUS] [CLIENTE] [CRECI] // 1 - DISPONIVEL, 2 - RESERVADO, 3 - VENDIDO\n");
    if(l!=NULL)
    {
        nolote* a = l->inicio;
        char* aux = (char*) malloc(sizeof(char)*21);


        while(a != NULL)
        {
            
            int verificador = 0;
            for(int i=0; i<20; i++)  // FORMATA A RUA EM UM NUMERO MAXIMO DE CARACTERES
            {
                if(a->valor.cliente[i] == '\0') verificador++;
                if(verificador>0)
                {
                    aux[i] = ' ';
                    continue;
                }
                aux[i] = a->valor.rua[i];
            }
            aux[20] = '\0';


            printf("[%d] [%s] [%d] [%d] [%d] [%s] [%s]\n", a->valor.id, a->valor.rua, a->valor.quadra, a->valor.num, a->valor.status, a->valor.cliente, a->valor.creci);
            a = a->prox;
        }
    }
}


// MOSTRA OS LOTES NA ORDEM EM QUE EST�O NA LISTA, SE DISPONIVEIS (ORDEM ALFAB�TICA PELA RUA)
// MODELO A SER MOSTRADO:
// [ID] [RUA] [QUADRA] [NUMERO] [STATUS] [CLIENTE] [CRECI]
void mostrardisponivel(listalotes* l)
{
    printf("[ID] [RUA]                [QUADRA] [NUMERO] [STATUS] [CLIENTE] [CRECI]\n");
    if(l!=NULL)
    {
        nolote* a = l->inicio;
        char* aux = (char*) malloc(sizeof(char)*21);

        while(a != NULL)
        {
            if(a->valor.status == 1)
            {
                int verificador = 0;
                for(int i=0; i<20; i++)  // FORMATA A RUA EM UM NUMERO MAXIMO DE CARACTERES
                {
                    if(a->valor.rua[i] == '\0') verificador++;
                    if(verificador>0)
                    {
                        aux[i] = ' ';
                        continue;
                    }
                    aux[i] = a->valor.rua[i];
                }
                aux[20] = '\0';

                printf("[%d] [%s] [%d] [%d] [%d] [%s] [%s]\n", a->valor.id, aux, a->valor.quadra, a->valor.num, a->valor.status, a->valor.cliente, a->valor.creci);
            }
            a = a->prox;
        }
    }

}

// MOSTRA OS LOTES NA ORDEM EM QUE EST�O NA LISTA, SE RESERVADOS (ORDEM ALFAB�TICA PELA RUA)
// MODELO A SER MOSTRADO:
// [ID] [RUA] [QUADRA] [NUMERO] [STATUS] [CLIENTE] [CRECI]
void mostrarreservados(listalotes* l)
{
    printf("[ID] [RUA]                [QUADRA] [NUMERO] [STATUS] [CLIENTE] [CRECI]\n");
    if(l!=NULL)
    {
        nolote* a = l->inicio;
        char* aux = (char*) malloc(sizeof(char)*21);

        while(a != NULL)
        {
            if(a->valor.status == 2)
            {
                int verificador = 0;
                for(int i=0; i<20; i++)  // FORMATA A RUA EM UM NUMERO MAXIMO DE CARACTERES
                {
                    if(a->valor.rua[i] == '\0') verificador++;
                    if(verificador>0)
                    {
                        aux[i] = ' ';
                        continue;
                    }
                    aux[i] = a->valor.rua[i];
                }
                aux[20] = '\0';

                printf("[%d] [%s] [%d] [%d] [%d] [%s] [%s]\n", a->valor.id, aux, a->valor.quadra, a->valor.num, a->valor.status, a->valor.cliente, a->valor.creci);
            }
            a = a->prox;
        }
    }


}

// MOSTRA OS LOTES NA ORDEM EM QUE EST�O NA LISTA, SE VENDIDOS (ORDEM ALFAB�TICA PELA RUA)
// MODELO A SER MOSTRADO:
// [ID] [RUA] [QUADRA] [NUMERO] [STATUS] [CLIENTE] [CRECI]
void mostrarvendidos(listalotes* l)
{
    printf("[ID] [RUA]                [QUADRA] [NUMERO] [STATUS] [CLIENTE] [CRECI]\n");
    if(l!=NULL)
    {
        nolote* a = l->inicio;
        char* aux = (char*) malloc(sizeof(char)*21);

        while(a != NULL)
        {
            if(a->valor.status == 3)
            {
                int verificador = 0;
                for(int i=0; i<20; i++)  // FORMATA A RUA EM UM NUMERO MAXIMO DE CARACTERES
                {
                    if(a->valor.rua[i] == '\0') verificador++;
                    if(verificador>0)
                    {
                        aux[i] = ' ';
                        continue;
                    }
                    aux[i] = a->valor.rua[i];
                }
                aux[20] = '\0';

                printf("[%d] [%s] [%d] [%d] [%d] [%s] [%s]\n", a->valor.id, aux, a->valor.quadra, a->valor.num, a->valor.status, a->valor.cliente, a->valor.creci);
            }
            a = a->prox;
        }
    }

}


// MOSTRA OS LOTES NA ORDEM EM QUE EST�O NA LISTA, PELA RUA
// MODELO A SER MOSTRADO:
// [ID] [RUA] [QUADRA] [NUMERO] [STATUS] [CLIENTE] [CRECI]
void mostrarua(listalotes* l, char* rua)
{
    printf("[ID] [RUA]                [QUADRA] [NUMERO] [STATUS] [CLIENTE] [CRECI]\n");
    if(l!=NULL)
    {
        nolote* a = l->inicio;
        char* aux = (char*) malloc(sizeof(char)*21);

        while(a != NULL)
        {
            if(strcmp(rua, a->valor.rua) == 0)
            {
                int verificador = 0;
                for(int i=0; i<20; i++)  // FORMATA A RUA EM UM NUMERO MAXIMO DE CARACTERES
                {
                    if(a->valor.rua[i] == '\0') verificador++;
                    if(verificador>0)
                    {
                        aux[i] = ' ';
                        continue;
                    }
                    aux[i] = a->valor.rua[i];
                }
                aux[20] = '\0';

                printf("[%d] [%s] [%d] [%d] [%d] [%s] [%s]\n", a->valor.id, aux, a->valor.quadra, a->valor.num, a->valor.status, a->valor.cliente, a->valor.creci);
            }
            a = a->prox;
        }
    }



}

// MOSTRA OS LOTES NA ORDEM EM QUE EST�O NA LISTA, PELO ID
// MODELO A SER MOSTRADO:
// [ID] [RUA] [QUADRA] [NUMERO] [STATUS] [CLIENTE] [CRECI]
void mostraid(listalotes* l, int id)
{
    printf("[ID] [RUA]                [QUADRA] [NUMERO] [STATUS] [CLIENTE] [CRECI]\n");
    if(l!=NULL)
    {
        nolote* a = l->inicio;
        char* aux = (char*) malloc(sizeof(char)*21);

        while(a != NULL)
        {
            if(a->valor.id == id)
            {
                int verificador = 0;
                for(int i=0; i<20; i++)  // FORMATA A RUA EM UM NUMERO MAXIMO DE CARACTERES
                {
                    if(a->valor.rua[i] == '\0') verificador++;
                    if(verificador>0)
                    {
                        aux[i] = ' ';
                        continue;
                    }
                    aux[i] = a->valor.rua[i];
                }
                aux[20] = '\0';

                printf("[%d] [%s] [%d] [%d] [%d] [%s] [%s]\n", a->valor.id, aux, a->valor.quadra, a->valor.num, a->valor.status, a->valor.cliente, a->valor.creci);
                break;
            }
            a = a->prox;
        }
    }
}


// MOSTRA OS LOTES NA ORDEM EM QUE EST�O NA LISTA, DE ACORDO COM CORRETOR
// MODELO A SER MOSTRADO:
// [ID] [RUA] [QUADRA] [NUMERO] [STATUS] [CLIENTE] [CRECI]
void mostracorretor(listalotes* l, char* creci)
{
    printf("[ID] [RUA]                [QUADRA] [NUMERO] [STATUS] [CLIENTE] [CRECI]\n");
    if(l!=NULL)
    {
        nolote* a = l->inicio;
        char* aux = (char*) malloc(sizeof(char)*21);

        while(a != NULL)
        {
            if(a->valor.creci == creci)
            {
                int verificador = 0;
                for(int i=0; i<20; i++)  // FORMATA A RUA EM UM NUMERO MAXIMO DE CARACTERES
                {
                    if(a->valor.rua[i] == '\0') verificador++;
                    if(verificador>0)
                    {
                        aux[i] = ' ';
                        continue;
                    }
                    aux[i] = a->valor.rua[i];
                }
                aux[20] = '\0';

                printf("[%d] [%s] [%d] [%d] [%d] [%s] [%s]\n", a->valor.id, aux, a->valor.quadra, a->valor.num, a->valor.status, a->valor.cliente, a->valor.creci);

            }
            a = a->prox;
        }
    }
}

// MOSTRA OS LOTES NA ORDEM EM QUE EST�O NA LISTA, DE ACORDO COM CLIENTE
// MODELO A SER MOSTRADO:
// [ID] [RUA] [QUADRA] [NUMERO] [STATUS] [CLIENTE] [CRECI]
void mostracliente(listalotes* l, cliente b)
{
    printf("[ID] [RUA]                [QUADRA] [NUMERO] [STATUS] [CLIENTE] [CRECI]\n");
    if(l!=NULL)
    {
        nolote* a = l->inicio;
        char* aux = (char*) malloc(sizeof(char)*21);

        while(a != NULL)
        {
            if(a->valor.cliente == b.nome)
            {
                int verificador = 0;
                for(int i=0; i<20; i++)  // FORMATA A RUA EM UM NUMERO MAXIMO DE CARACTERES
                {
                    if(a->valor.rua[i] == '\0') verificador++;
                    if(verificador>0)
                    {
                        aux[i] = ' ';
                        continue;
                    }
                    aux[i] = a->valor.rua[i];
                }
                aux[20] = '\0';

                printf("[%d] [%s] [%d] [%d] [%d] [%s] [%s]\n", a->valor.id, aux, a->valor.quadra, a->valor.num, a->valor.status, a->valor.cliente, a->valor.creci);
            }
            a = a->prox;
        }
    }
}

// FUN��O QUE ALTERA UM LOTE COMO VENDIDO
int lotevendido(listalotes* l, int id, Cliente a, char* creci, float preco)
{
    if(l == NULL) return 0;
    nolote* cl = l->inicio;
    printf("entrei aqui");
    sleep(10);
    while(cl!=NULL)
    {
        if((cl->valor).id == id)
        {
            cl->valor.status = 3;
            printf("1");
            cl->valor.cliente = a.nome;
            printf("2");
            strcpy(cl->valor.creci, creci);
            printf("3");
            cl->valor.preco = preco;

            printf("entrei aqui");
            return 1;
        }
        cl = cl->prox;
    }
    return 0;
}



int tamanholote(listalotes* l, int id)
{
    if(l == NULL) return -1;
    nolote* cl;
    cl =  l->inicio;
    while(cl!= NULL)
    {

        if(cl->valor.id == id) return cl->valor.tamanho;

        cl = cl->prox;
    }


    return 0;

}
//USUARIO////////////////////////////////////////////////////////////////////


int listaVazia (lista *l)
{

    if (l == NULL) return -1;
    if (l->inicio == NULL) return 0;

}

lista * criarlistacorretor()
{
    lista *l = (lista*) malloc(sizeof(lista));
    if (l != NULL)
    {
        l->inicio = NULL;
    }
    return l;
}

int tamanhoUsuario (lista *l)
{
    if (l == NULL)
    {
        return -1;
    }
    int cont = 0;
    struct NO *aux = l->inicio;
    while (aux != NULL)
    {
        cont++;
        aux = aux->prox;
    }
    return cont;
}

int novoCadastro (lista *l, corretor c)
{
    if (l == NULL) return 2;

    struct NO *nonl = (struct NO*) malloc(sizeof(no));
    nonl->valor = c;
    nonl->prox = NULL;

    if(listaVazia(l) == 0)
    {

        l->inicio = nonl;
        return 0;

    }

    struct NO *noLista = l->inicio;

    while(noLista->prox != NULL)
    {

        noLista = noLista->prox;

    }

    noLista->prox = nonl;

    return 0;
}

int existeCadastro (lista *l, char* email)
{
    if (l == NULL) return -1;
    no *noLista = l->inicio;
    while (noLista != NULL)
    {

        if (strcmp(noLista->valor.email, email) == 0)
        {
            return 1;
        }
        noLista = noLista->prox;

    }
    return 0;
}


void visualizarUsuarios (lista *l)
{
    if (l != NULL)
    {
        printf ("[");
        no *noLista = l->inicio;
        while (noLista != NULL)
        {
            printf("[%s ", noLista->valor.nome);
            printf("%s ", noLista->valor.cpf);
            printf("%s]\n", noLista->valor.email);
            noLista = noLista->prox;
        }
        printf("]\n");
    }
}

int VerificaUsuario(lista* l, char* usuario, char* senha)
{
    if(l == NULL) return -1;
    no *aux = l->inicio;
    while(aux != NULL)
    {
        if(strcmp(aux->valor.email, usuario) == 0) return 1;
        aux = aux->prox;
    }

    return 0;
}


int LoginUsuario(corretor* a, lista* l, char* email)
{
    if(l == NULL) return -1;
    no* aux;
    aux = l->inicio;
    while(aux!= NULL)
    {
        if(strcmp(aux->valor.email, email)==0)
        {
            *a = aux->valor;
            return 1;
        }
        aux = aux->prox;

    }

    return 0;

}


//CLIENTE////////////////////////////////////////////////////////////////////


listacliente *criarlistacliente()
{

    listacliente *l = (listacliente*) malloc(sizeof(listacliente));

    if(l != NULL)
    {

        l->inicio = NULL;

    }

    return l;
}



int listaclienteVazia(listacliente *l)
{

    if(l == NULL) return 2;
    if(l->inicio == NULL) return 0;
    else return 1;

}



int listaclienteCheia(listacliente *l)
{

    return 1;

}



void limpar(listacliente *l)
{

    while(listaclienteVazia(l) != 0)
    {

        removerClienteInicio(l);

    }

}



int adicionarClienteInicio(listacliente *l, Cliente c)
{

    if(l == NULL) return 2;
    if(listaclienteCheia(l) == 0) return -1;

    No *no = (No*) malloc(sizeof(No));

    no->pessoa = c;
    no->prox = l->inicio;
    l->inicio = no;

    return 0;
}



int adicionarClienteFinal(listacliente *l, Cliente c)
{

    if(l == NULL) return 2;
    if(listaclienteCheia(l) == 0) return -1;

    No *no = (No*) malloc(sizeof(No));
    no->pessoa = c;
    no->prox = NULL;

    if(listaclienteVazia(l) == 0)
    {

        l->inicio = no;
        return 0;

    }

    No *nolistacliente = l->inicio;

    while(nolistacliente->prox != NULL)
    {

        nolistacliente = nolistacliente->prox;

    }

    nolistacliente->prox = no;

    return 0;
}



int adicionarClientePosicao(listacliente *l, Cliente c, int pos)
{

    if(l == NULL) return 2;
    if(listaclienteCheia(l) == 0) return 1;
    if(pos < 0) return -2;

    if((listaclienteVazia(l) == 0) || (pos == 0)) return adicionarClienteInicio(l, c);

    No *nolistacliente = l->inicio;
    int p = 1;

    while((nolistacliente != NULL) && (p < pos))
    {

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



int ordemAlfabetica(listacliente *l)
{

    if(l == NULL) return 2;
    if(listaclienteVazia(l) == 0) return 1; //N�o h� o que ordenar
    if(tamanho(l) == 1) return 3; //A listacliente tem apenas um elemento

    No *noAux; //N� para o primeiro elemento
    No *nolistacliente; //N� para o segundo elemento
    Cliente temp; //espa�o temporario para o deslocamento de um cliente

    for(noAux = l->inicio; noAux != NULL; noAux = noAux->prox)  //o primeiro for controla o primeiro n� at� que chegue ao final da listacliente
    {

        for(nolistacliente = noAux->prox; nolistacliente != NULL; nolistacliente = nolistacliente->prox)  //o segundo, que fica sempre a frente do primeiro, tamb�m anda at� o final da listacliente
        {

            if(strcmp(noAux->pessoa.nome, nolistacliente->pessoa.nome) > 0)  //se o n� da frente for alfabeticamente menor que o de tr�s:
            {

                temp = noAux->pessoa; //guarda o de tr�s em no espa�o temporario
                noAux->pessoa = nolistacliente->pessoa; //passa o da frente pra tr�s
                nolistacliente->pessoa = temp; //coloca o temporario na frente

            }
        }
    }

    return 0;

}

int removerClienteCPF(listacliente *l, char *cpf)
{

    if(l == NULL) return 2;
    if(listaclienteVazia(l) == 0) return 1;

    No *noAux = NULL;
    No *nolistacliente = l->inicio;

    while(nolistacliente != NULL)
    {

        if(strcmp(nolistacliente->pessoa.cpf, cpf) == 0)
        {

            if(noAux == NULL)
            {

                if(nolistacliente->prox == NULL)
                {

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


int removerClientePosicao(listacliente *l, int pos)
{

    if(l == NULL) return 2;
    if(listaclienteVazia(l) == 0) return 1;
    if(pos < 0) return -2;

    if(pos == 0) return removerClienteInicio(l);

    No *noAux = NULL;
    No *nolistacliente = l->inicio;
    int p = 0;

    while((nolistacliente != NULL) && (pos < p))
    {

        noAux = nolistacliente;
        nolistacliente = nolistacliente->prox;
        p++;

    }

    /*
    if(pos < p)
        return -3; //posicao nao encontrada
    */

    if(noAux == NULL)
    {

        l->inicio = nolistacliente->prox;
        free(nolistacliente);
        return 0;

    }

    noAux->prox = nolistacliente->prox;
    free(nolistacliente);

    return 0;

}



int existeClienteCPF(listacliente *l, char *cpf)
{

    if(l == NULL) return 2;
    if(listaclienteVazia(l) == 0) return 1;

    No *nolistacliente = l->inicio;

    while(nolistacliente != NULL)
    {

        if(strcmp(nolistacliente->pessoa.cpf, cpf) == 0)
        {

            return 0;

        }

        nolistacliente = nolistacliente->prox;

    }

    return 1;

}



int removerClienteInicio(listacliente *l)
{

    if(l == NULL) return 2;
    if(listaclienteVazia(l) == 0) return 1;

    No *nolistacliente = l->inicio;

    if(nolistacliente->prox == NULL)
    {

        free(nolistacliente);
        l->inicio = NULL;
        return 0;

    }

    l->inicio = nolistacliente->prox;
    free(nolistacliente);

    return 0;
}



int removerClienteFinal(listacliente *l)
{

    if(l == NULL) return 2;
    if(listaclienteVazia(l) == 0) return 1;

    No *noAux = NULL;
    No *nolistacliente = l->inicio;

    while(nolistacliente->prox != NULL)
    {

        noAux = nolistacliente;
        nolistacliente = nolistacliente->prox;

    }

    if(noAux == NULL) l->inicio = NULL;
    else noAux->prox = NULL;

    free(nolistacliente);

    return 0;
}



int retornaClienteCPF(listacliente *l, Cliente *retorno, char *cpf)
{

    if(l == NULL) return 2;
    if(listaclienteVazia(l) == 0) return 1;

    No *nolistacliente = l->inicio;

    while(nolistacliente != NULL)
    {

        if(strcmp(nolistacliente->pessoa.cpf, cpf) == 0)
        {

            *retorno = nolistacliente->pessoa;

            return 0;

        }

        nolistacliente = nolistacliente->prox;

    }

    return 1;
}



int tamanho(listacliente *l)
{

    if(l == NULL) return 2;
    if(listaclienteVazia(l) == 0) return 0;

    No *nolistacliente = l->inicio;
    int contador = 0;

    while(nolistacliente != NULL)
    {

        contador++;
        nolistacliente = nolistacliente->prox;

    }

    return contador;
}



void mostrar(listacliente *l)
{

    if(l != NULL)
    {

        printf("Lista de Clientes:\n\n");

        if(listaclienteVazia(l) != 0)
        {

            No *nolistacliente = l->inicio;
            int i = 1;

            while(nolistacliente != NULL)
            {

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

void mostrarlistaclienteClienteNome(listacliente *l, char *nome)
{

    if(l != NULL)
    {

        printf("listacliente de Clientes com nome %s:\n\n", nome);

        if(listaclienteVazia(l) != 0)
        {

            No *nolistacliente = l->inicio;
            int i = 1;

            while(nolistacliente != NULL)
            {

                if(strcmp(nolistacliente->pessoa.nome, nome) == 0)
                {

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
