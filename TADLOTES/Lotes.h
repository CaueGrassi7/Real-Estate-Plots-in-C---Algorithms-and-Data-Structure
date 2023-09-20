#ifndef LOTES_H_INCLUDED
#define LOTES_H_INCLUDED

struct Lote{

int tamanho;
char rua[50];
int quadra;
int num;

};
typedef struct Lote lote;

typedef struct No{
lote a;
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


#endif
