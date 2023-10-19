#ifndef LOTES_H_INCLUDED
#define LOTES_H_INCLUDED

struct Lote{

int id;
int tamanho;
char rua[50];
int quadra;
int num;
int status;
char* cliente;
char* creci;
};

typedef struct Lote lote;

typedef struct No{
lote valor;
no* prox;
}no;

typedef struct listaLotes{
no* inicio;
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
void mostracliente(listalotes* l, cliente a);
int lotevendido(listalotes* l, int id, cliente a, int creci);









#endif
