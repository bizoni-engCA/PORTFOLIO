#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){
    FILE *ponteiro_texto;
    char arquivo_txt[100];
    scanf("%s", arquivo_txt[100]);
    ponteiro_texto = fopen(arquivo_txt, "a");
    if(ponteiro_texto == NULL){
        printf("ERRO!!!");
        exit(1);
    }
    printf("Editor aberto no arquivo:%s\n", arquivo_txt);
    char texto[100000];
    scanf("%s", texto);
    fprintf(ponteiro_texto, "Nome:%s\n %s", arquivo_txt, texto);
    fclose(ponteiro_texto);
    printf("Texto Salvo!");
}