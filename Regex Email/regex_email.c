#include <stdio.h>
#include <stdlib.h>
#include <regex.h>
#include <string.h>
#include <time.h>
#include <sys/types.h>


void regexMenu(int *op);

void regexEmail(){
    regex_t er; // armazena a expressao regular
    int isBoolean, isTrue = 1; // verificadores booleanos
    int op = 0; // armazena a opcao da interface
    int save; // armazena valor para salvar ou nao no arquivo de saida
    char *exp = "^[A-Za-z0-9._%+-]+@[A-Za-z0-9.-]+\\.[A-Za-z]{2,}$"; // expressao regular
    char *emailString; // email de entrada para ver se eh ou nao aceito pela expressao regular
    emailString = malloc(20 * sizeof(char));

    // aqui vamos criar uma db em txt que ira armazenar os emails gerados com regex
    FILE *emaildb; // cria um ponteiro para o arquivo que vai ser criado
    emaildb = fopen("../emaildb", "w"); // abre o arquivo que vai ser armazenado os resultados

    // Compilado a expressao regular
    isBoolean = regcomp(&er, exp, REG_EXTENDED);
    if (isBoolean != 0){ // se for diferente de 0, quer dizer que a expreesao eh invalida
        printf("Erro ao compilar a expressao");
        exit(1);
    }

    
    // Regexec
    while (isTrue){

        regexMenu(&op);

        switch(op){
            case 0: // opcao de saida do terminal
                system("clear"); 
                isTrue = 0;
                break;
            case 1: // opcao que faz a comparacao da string com a expressao regular
                system("clear"); 
                printf("Digite um Email: \n");
                scanf("%s", emailString);
                            

                isBoolean = regexec(&er, emailString, 0, NULL, 0); // se isboolean for  == 0, compilou com sucesso
                                  
                
                if(isBoolean == 0){
                    system("clear"); 
                    printf("Email Verificado com sucesso!\nGostaria de salvar o resultado?\n[1 = sim / 0 = nao]\n");
                    scanf("%d", &save);  
                    if (save == 1){
                        fprintf(emaildb, "%s\n", emailString); //printasdf no arquivo o email
                    }
                    system("clear"); // limpa a tela
                } else{
                    system("clear"); // limpa a tela
                    printf("Email Invalido => [%s]\n", emailString);
                }
                
                break;
            default: // qualquer outro caractere fora de 0 e 1
                system("clear"); 
                break;
        }

    }
    fclose(emaildb); // libera da memoria o ponteiro
    regfree(&er);
}

void regexMenu(int *op){
    printf("|=============================|\n");
    printf("|1 - Inseir Email?            |\n");
    printf("|0 - Sair                     |\n");
    printf("|=============================|\n");

    scanf("%d", op);
}


