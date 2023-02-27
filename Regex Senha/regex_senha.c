#include <stdio.h>
#include <stdlib.h>
#include <regex.h>
#include <sys/types.h>

void menuSenha(int *op);
void regex(FILE *openfile);


void regexSenha(){

    int opcao;
    int isTrue = 1;
    FILE *openfile;
    openfile = fopen("../senha", "w");

    while(isTrue){
        menuSenha(&opcao);

        switch(opcao){
            case 0:
                system("clear");
                isTrue = 0;
                break;
            case 1:
                system("clear");
                regex(openfile);
                break;
            default:
                break;


        }
    }

    fclose(openfile);

    

    
}

void menuSenha(int *op){
    printf("|==========================|\n");
    printf("| 1 - Inserir Senha:       |\n");
    printf("| 0 - Sair:                |\n");
    printf("|==========================|\n");

    scanf("%d", op);
}



void regex (FILE *openfile){
    regex_t regex;
    int isBoolean;
    char *senha;
    senha = malloc(20 * sizeof(char));
    printf("Digite uma Senha: ");
    scanf("%s", senha);

    isBoolean = regcomp(&regex,"^[[:alnum:]]{8,20}$", REG_EXTENDED);
    isBoolean = regexec(&regex,senha, 0, NULL, 0);
    if (isBoolean == 0){
        printf("\n -- senha aceita -- \n");
        fprintf(openfile, "%s", "Senha: " );
        fprintf(openfile, "%s", senha);
        fprintf(openfile, "%s\n", " => Status: Senha Simples");
        regfree(&regex);
    } 
    if ( isBoolean != 0 && regcomp(&regex,"^[[:print:]]{8,20}$", REG_EXTENDED) == 0 ){
            if (regexec(&regex, senha, 0, NULL, 0) == 0){
                printf("\n -- senha aceita -- \n");
                fprintf(openfile, "%s", "Senha: " );
                fprintf(openfile, "%s", senha);
                fprintf(openfile, "%s\n", " => Status: Senha Complexos");
                regfree(&regex);
            }
            
    }   
    free(senha);
    
}
