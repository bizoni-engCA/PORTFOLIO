#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    int result = 0;
    char comando[100];
    int a = 10;
    while(1){
    printf("myterm>");
    scanf("%s", comando);
    printf("\n");
    printf("%s \n", comando);
    if(strcmp("calculadora", comando)==0){
        printf("Entre 2 números e um operador");
        int num1;
        int num2;
        char operador;
        scanf("%d", num1);
        scanf("%d", num2);
        scanf("%s", operador);
        conta(num1, num2, operador);
    }else if(strcmp("agenda", comando)==0){
        char nome[100];
        char telefone[10];
        scanf("%s", nome);
        scanf("%s", telefone);
        cadastrar_agenda(nome, telefone);
    }else if(strcmp("exit", comando)==0){
        printf("Saindo \n");
        exit(0);
    }
}

return 0;
}

void conta(int a1, int a2,char o[1]){
    int resultado;
    if(strcmp("-", o)==0){
         resultado = a1 - a2;
         printf("%d", resultado);
    }else if(strcmp("+", o)==0){
        resultado = a1 + a2;
        printf("%d", resultado);
    }else if(strcmp("*", o)==0){
        resultado = a1 * a2;
        printf("%d", resultado);
    }else if(strcmp("/",o)==0){
        resultado = a1 / a2;
        printf("%d", resultado);
    }
}

void cadastrar_agenda(char nome[100], char telefone[10]){
    
    FILE *ponteiro_agenda;

    ponteiro_agenda = fopen("agenda.txt", "a");
    if(ponteiro_agenda == NULL){
        printf("ERRO!!!");
        exit(1);
    }
    fprintf(ponteiro_agenda, "Nome:%s Telefone:%s", nome, telefone);
    fclose(ponteiro_agenda);
    printf("Contato Salvo!");
}




   