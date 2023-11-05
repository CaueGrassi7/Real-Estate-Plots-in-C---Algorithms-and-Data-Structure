#include "Lotes.h"
#include "cliente.h"
#include "clientela.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>



// TIPO LOTE
struct Lote
{

    int id; // CODIGO DE IDENTIFICAÇÃO DO LOTE. NÃO REPRESENTA NADA ALEM DE IDENTIFICAÇÃO.
    int tamanho; // DADOS               // (CÓDIGO ÚNICO DE CADA LOTE, MESMO QUE EXCLUIDO)
    char rua[50]; // DO
    int quadra;   // LOTE
    int num;
    int status; // SITUAÇÃO ATUAL DO LOTE (1 - LIVRE, 2 - RESERVADO, 3 -  VENDIDO);
    char* cliente;
    char* creci; // CORRETOR RESPONSAVEL
    float preco;
};
typedef struct Lote lote;


// NÓ DA LISTA
typedef struct nolote
{
    lote valor;
    nolote* prox;
} nolote;


// TIPO LISTA DE LOTES
typedef struct listaLotes
{
    nolote* inicio;
    int cod; // VARIAVEL PARA CONTROLE DE LOTES E PARA ATRIBUIR OS CÓDIGOS DE CADA LOTE.
}listalotes;


// CRIAÇÃO DA LISTA DE LOTES
listalotes *crialistalote()
{
    listalotes* l = (listalotes*) malloc (sizeof(listalotes)); // ALOCA A LISTA E CRIA A LISTA;
    l -> inicio = NULL; // COLOCA O INICIO PARA APONTAR PARA NADA;
    l -> cod = 0; // ZERA A QUANTIDADE DE LOTES;
    return l;
}



// INSERÇÃO DO LOTE EM ORDEM (RUA).
int inserelote(listalotes* l, lote a){
    if(l == NULL) return 0;
    nolote* nolotevoLote = (nolote*)malloc(sizeof(nolote));
    nolotevoLote->valor = a;
    nolotevoLote->prox = NULL;
    nolotevoLote->valor.creci = 0;
    nolotevoLote->valor.cliente = " ";
    nolotevoLote->valor.preco = 0;

    if (l->inicio == NULL || strcmp(a.rua, l->inicio->valor.rua) < 0) {
        // Inserir nolote início da lista
        nolotevoLote->prox = l->inicio;
        l->inicio = nolotevoLote;
    }
    else {
        nolote* atual = l->inicio;
        while (atual->prox != NULL && strcmp(a.rua, atual->prox->valor.rua) >= 0) {
            atual = atual->prox;
        }
        // Inserir após o nó 'atual'
        nolotevoLote->prox = atual->prox;
        atual->prox = nolotevoLote;
    }

    nolotevoLote->valor.id == l->cod;
    l->cod++;
    return 1;
}





// FUNÇÃO QUE BUSCA UM LOTE UTILIZANDO SEU ID
// RETORNA 1 SE ENCONTRA
// RETORNA 0 SE NÃO
int buscalote(listalotes* l, lote a)
{
    if(l == NULL) return 0;
    if(listavazia(l)) return 0;
    nolote* cl = l->inicio;
    while(cl!=NULL)
    {
        if((cl->valor).id == a.id) return 1;
        cl = cl->prox;
    }
    return 0;
}



// FUNÇÃO QUE RETORNA O STATUS DO LOTE
// (0 - LOTE NÃO ENCONTRADO 1 - LIVRE, 2 - RESERVADO, 3 -  VENDIDO);
int statuslote(listalotes* l, int id)
{
    if(l == NULL) return 0;
    if(listavazia(l)) return 0;
    nolote* cl = l->inicio;
    while(cl!=NULL)
    {
        if((cl->valor).id == id) return ((cl->valor).status);
        cl = cl->prox;
    }
    return 0;
}



// FUNÇÃO QUE ALTERA O STATUS DE UM DADO LOTE.
// RETORNA 0 SE NÃO ENCONTRADO
// RETORNA 1 SE FUNÇÃO FEITA COM SUCESSO
int mudastatus(listalotes* l, int id, int status)
{
    if(l == NULL) return 0;
    if(listavazia(l)) return 0;
    nolote* cl = l->inicio;
    while(cl!=NULL)
    {
        if((cl->valor).id == id)
        {
            (cl->valor).status == status;
            return 1;
        }
        cl = cl->prox;
    }
    return 0;
}


// FUNÇÃO QUE REMOVE UM CERTO LOTE POR SUA IDENTIFICAÇÃO
// RETORNA 1 SE OPERAÇÃO REALIZADA
// RETORNA 0 SE NÃO ENCONTRADO
int removelote(listalotes* l, int id)
{
    if(l == NULL) return 0;
    if(listavazia(l)) return 0;
    nolote* cl = l->inicio;
    if((cl->valor.id) == id){
        l->inicio = cl->prox;
        free(cl);
        return 1;
    }else while(cl->prox!=NULL)
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

// MOSTRA OS LOTES NA ORDEM EM QUE ESTÃO NA LISTA (ORDEM ALFABÉTICA PELA RUA)
// MODELO A SER MOSTRADO:
// [ID] [RUA] [QUADRA] [NUMERO] [STATUS] [CLIENTE] [CRECI]
void mostrarlotes(listalotes* l)
{
    printf("[ID] [RUA]                [QUADRA] [NUMERO] [STATUS] [CLIENTE] [CRECI]\n");
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

            printf("[%d] [%s] [%d] [%d] [%d] [%s] [%d]\n", a->valor.id, aux, a->valor.quadra, a->valor.num, a->valor.status, a->valor.cliente, a->valor.creci);
            a = a->prox;
        }
    }
}


// MOSTRA OS LOTES NA ORDEM EM QUE ESTÃO NA LISTA, SE DISPONIVEIS (ORDEM ALFABÉTICA PELA RUA)
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

                printf("[%d] [%s] [%d] [%d] [%d] [%s] [%d]\n", a->valor.id, aux, a->valor.quadra, a->valor.num, a->valor.status, a->valor.cliente, a->valor.creci);
            }
            a = a->prox;
        }
    }

}

// MOSTRA OS LOTES NA ORDEM EM QUE ESTÃO NA LISTA, SE RESERVADOS (ORDEM ALFABÉTICA PELA RUA)
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

                printf("[%d] [%s] [%d] [%d] [%d] [%s] [%d]\n", a->valor.id, aux, a->valor.quadra, a->valor.num, a->valor.status, a->valor.cliente, a->valor.creci);
            }
            a = a->prox;
        }
    }


}

// MOSTRA OS LOTES NA ORDEM EM QUE ESTÃO NA LISTA, SE VENDIDOS (ORDEM ALFABÉTICA PELA RUA)
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

                printf("[%d] [%s] [%d] [%d] [%d] [%s] [%d]\n", a->valor.id, aux, a->valor.quadra, a->valor.num, a->valor.status, a->valor.cliente, a->valor.creci);
            }
            a = a->prox;
        }
    }

}


// MOSTRA OS LOTES NA ORDEM EM QUE ESTÃO NA LISTA, PELA RUA
// MODELO A SER MOSTRADO:
// [ID] [RUA] [QUADRA] [NUMERO] [STATUS] [CLIENTE] [CRECI]
void mostrarua(listalotes* l, char* rua){
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

                printf("[%d] [%s] [%d] [%d] [%d] [%s] [%d]\n", a->valor.id, aux, a->valor.quadra, a->valor.num, a->valor.status, a->valor.cliente, a->valor.creci);
            }
            a = a->prox;
        }
    }



}

// MOSTRA OS LOTES NA ORDEM EM QUE ESTÃO NA LISTA, PELO ID
// MODELO A SER MOSTRADO:
// [ID] [RUA] [QUADRA] [NUMERO] [STATUS] [CLIENTE] [CRECI]
void mostraid(listalotes* l, int id){
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

                printf("[%d] [%s] [%d] [%d] [%d] [%s] [%d]\n", a->valor.id, aux, a->valor.quadra, a->valor.num, a->valor.status, a->valor.cliente, a->valor.creci);
                break;
            }
            a = a->prox;
        }
    }
}


// MOSTRA OS LOTES NA ORDEM EM QUE ESTÃO NA LISTA, DE ACORDO COM CORRETOR
// MODELO A SER MOSTRADO:
// [ID] [RUA] [QUADRA] [NUMERO] [STATUS] [CLIENTE] [CRECI]
void mostracorretor(listalotes* l, char* creci){
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

                printf("[%d] [%s] [%d] [%d] [%d] [%s] [%d]\n", a->valor.id, aux, a->valor.quadra, a->valor.num, a->valor.status, a->valor.cliente, a->valor.creci);

            }
            a = a->prox;
        }
    }
}

// MOSTRA OS LOTES NA ORDEM EM QUE ESTÃO NA LISTA, DE ACORDO COM CLIENTE
// MODELO A SER MOSTRADO:
// [ID] [RUA] [QUADRA] [NUMERO] [STATUS] [CLIENTE] [CRECI]
void mostracliente(listalotes* l, cliente b){
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

                printf("[%d] [%s] [%d] [%d] [%d] [%s] [%d]\n", a->valor.id, aux, a->valor.quadra, a->valor.num, a->valor.status, a->valor.cliente, a->valor.creci);
            }
            a = a->prox;
        }
    }
}

// FUNÇÃO QUE ALTERA UM LOTE COMO VENDIDO
int lotevendido(listalotes* l, int id, cliente a, char* creci, float preco){
    if(l == NULL) return 0;
    if(listavazia(l)) return 0;
    nolote* cl = l->inicio;
    while(cl!=NULL)
    {
        if((cl->valor).id == id) {
            cl->valor.status = 3;
            cl->valor.cliente = a.nome;
            strcpy(cl->valor.creci, creci);
            cl->valor.preco = preco;
            return 1;
        }
        cl = cl->prox;
    }
    return 0;
}





