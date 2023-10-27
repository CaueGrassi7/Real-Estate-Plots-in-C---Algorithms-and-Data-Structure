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

////

int cadastrarCliente(listacliente *b);

void mostrarCliente(listacliente *b);

int gerenciarClientes(listacliente *b);

////

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
        printf("O que voce deseja hoje?\n\n1- Cadastrar lote\n2- Gerenciar Clientes\n3- Ver lotes\n4- Simular Venda\n5- Vender Lote\n6- Ver meu faturamento\n7- Ver faturamento do empreendimento\n10- Sair")

            if(opc == 1)      //cadastrarlote(a); (FEITO)

            else if(opc == 2) //gerenciarClientes(b); (FEITO)

            else if(opc == 3) // MostraLote(a); (FEITO)

            else if(opc == 4) // Simulador(l, b, corretorr);
                
            else if(opc == 5) // Venda(l, b, corretorr);
            
            else if(opc == 6) // FaturamentoCorretor(corretorr, a);
            
            else if(opc == 7) // FaturamentoTotal(a);

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

////

int cadastrarCliente(listacliente *b){

    if(b == NULL) return -1;

    system("cls");

    printf("CADASTRO DE CLIENTE:\n");

    Cliente a;

    printf("\nDigite o NOME COMPLETO do cliente: ");
    setbuf(stdin, NULL);
    fgets(a.nome, 50, stdin);
    printf("\nDigite o CPF do cliente (ex: 12345678910): ");
    setbuf(stdin, NULL);
    fgets(a.cpf, 15, stdin);
    printf("\nDigite o endereco do cliente (ex: rua/avenida numero): ");
    setbuf(stdin, NULL);
    fgets(a.endereco, 40, stdin);
    printf("\nDigite o email do cliente (ex: nome@gmail.com): ");
    setbuf(stdin, NULL);
    fgets(a.email, 40, stdin);

    if(adicionarClienteFinal(b, a) == 0)
        printf("\nCliente cadastrado com sucesso!\n\n");

    int op;

    printf("Deseja cadastrar outro cliente:\n1 - sim\n2 - nao\nopcao: ");
    scanf("%d", &op);

    if(op == 1){

        return cadastrarCliente(b);

    }
    else{

    return ordemAlfabetica(b);

    }

    return 0;

}

void mostrarCliente(b){

    system("cls");

    int op;

    mostrar(b);
    printf("0 - Voltar\n");
    printf("opcao: ");
    scanf("%d", &op);

    if(op == 0) return 0;
    else return mostrarCliente(b);

}

int gerenciarClientes(listacliente *b){

    system("cls");

    int op;
    char cpf[15];

    printf("1 - Adicionar cliente\n2 - Remover cliente\n3 - Mostrar clientes\n4 - Verificar cliente\n5 - Voltar\n");
    printf("opcao: ");
    scanf("%d", &op);

    if(op == 1){

        cadastrarCliente(b);
        return gerenciarClientes(b); //função da main

    }

    if(op == 2){

        system("cls");

        int op;

        printf("Digite o cpf do cliente que deseja remover: ");
        setbuf(stdin, NULL);
        fgets(cpf, 15, stdin);
        if(removerClienteCPF(b, cpf) == 1) printf("\nCPF nao encontrado\n");
        else printf("\nCliente removido com sucesso!\n");

        printf("\n0 - Voltar\n");
        printf("opcao: ");
        scanf("%d", &op);

        return gerenciarClientes(b);

    }
    if(op == 3){

        mostrarCliente(b); //função da main
        return gerenciarClientes(b);

    }
    if(op == 4){

        printf("Digite o cpf do cliente");
        setbuf(stdin, NULL);
        fgets(cpf, 15, stdin);
        if(existeClienteCPF(b, cpf) == 1) printf("CPF nao encontrado");
        return gerenciarClientes(b);

    }
    else{

        return 0;

    }

}

////
