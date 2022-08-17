#include <stdio.h>
#include <string.h>
#include <ctype.h>

int eh_minusculo(char letra)
{
    if (letra >= 'a' && letra <= 'z') return 1;
    else return 0;
}

int tem_numero(char palavra[])
{
    for (int i = 0; i < strlen(palavra); i++){
        if (palavra[i] >= '0' && palavra[i] <= '9') return 1;
    }

    return 0;
}

int verificar_nome(char nome[])
{
    if (strlen(nome) < 1) return 0;
    else if (eh_minusculo(nome[0])) return 0;
    else if (nome[0] == ' ') return 0;
    else if (tem_numero(nome)) return 0;
    else return 1;
}

int main()
{
    char nome[100];
    scanf("%s", nome);
    if (verificar_nome(nome)) printf("Nome valido\n");
    else printf("Nome invalido\n");
    return 0;
}