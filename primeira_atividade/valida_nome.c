#include <stdio.h>
#include <string.h>
#include <ctype.h>

int eh_maiusculo(char letra)
{
    if (letra >= 'A' && letra <= 'Z') return 1;
    else return 0;
}

int so_letras(char palavra[])
{
    for (int i = 1; i < strlen(palavra); i++){
        if (palavra[i] >= 'a' && palavra[i] <= 'z') continue;
        else return 0;
    }

    return 1;
}

int verificar_nome(char nome[])
{
    if (strlen(nome) < 1) return 0;
    else if (!eh_maiusculo(nome[0])) return 0;
    else if (nome[0] == ' ') return 0;
    else if (!so_letras(nome)) return 0;
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