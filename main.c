#include <stdio.h>
#include <stdlib.h>
#include "Regex Email/regex_email.c"
#include "Regex Email/regex_email.h"
#include "Regex Senha/regex_senha.c"
#include "Regex Senha/regex_senha.h"

void menuInterface(int *op);
int main(){

    int op;
    int isTrue = 1;
    

    while(isTrue){
    menuInterface(&op);
            switch(op){
            case 1:
                system("clear");
                regexEmail();
                
                break;
            case 2: 
                system("clear");
                regexSenha();
                
                break;
            default:
                system("clear");
                isTrue = 0;
                break;
        }
    }
    return 0;
}

void menuInterface(int *op){
    printf("|==================================|\n");
    printf("| Opcao 1: Email                   |\n");
    printf("| Opcao 2: Senha                   |\n");
    printf("| Opcao 0: Sair                    |\n");
    printf("|==================================|\n");
    scanf("%d", op);
}
