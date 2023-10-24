#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "Lotes.h"
#include "clientela.h"
#include "cliente.h"

int cadastrarlote(listalotes* l);

void IniciaLogin(listalotes* a, ListaCliente* b, ListaCorretor* c, corretor corretorr);

void MostraLote(listalotes* l);



int main()
{


    int opcao;
    listalotes* a = crialistalote();
    listacliente* b = criarlistacliente();
    lista* c = criarlistacorretor();

    while(1)
    {
        system("cls");
        char email[40], senha[40];
        printf("Seja bem vindo!\n\n1- Login\n2-Cadastro\n3- Sobre\n4- Sair\n");
        if(opcao == 1)
        {
            system("cls");
            printf("Seja bem vindo novamente!\n\nInsira seu email:\n");
            scanf("%s", email);
            printf("Ótimo! Agora, sua senha:\n");
            scanf("%s", senha);
            if(/*VerificaUsuario(l, usuario, senha)*/)
            {
                corretor* a;
                //LoginUsuario(corretor* a, ListaUsuario* b, char* email);
                
                //IniciaLogin(listalotes* l, ListaCliente* cliente, ListaCorretor* corretor, a);
            }
        }
        else if(opcao == 2)
        {
            system("cls");
            printf("Seja bem vindo!\n\nInsira seu email:\n");
            scanf("%s", email);
            printf("Ótimo! Agora, a senha que deseja utilizar:\n");
            scanf("%s", senha);
            //  InserirUsuario(l, usuario, senha);
        }
        else if(opcao == 3)
        {

        }
        else if(opcao == 4)break;

    }
    return 0;
}


void IniciaLogin(listalotes* l, ListaCliente* cliente, ListaCorretor* corretorr, corretor a)
{

    int opc = -1;
    while(opc!=10)
    {
        system("cls");
        printf("Seja bem vindo %s!\n", a.nome);
        printf("O que voce deseja hoje?\n\n1- Cadastrar lote\n2- Cadastrar cliente\n3- Ver clientes\n4- Ver lotes\n5- Gerenciar clientes\n6- Simular Venda\n7- Vender Lote\n8- Ver meu faturamento\n9- Ver faturamento do empreendimento\n10- Sair")

            if(opc == 1)      //cadastrarlote(a); (FEITO)

            else if(opc == 2) //cadastrarCliente(b); (FEITO)

            else if(opc == 3) // MostraCliente(b); (FEITO)

            else if(opc == 4) // MostraLote(a);  (FEITO)
                
            else if(opc == 5) // GerenciarCliente(b); (FEITO)
            
            else if(opc == 6) // Simulador(l, b, corretorr);
            
            else if(opc == 7) // Venda(l, b, corretorr);
            
            else if(opc == 8) // FaturamentoCorretor(corretorr, a);
            
            else if(opc == 9) // FaturamentoTotal(a);

            else printf("Opcao Invalida!\n");




    }


}

 int cadastrarlote(listalotes* l){
     system("cls");
    if(lote == NULL)  return -1;
    
    lote a;
    char buffer[50];
    int aux;
    printf("Qual a rua onde se encontra o lote?\n");
    setbuf(stdin, NULL);
    fgets(buffer, 49, stdin);
    strcpy(a.rua, buffer);
    printf("Qual a quadra onde se encontra o lote?\n");
    scanf("%d", &aux);
    a.quadra = aux;
    printf("E qual o numero do lote?\n");
    scanf("%d", &aux);
    a.num = aux;
    a.status = 1;
    a.cliente = (char*) calloc (30, sizeof(char));
    a.creci = (char*) calloc (30, sizeof(char));
    if(inserelote(l, a))printf("Lote cadastrado com sucesso!\n");
    
    printf("Deseja continuar cadastrando?\n1-Sim\n2-Nao\n");
    scanf("%d", &aux);
    if(aux == 1) return cadastrarlote(l);
    
    return 0;
    
}

void MostraLote(listalotes* l){

system("cls");
int opc;
mostrarlotes(l);
printf("0 - Voltar\n");
scanf("%d", &opc);
if(opc == 0) return 0;
else return MostraLote(l);


}
