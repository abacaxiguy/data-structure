// faça um programa que recebe um número no formato de string e informa o tipo do número fornecido(natural, inteiros ou real).Existe a possibilidade do número fornecidos não ser válido para nenhum desses tipos, caso em que uma mensagem de erro deve ser exibida para o usuário

#include <stdio.h>
#include <string.h>

int so_numeros(char numero[])
{
    for (int i = 0; i < strlen(numero); i++){
        if (numero[i] < '0' || numero[i] > '9'){
            if (numero[i] != ',' && numero[i] != '.' && numero[i] != '-' && numero[i] != '+') return 0;
        }
    }

    return 1;
}

int tem_virgula(char numero[])
{
    for (int i = 0; i < strlen(numero); i++){
        if (numero[i] == ',' || numero[i] == '.') return 1;
    }

    return 0;
}

int formato_real(char numero[]){
    if (numero[0] == '.' || numero[strlen(numero) - 1] == '.') return 0;
    else if (numero[0] == ',' || numero[strlen(numero) - 1] == ',') return 0;

    int virgulas = 0;

    for (int i = 0; i < strlen(numero); i++){
        if (numero[i] == ',' || numero[i] == '.') virgulas++;
        if (virgulas > 1) return 0;
    }
    
    return 1;
}

int main(){
    char numero[100];

    scanf("%s", numero);

    if (!so_numeros(numero)){
        printf("Numero invalido\n");
        return 0;
    }

    if ((numero[0] >= '0' && numero[0] <= '9') || numero[0] == '+') {
        if (tem_virgula(numero)){
            if (formato_real(numero)) printf("Real\n");
            else (printf("Numero invalido\n"));
        } 

        else printf("Natural\n");
        return 0;
    }

    else {
        if (numero[0] == '-' && numero[1] >= '0' && numero[1] <= '9' && !tem_virgula(numero)) printf("Inteiro\n");

        else if (numero[0] == '-' && numero[1] >= '0' && numero[1] <= '9'){
            if (tem_virgula(numero) && formato_real(numero)) printf("Real\n");
            else printf("Numero invalido\n");
        } 

        else printf("Numero invalido\n");
        return 0;
    }
}