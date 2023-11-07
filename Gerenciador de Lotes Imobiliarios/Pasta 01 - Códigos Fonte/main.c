#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "gerenciador.h"

int cadastrarlote(listalotes* l);

void MostraLoteReservado(listalotes* l);

void removeespaco(char* s);

void IniciaLogin(listalotes* a, listacliente* b, lista* c, corretor corretorr, listalotes* h);

void MostraLote(listalotes* l);

int cadastrarCliente(listacliente *b);

void mostrarCliente(listacliente *b);

int gerenciarClientes(listacliente *b);

int Simulador(listalotes* a, listacliente* b, corretor corretorr, listalotes* h);

int FaturamentoCorretor(corretor corretorr, listalotes* a);

float FaturamentoTotal(listalotes* a);

void Cadastro(lista* l, char* email, char* senha);

int MostrarHistorico(listalotes* l); //  MOSTRA A PILHA DE VENDAS (HISTÓRICO)


int main()
{

    int opcao;
    listalotes* a = crialistalote();
    listalotes* h = crialistalote();
    listacliente* b = criarlistacliente();
    lista* c = criarlistacorretor();

    while(opcao != 4)
    {
        system("cls");
        char email[40], senha[40];
        printf("Seja bem vindo!\n\n1- Login\n2- Cadastro\n3- Sobre\n4- Sair\n");
        scanf("%d", &opcao);
        getchar();
        if(opcao == 1)
        {
            system("cls");
            printf("Seja bem vindo novamente!\n\nInsira seu email:\n");
            scanf("%s", email);
            getchar();
            printf("Otimo! Agora, sua senha:\n");
            scanf("%s", senha);
            getchar();
            if(VerificaUsuario(c, email, senha)) // Verifica usuario e senha
            {
                corretor corretorr;
                LoginUsuario(&corretorr, c, email); // Dá valor à variável corretorr, que será usada ao longo do código
                IniciaLogin(a, b, c, corretorr, h);
            }
            else{
                printf("Login Invalido!\n");
                sleep(6);
            }
        }

        if(opcao == 2)
        {
            system("cls");
            printf("Seja bem vindo!\n\nInsira seu email:\n");
            setbuf(stdin, NULL);
            scanf("%s", email);
            getchar();
            printf("Otimo! Agora, a senha que deseja utilizar:\n");
            setbuf(stdin, NULL);
            scanf("%s", senha);
            getchar();
            Cadastro(c, email, senha);
        }

        if(opcao == 3){
            system("cls");
            printf("Feito por:\n\nCaue Grassi, Enzo Faria, Malcon Rezende, Murilo Beppler\n");
            sleep(10);
        }



    }
    return 0;
}


void IniciaLogin(listalotes* a, listacliente* b, lista* c, corretor corretorr, listalotes* h){

    int opc = -1;
    while(opc!=10)
    {
        system("cls");
        printf("Seja bem vindo %s!\n", corretorr.nome);
        printf("O que voce deseja hoje?\n\n1- Cadastrar lote\n2- Gerenciar Clientes\n3- Ver lotes\n4- Simular Venda\n5- Checar Reservados\n6- Ver meu faturamento\n7- Ver faturamento do empreendimento\n8- Ver Historico de Vendas\n10- Sair\n");
        scanf("%d", &opc);
        getchar();

        if(opc == 1)      cadastrarlote(a); 

        else if(opc == 2) gerenciarClientes(b); 

        else if(opc == 3) MostraLote(a); 

        else if(opc == 4) Simulador(a, b, corretorr, h);

        else if(opc == 5) MostraLoteReservado(a);

        else if(opc == 6) FaturamentoCorretor(corretorr, a); 

        else if(opc == 7) FaturamentoTotal(a); 

        else if(opc == 8) MostrarHistorico(h); 

        else printf("Opcao Invalida!\n");




    }


}


// Trata a variável lote para somente depois disto enviá-la a lista
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
    removeespaco(buffer);
    strcpy(a.rua, buffer);
    printf("Qual a quadra onde se encontra o lote?\n");
    scanf("%d", &aux);
    getchar();
    a.quadra = aux;
    printf("E qual o numero do lote?\n");
    scanf("%d", &aux);
    getchar();
    a.num = aux;
    printf("Qual o tamanho em metro quadrado do lote cadastrado?\n");
    scanf("%d", &aux);
    getchar();
    a.tamanho = aux;
    a.status = 1;
    a.creci = (char*) calloc (30, sizeof(char));
    if(inserelote(l, a))printf("Lote cadastrado com sucesso!\n");

    printf("Deseja continuar cadastrando?\n1-Sim\n2-Nao\n");
    scanf("%d", &aux);
    getchar();
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
    getchar();
    if(opc == 0) return 0;
    else return MostraLote(l);


}



void MostraLoteReservado(listalotes* l)
{

    system("cls");
    int opc;
    mostrarreservados(l);
    printf("Deseja Reservar algum lote?\n1- Sim\n2- Remover Reserva\n0 - Voltar\n");
    scanf("%d", &opc);
    getchar();

    if(opc == 1){

        system("cls");
        mostrardisponivel(l);
        printf("Escreva o id do lote a ser reservado:\n");
        scanf("%d", &opc);
        mudastatus(l, opc, 2);
        return 1;
    }
    if(opc == 2){

        printf("Escreva o id do lote a ser liberado:\n");
        scanf("%d", &opc);
        mudastatus(l, opc, 1);
    }

    if(opc == 0) return 0;
    else return MostraLote(l);



}


// Trata a variável Cliente para somente depois disto enviá-la a lista
int cadastrarCliente(listacliente *b)
{

    if(b == NULL) return -1;

    system("cls");

    printf("CADASTRO DE CLIENTE:\n");

    Cliente a;

    printf("\nDigite o NOME COMPLETO do cliente: ");
    setbuf(stdin, NULL);
    fgets(a.nome, 50, stdin);
    removeespaco(a.nome);
    printf("\nDigite o CPF do cliente (ex: 12345678910): ");
    setbuf(stdin, NULL);
    fgets(a.cpf, 15, stdin);
    removeespaco(a.cpf);
    printf("\nDigite o endereco do cliente (ex: rua/avenida numero): ");
    setbuf(stdin, NULL);
    fgets(a.endereco, 40, stdin);
    removeespaco(a.endereco);
    printf("\nDigite o email do cliente (ex: nome@gmail.com): ");
    setbuf(stdin, NULL);
    fgets(a.email, 40, stdin);
    removeespaco(a.email);

    if(adicionarClienteFinal(b, a) == 0)
        printf("\nCliente cadastrado com sucesso!\n\n");

    int op;

    printf("Deseja cadastrar outro cliente:\n1 - sim\n2 - nao\nopcao: ");
    scanf("%d", &op);
    getchar();

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
    getchar();

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
    getchar();

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
        removeespaco(cpf);
        if(removerClienteCPF(b, cpf) == 1) printf("\nCPF nao encontrado\n");
        else printf("\nCliente removido com sucesso!\n");

        printf("\n0 - Voltar\n");
        printf("opcao: ");
        scanf("%d", &op);
        getchar();

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
        removeespaco(cpf);
        if(existeClienteCPF(b, cpf) == 1) printf("\nCPF nao encontrado");
        else printf("\nO Cliente ja esta cadastrado");

        printf("\n0 - Voltar\n");
        printf("\nopcao: ");
        scanf("%d", &op);
        getchar();

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
        getchar();
        return gerenciarClientes(b);

    }

}

// Simulador de vendas. Também realiza a venda caso a mesma seja confirmada, usando a lotevendido do TAD lotes
int Simulador(listalotes* a, listacliente* b, corretor corretorr, listalotes* h)
{
    int op;
    //valorDoMetro -> informado pelo corretor
    //precoBruto -> calculado pelo sistema
    //valorVendido -> depende da forma de pagamento (armazena o valor final da venda)
    float valorDoMetro, precoBruto, valorVendido;
    int formaDePagamento, confirmacao;
    int idLote;
    char cpfCliente[15];
    int tamanhoDoLote;
    Cliente *clienteaux;
    clienteaux = (Cliente*) malloc(sizeof(Cliente));

    do
    {
        system("cls");
        printf("\n1 - Realizar venda\n");
        printf("2 - Verificar lotes reservados\n");
        printf("0 - Sair\n");
        scanf("%d", &op);
        getchar();
        switch (op)
        {
        case 1:
            system("cls");

            //Dados dos clientes
            mostrar(b);
            printf("CPF do cliente: ");
            setbuf(stdin, NULL);
            fgets(cpfCliente, 15, stdin);
            removeespaco(cpfCliente);
            if(retornaClienteCPF(b, clienteaux, cpfCliente) == 1)
            {
                printf("\nCPF nao encontrado\n");
                sleep(5);
                return 1;
            }

            //Dados dos lotes
            printf("\nLista de lotes disponiveis:\n");
            mostrardisponivel(a);
            printf("\nID do lote: ");
            setbuf(stdin, NULL);
            scanf("%d", &idLote);
            getchar();
            if ((tamanholote(a, idLote)) == 0)
            {
                printf("ID invalido\n");
                sleep(5);
                return 1;
            }

            //Orçamento do lote
            printf("\nValor do metro quadrado do lote: ");
            setbuf(stdin, NULL);
            scanf("%f", &valorDoMetro);
            getchar();
            if(((valorDoMetro) == 0) || ((valorDoMetro) < 0))
            {
                printf("Valor invalido\n");
                return 1;
            }

            //Valor do lote
            tamanhoDoLote = tamanholote(a, idLote);
            precoBruto = valorDoMetro * tamanhoDoLote;

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
            getchar();
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
                getchar();
                if (confirmacao == 1)
                {
                    if ((lotevendido(a, idLote, *clienteaux, corretorr.creci, valorVendido)))
                    {
                        printf("Venda realizada com sucesso\n");
                        op = 0;
                        lote lot;
                        buscarid(a, idLote, &lot);
                        inserirfim(h, lot);
                        return 0;
                    }

                    else
                    {
                        printf("Erro ao realizar venda\n");
                        sleep(5);
                        return 1;
                    }
                }
            }
            break;
        case 2:
            system("cls");
            printf("\nLista de lotes reservados:\n");
            mostrarreservados(a);
            sleep(10);
            break;

        default:
            break;
        }


    }
    while (op != 0);
}

// Mostra o faturamento associado ao CRECI do usuário LOGADO NO MOMENTO
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
    getchar();

    return 1;

}

// Mostra o faturamento total do empreendimento, independente do creci do usuario
float FaturamentoTotal(listalotes* a)
{
    system("cls");
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
    getchar();

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
    removeespaco(aux);
    strcpy(a.nome, aux);
    printf("Me informe agora seu endereco\n");
    setbuf(stdin, NULL);
    fgets(aux, 50, stdin);
    removeespaco(aux);
    strcpy(a.endereco, aux);
    printf("Me informe agora seu cpf (SOMENTE NUMEROS):\n");
    setbuf(stdin, NULL);
    fgets(aux, 15, stdin);
    removeespaco(aux);
    strcpy(a.cpf, aux);
    printf("Por ultimo, favor informe seu CRECI:\n");
    setbuf(stdin, NULL);
    fgets(aux, 19, stdin);
    removeespaco(aux);
    strcpy(a.creci, aux);
    printf("Otimo! Realizando Cadastro...\n\n\n");
    novoCadastro(l, a);
}


// UTILIZADA PARA REMOVER O "ENTER" AO FINAL DE CADA STRING LIDA COM FGETS. USADA PARA OTIMIZAR VISUALMENTE O PROGRAMA
void removeespaco(char* s){

    s[(strlen(s)-1)] = '\0';

}

int MostrarHistorico(listalotes* l){
    system("cls");
    if(l == NULL) return -1;
    lote n;
    listalotes* auxiliar = crialistalote();
    while(pop(l, &n)) inserirfim(auxiliar, n);
    mostrarlotes(auxiliar);
    while(pop(auxiliar, &n)) inserirfim(l, n);  
    
    printf("0 - Voltar\n");
    int o = -1;
    scanf("%d", &o);
    return 1;
}

