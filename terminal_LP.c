#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void conta(int a1, int a2,char o[1]){
    int resultado;
    if(strcmp("-", o)==0){
         resultado = a1 - a2;
         printf("O Resultado é:%d \n", resultado);
    }else if(strcmp("+", o)==0){
        resultado = a1 + a2;
        printf("O Resultado é:%d \n", resultado);
    }else if(strcmp("*", o)==0){
        resultado = a1 * a2;
        printf("O Resultado é:%d \n", resultado);
    }else if(strcmp("/",o)==0){
        resultado = a1 / a2;
        printf("O Resultado é:%d \n", resultado);
    }
}

void cadastrar_agenda(char nome[100], char telefone[10]){
    
    FILE *ponteiro_agenda;

    ponteiro_agenda = fopen("agenda.txt", "a");
    if(ponteiro_agenda == NULL){
        printf("ERRO!!!");
        exit(1);
    }
    fprintf(ponteiro_agenda, "Nome:%s Telefone:%s\n", nome, telefone);
    fclose(ponteiro_agenda);
    printf("Contato Salvo!");
}

void listar_agenda(){
    char linha[100];
    FILE *ponteiro_agenda;
    ponteiro_agenda = fopen("agenda.txt", "r");
    if(ponteiro_agenda == NULL){
        printf("ERRO!!!");
        exit(1);
    }
    printf("Seus Contatos: \n");
    while(fgets(linha, sizeof(linha), ponteiro_agenda)!= NULL){
        printf("%s", linha);
    }

}
void editor_txt(char arquivo_txt[100]){
    FILE *ponteiro_texto;
    ponteiro_texto = fopen(arquivo_txt, "a");
    if(ponteiro_texto == NULL){
        printf("ERRO!!!");
        exit(1);
    }
    printf("Editor aberto no arquivo:%s\n", arquivo_txt);
    char texto[10000];
    scanf("%s", texto);
    fprintf(ponteiro_texto, "Nome:%s\n %s", arquivo_txt, texto);
    fcolse(ponteiro_texto);
    printf("Texto Salvo!");
}




int main(){
    char comando[100];
    while(1){
    printf("myterm>");
    scanf("%s", comando);
    printf("\n");
    printf("%s \n", comando);
    if(strcmp("calculadora", comando)==0){
        printf("Entre 2 números e um operador: \n");
        int num1;
        int num2;
        char operador[1];
        scanf("%d", &num1);
        scanf("%d", &num2);
        scanf("%s", operador);
        conta(num1, num2, operador);
    }else if(strcmp("agenda", comando)==0){
        char nome[100];
        char telefone[10];
        printf("Você deseja cadastrar um novo contato ou listar a agenda?: \n");
        printf("(cadastrar/listar)?: \n");
        char AgComando[100];
        scanf("%s", AgComando);
        if(strcmp("cadastrar", AgComando)==0){
        scanf("%s", nome);
        scanf("%s", telefone);
        cadastrar_agenda(nome, telefone);
    }else if(strcmp("listar", AgComando)==0){
        listar_agenda();
    }
    }else if(strcmp("sair", comando)==0){
        printf("Saindo \n");
        exit(0);
    }
}

return 0;
}
   