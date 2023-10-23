#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "Lotes.h"
#include "clientela.h"
#include "cliente.h"

int main() {

    
    int opcao;
    while(1){
    char email[40], senha[40];
    printf("Seja bem vindo!\n\n1- Login\n2-Cadastro\n3- Sobre\n4- Sair\n");
    if(opcao == 1){
        system(cls);
        printf("Seja bem vindo novamente!\n\nInsira seu email:\n");
        scanf("%s", email);
        printf("Ótimo! Agora, sua senha:\n");
        scanf("%s", senha);
    //   VerificaUsuario(l, usuario, senha);
    }
    else if(opcao == 2){
        system(cls);
        printf("Seja bem vindo!\n\nInsira seu email:\n");
        scanf("%s", email);
        printf("Ótimo! Agora, a senha que deseja utilizar:\n");
        scanf("%s", senha);
    //  InserirUsuario(l, usuario, senha);
    } else if(opcao == 3){
        
    }
    else if(opcao == 4)break;
    
    }
    return 0;
}
