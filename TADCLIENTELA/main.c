#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "gerenciador.h"

int cadastrarlote(listalotes* l);

void IniciaLogin(listalotes* a, listacliente* b, lista* c, corretor corretorr);

void MostraLote(listalotes* l);

int cadastrarCliente(listacliente *b);

void mostrarCliente(listacliente *b);

int gerenciarClientes(listacliente *b);

int Simulador(listalotes* a, listacliente* b, corretor corretorr);

int FaturamentoCorretor(corretor corretorr, listalotes* a);

float FaturamentoTotal(listalotes* a);

void Cadastro(lista* l, char* email, char* senha);



int main()
{

    int opcao;
    listalotes* a = crialistalote();
    listacliente* b = criarlistacliente();
    lista* c = criarlistacorretor();

    while(opcao != 4)
    {
        system("cls");
        char email[40], senha[40];
        printf("Seja bem vindo!\n\n1- Login\n2-Cadastro\n3- Sobre\n4- Sair\n");
        scanf("%d", &opcao);
        if(opcao == 1)
        {
            system("cls");
            printf("Seja bem vindo novamente!\n\nInsira seu email:\n");
            scanf("%s", email);
            printf("Ótimo! Agora, sua senha:\n");
            scanf("%s", senha);
            if(VerificaUsuario(c, email, senha))
            {
                corretor corretorr;
                LoginUsuario(&corretorr, c, email);
                IniciaLogin(a, b, c, corretorr);
            }
        }

        if(opcao == 2)
        {
            system("cls");
            printf("Seja bem vindo!\n\nInsira seu email:\n");
            setbuf(stdin, NULL);
            scanf("%s", email);
            printf("Ótimo! Agora, a senha que deseja utilizar:\n");
            setbuf(stdin, NULL);
            scanf("%s", senha);
            Cadastro(c, email, senha);
        }

        if(opcao == 3);



    }
    return 0;
}


void IniciaLogin(listalotes* a, listacliente* b, lista* c, corretor corretorr)
{

    int opc = -1;
    while(opc!=10)
    {
        system("cls");
        printf("Seja bem vindo %s!\n", corretorr.nome);
        printf("O que voce deseja hoje?\n\n1- Cadastrar lote\n2- Gerenciar Clientes\n3- Ver lotes\n4- Simular Venda\n5- Vender Lote\n6- Ver meu faturamento\n7- Ver faturamento do empreendimento\n10- Sair\n");

        scanf("%d", &opc);

        if(opc == 1)      cadastrarlote(a); // (FEITO)

        else if(opc == 2) gerenciarClientes(b); // (FEITO)

        else if(opc == 3) MostraLote(a); //  (FEITO)

        else if(opc == 4) Simulador(a, b, corretorr);

        //else if(opc == 5) Venda(a, b, corretorr);

        else if(opc == 6) FaturamentoCorretor(corretorr, a); // FEITO

        else if(opc == 7) FaturamentoTotal(a); // FEITO

        else printf("Opcao Invalida!\n");




    }


}



int cadastrarlote(listalotes* l)
{
    system("cls");
    if(l == NULL)  return -1;

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

void MostraLote(listalotes* l)
{

    system("cls");
    int opc;
    mostrarlotes(l);
    printf("0 - Voltar\n");
    scanf("%d", &opc);
    if(opc == 0) return 0;
    else return MostraLote(l);


}

////

int cadastrarCliente(listacliente *b)
{

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

    if(op == 1)
    {

        return cadastrarCliente(b);

    }
    else
    {

        return ordemAlfabetica(b);

    }

    return 0;

}

void mostrarCliente(listacliente* b)
{

    system("cls");

    int op;

    mostrar(b);
    printf("0 - Voltar\n");
    printf("opcao: ");
    scanf("%d", &op);

    if(op == 0) return 0;
    else return mostrarCliente(b);

}

int gerenciarClientes(listacliente *b)
{

    system("cls");

    int op;
    char cpf[15];

    printf("1 - Adicionar cliente\n2 - Remover cliente\n3 - Mostrar clientes\n4 - Verificar cliente\n5 - Voltar\n");
    printf("opcao: ");
    scanf("%d", &op);

    if(op == 1)
    {

        cadastrarCliente(b);
        return gerenciarClientes(b); //função da main

    }

    if(op == 2)
    {

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
    if(op == 3)
    {

        mostrarCliente(b); //função da main
        return gerenciarClientes(b);

    }
    if(op == 4)
    {

        system("cls");

        int op;

        printf("Digite o cpf do cliente: ");
        setbuf(stdin, NULL);
        fgets(cpf, 15, stdin);
        if(existeClienteCPF(b, cpf) == 1) printf("\nCPF nao encontrado");
        else printf("\nO Cliente ja esta cadastrado");

        printf("\n0 - Voltar\n");
        printf("\nopcao: ");
        scanf("%d", &op);

        return gerenciarClientes(b);

    }
    if(op == 5)
    {

        return 0;

    }
    else
    {

        int i;

        printf("\nOpcao invalida\n");
        printf("\n0 - Continuar");
        printf("\nopcao: ");
        scanf("%d", &i);
        return gerenciarClientes(b);

    }

}

////
int Simulador(listalotes* a, listacliente* b, corretor corretorr)
{
    int op;
    //valorDoMetro -> informado pelo corretor
    //precoBruto -> calculado pelo sistema
    //valorVendido -> depende da forma de pagamento (armazena o valor final da venda)
    float valorDoMetro, precoBruto, valorVendido;
    int formaDePagamento, confirmacao;
    int idLote;
    char cpfCliente[15];
    lote *loteaux;
    Cliente *clienteaux;
    clienteaux = (Cliente*) malloc(sizeof(Cliente));

    do
    {
        printf("\n1 - Realizar venda\n");
        printf("2 - Verificar lotes reservados\n");
        printf("0 - Sair\n");
        scanf("%d", &op);
        switch (op)
        {
        case 1:
            system("cls");

            //Dados dos clientes
            printf("\nLista de clientes:\n");
            mostrar(b);
            printf("CPF do cliente: ");
            setbuf(stdin, NULL);
            fgets(cpfCliente, 15, stdin);

            retornaClienteCPF(b, clienteaux, cpfCliente);
            printf("caiu\n");

            //Dados dos lotes
            printf("\nLista de lotes disponiveis:\n");
            mostrardisponivel(a);
            printf("ID do lote: ");
            setbuf(stdin, NULL);
            scanf("%d", &idLote);


            //Orçamento do lote
            printf("Valor do metro quadrado do lote: ");
            setbuf(stdin, NULL);
            scanf("%f", &valorDoMetro);

            //Valor do lote
            lote loteamento;

            //    precoBruto = (valorDoMetro * (a->lote->area));
            precoBruto = 1;

            //Formas de pagamento

            system("cls");
            printf("\nFormas de pagamento:\n");
            printf("1 - A vista [ 1x de %f])\n", precoBruto);
            printf("2 - Parcelado em 2 vezes sem juros [ 2x de %f]\n", precoBruto/2);
            printf("3 - Parcelado em 3 vezes sem juros [ 3x de %f]\n", precoBruto/3);
            printf("4 - Parcelado em 4 vezes sem juros [ 4x de %f]\n", precoBruto/4);
            printf("5 - Parcelado em 5 vezes com juros [ 5x de %f]\n", ((precoBruto) * 1.1)/5);
            printf("6 - Parcelado em 6 vezes com juros [ 6x de %f]\n", ((precoBruto) * 1.15)/6);
            printf("7 - Parcelado em 7 vezes com juros [ 7x de %f]\n", ((precoBruto) * 1.2)/7);
            printf("8 - Parcelado em 8 vezes com juros [ 8x de %f]\n", ((precoBruto) * 1.25)/8);
            printf("9 - Parcelado em 9 vezes com juros [ 9x de %f]\n", ((precoBruto) * 1.3)/9);
            printf("10 - Parcelado em 10 vezes com juros [ 10x de %f]\n", ((precoBruto) * 1.35)/10);
            printf("11 - Parcelado em 11 vezes com juros [ 11x de %f]\n", ((precoBruto) * 1.4)/11);
            printf("12 - Parcelado em 12 vezes com juros [ 12x de %f]\n", ((precoBruto) * 1.45)/12);
            printf("0 - Sair\n");
            setbuf(stdin, NULL);
            scanf("%d", &formaDePagamento);
            switch (formaDePagamento)
            {
            case 1:
                valorVendido = precoBruto;
                break;
            case 2:
                valorVendido = precoBruto;
                break;
            case 3:
                valorVendido = precoBruto;
                break;
            case 4:
                valorVendido = precoBruto;
                break;
            case 5:
                valorVendido = ((precoBruto) * 1.1);
                break;
            case 6:
                valorVendido = ((precoBruto) * 1.15);
                break;
            case 7:
                valorVendido = ((precoBruto) * 1.2);
                break;
            case 8:
                valorVendido = ((precoBruto) * 1.25);
                break;
            case 9:
                valorVendido = ((precoBruto) * 1.3);
                break;
            case 10:
                valorVendido = ((precoBruto) * 1.35);
                break;
            case 11:
                valorVendido = ((precoBruto) * 1.4);
                break;
            case 12:
                valorVendido = ((precoBruto) * 1.45);
                break;
            case 0:
                break;
            default:
                printf("Opcao invalida\n");
                break;
            }

            //Confirmação da venda
            if(formaDePagamento != 0)
            {
                printf("\nConfirmar venda?\n");
                printf("1 - Sim\n");
                printf("2 - Nao\n");
                setbuf(stdin, NULL);
                scanf("%d", &confirmacao);
                if (confirmacao == 1)
                {
                    if ((lotevendido(a, idLote, *clienteaux, corretorr.creci, valorVendido)))
                    {
                        printf("entrei aqui");
                        sleep(10);
                        printf("Venda realizada com sucesso\n");
                        op = 0;
                        return 0;
                    }

                    else
                    {
                        printf("Erro ao realizar venda\n");
                        return 1;
                    }
                }
            }
            printf("FUDEU");
            break;
        case 2:
            system("cls");
            printf("\nLista de lotes reservados:\n");
            mostrarreservados(a);
            break;

        default:
            break;
        }


    }
    while (op != 0);
}
///

int FaturamentoCorretor(corretor corretorr, listalotes* a)
{

    system("cls");
    if (a == NULL) return -1;
    float v = 0;
    nolote* cl = a->inicio;
    while(cl!=NULL)
    {

        if(strcmp(corretorr.creci,(cl->valor).creci) == 0)
        v+= cl->valor.preco;
        cl = cl->prox;

    }
    printf("Seu faturamento total foi de R$ %f\n\n\n\n\nDigite qualquer numero para sair\n", v);
    scanf("%f", &v);

    return 1;

}

float FaturamentoTotal(listalotes* a)
{

    if (a == NULL) return -1;
    float v = 0;
    nolote* cl = a->inicio;
    while(cl!=NULL)
    {

        v+= cl->valor.preco;
        cl = cl->prox;

    }
    printf("O faturamento total do empreendimento foi de R$ %f\n\n\n\n\nDigite qualquer numero para sair\n", v);
    scanf("%f", &v);


    return 1;

}

void Cadastro(lista* l, char* email, char* senha)
{
    system("cls");
    printf("Perfeito! Agora, vamos coletar alguns dados pessoais...\n\n");
    char aux[100];
    corretor a;

    strcpy(a.email, email);
    strcpy(a.senha, senha);

    printf("Qual seu nome completo?\n");
    setbuf(stdin, NULL);
    fgets(aux, 49, stdin);
    strcpy(a.nome, aux);
    printf("Me informe agora seu endereco\n");
    setbuf(stdin, NULL);
    fgets(aux, 50, stdin);
    strcpy(a.endereco, aux);
    printf("Me informe agora seu cpf (SOMENTE NUMEROS):\n");
    setbuf(stdin, NULL);
    fgets(aux, 15, stdin);
    strcpy(a.cpf, aux);
    printf("Por ultimo, favor informe seu CRECI:\n");
    setbuf(stdin, NULL);
    fgets(aux, 19, stdin);
    strcpy(a.creci, aux);
    printf("Otimo! Realizando Cadastro...\n\n\n");
    novoCadastro(l, a);
}
