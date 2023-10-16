#ifndef LOTES_H_INCLUDED
#define LOTES_H_INCLUDED

struct Lote{

int tamanho;
char rua[50];
int quadra;
int num;
int status;
};

typedef struct Lote lote;

typedef struct No{
lote valor;
int pos;
no* prox;
}no;

typedef struct listaLotes{
no* inicio;

}listalotes;

listalotes* crialistalote(){
    listalotes* l = (listalotes*) malloc (sizeof(listalotes));
    l -> inicio = NULL;
    return l;
}

/*
int inserelote(listalotes* l, lote a){
    if(l == NULL) return -1;
    if(l->inicio ==  NULL) return 1;
    no* cl = (no*) malloc(sizeof(no));
    no* aux;
    aux = l->inicio;
    while(aux->prox != NULL && strcmp(a.rua, (aux->prox->valor).rua)>0){
        aux = aux->prox;
    }
    cl->prox = aux->prox;
    aux->prox = cl;
    cl->valor = a;
    return 0;
}
*/



int buscalote(listalotes* l, lote a);
int statuslote(listalotes* l, int pos);
int mudastatus(listalotes* l, int pos);
int removelote(listalotes* l, int pos);
void mostrarlotes(listalotes* l);
void mostrardisponivel(listalotes* l);
void mostrarreservados(listalotes* l);
void mostrarvendidos(listalotes* l);
int mostrarua(listalotes* l, char* rua);
int mostrapos(listalotes* l, int pos);
int mostracorretor(listalotes* l, char* creci);
int mostracliente(listalotes* l, cliente a);









#endif
