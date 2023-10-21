#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "clientela.h"

int main() {

    Lista *lista = criar();

    // Adicionando clientes
    Cliente cliente1 = {"Joao", "111.111.111-11"};
    Cliente cliente2 = {"Maria", "222.222.222-22"};
    Cliente cliente3 = {"Jose", "333.333.333-33"};
    Cliente cliente4 = {"Dantas", "000.000.000-00"};
    Cliente cliente5 = {"Ana", "121.121.121-12"};
    Cliente cliente6 = {"Rodrigo", "777.777.777-77"};
    Cliente cliente7 = {"Carlos", "333.333.333-35"};
    Cliente cliente8 = {"Bianca", "222.222.222-26"};
    Cliente cliente9 = {"Airton", "111.111.111-17"};
    Cliente cliente10 = {"Ana", "999.999.999-99"};

    adicionarClienteFinal(lista, cliente1);
    adicionarClienteFinal(lista, cliente2);
    adicionarClienteFinal(lista, cliente3);
    adicionarClienteFinal(lista, cliente4);
    adicionarClienteFinal(lista, cliente5);
    adicionarClienteFinal(lista, cliente6);
    adicionarClienteFinal(lista, cliente7);
    adicionarClienteFinal(lista, cliente8);
    adicionarClienteFinal(lista, cliente9);
    adicionarClienteFinal(lista, cliente10);

    //ordenar alfabeticamente
    printf("Ordenar a lista alfabeticamente:\n");
    int resultado = ordemAlfabetica(lista);
    if(resultado == 1) printf("Lista vazia");
    if(resultado == 3) printf("Lista possui apenas 1 elemento");
    if(resultado == 0) printf("Lista ordenada alfabeticamente com sucesso");


    // Mostrando a lista de clientes
    mostrar(lista);

    //Busca de cliente
    char cpfBusca[] = "222.222.222-22";
    if (existeClienteCPF(lista, cpfBusca) == 0) {
        printf("O cliente com CPF %s existe na lista.\n", cpfBusca);
    } else {
        printf("O cliente com CPF %s nao existe na lista.\n", cpfBusca);
    }

    //Retorno de cliente
    Cliente clienteEncontrado;
    char cpfRetorno[] = "111.111.111-11";
    if (retornaClienteCPF(lista, &clienteEncontrado, cpfRetorno) == 0) {
        printf("Cliente encontrado com CPF %s: Nome: %s\n", cpfRetorno, clienteEncontrado.nome);
    } else {
        printf("Cliente com CPF %s nao encontrado.\n", cpfRetorno);
    }

    //Remover cliente CPF
    char cpfRemocao[] = "333.333.333-33";
    if (removerClienteCPF(lista, cpfRemocao) == 0) {
        printf("Cliente com CPF %s removido com sucesso.\n", cpfRemocao);
    } else {
        printf("Nao foi possivel remover o cliente com CPF %s.\n", cpfRemocao);
    }

    mostrar(lista);

    printf("Tamanho da lista: %d\n", tamanho(lista));

    //Mostra lista com nome passado por parametro, a ideia é poder mostrar um cliente em específico ou uma lista de clientes com nomes repetidos
    mostrarListaClienteNome(lista, "Ana");

    return 0;
}
