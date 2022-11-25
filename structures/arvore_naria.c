#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int info;
    struct no *filho;
    struct no *irmao;
} no;

no *cria_no(int info) {
    no *novo = (no *) malloc(sizeof(no));
    novo->info = info;
    novo->filho = NULL;
    novo->irmao = NULL;
    return novo;
}

no *insere_filho(no *pai, no *filho) {
    if (pai->filho == NULL) {
        pai->filho = filho;
    } else {
        no *aux = pai->filho;
        while (aux->irmao != NULL) {
            aux = aux->irmao;
        }
        aux->irmao = filho;
    }
    return pai;
}

int busca(no *pai, int info){
    if (pai == NULL){
        return 0;
    }
    if (pai->info == info){
        return 1;
    }
    if (busca(pai->filho, info) == 1){
        return 1;
    }

    return busca(pai->irmao, info);
}

void imprimir_arvore(no *pai) {
    if (pai == NULL) {
        return;
    }
    printf("%d ", pai->info);
    imprimir_arvore(pai->filho);
    imprimir_arvore(pai->irmao);
}

no *copiar(no *arvore1, no *arvore2)
{
    if (arvore1 == NULL)
    {
        return arvore2;
    }

    no *novo = cria_no(arvore1->info);

    arvore2 = insere_filho(arvore2, novo);

    arvore2 = copiar(arvore1->irmao, arvore2);

    arvore2 = copiar(arvore1->filho, arvore2);

    return arvore2;
}

no *unir(no *arvore1, no *arvore2)
{
    if (arvore1 == NULL)
    {
        return arvore2;
    }

    if (busca(arvore2, arvore1->info) == 0)
    {
        no *novo = cria_no(arvore1->info);
        arvore2 = insere_filho(arvore2, novo);
    }

    arvore2 = unir(arvore1->irmao, arvore2);

    arvore2 = unir(arvore1->filho, arvore2);

    return arvore2;
}

no *uniao(no *arvore1, no *arvore2){
    no *arvore3 = cria_no(arvore1->info);

    arvore3 = copiar(arvore1->filho, arvore3);

    arvore3 = unir(arvore2, arvore3);

    return arvore3;
}


int main(){

    no *raiz = cria_no(1);
    no *filho1 = cria_no(2);
    no *filho2 = cria_no(3);
    no *filho3 = cria_no(4);

    insere_filho(raiz, filho1);
    insere_filho(raiz, filho2);
    insere_filho(raiz, filho3);

    insere_filho(filho1, cria_no(5));
    insere_filho(filho1, cria_no(6));
    insere_filho(filho2, cria_no(7));

    printf("Arvore 1:\n");
    imprimir_arvore(raiz);
    printf("\n");

    printf("\nBuscando na árvore 1 o número 4:");
    if (busca(raiz, 4) == 1){
        printf("\nAchou o número 4!\n\n");
    } else {
        printf("\nNao achou o número 4!\n\n");
    }

    no *raiz2 = cria_no(1);
    no *filho4 = cria_no(7);
    no *filho5 = cria_no(8);
    no *filho6 = cria_no(9);

    insere_filho(raiz2, filho4);
    insere_filho(raiz2, filho5);
    insere_filho(raiz2, filho6);

    printf("Arvore 2:\n");
    imprimir_arvore(raiz2);
    printf("\n");

    no *raiz3 = uniao(raiz, raiz2);

    printf("\nUnindo as duas árvores:\n");
    printf("\nArvore 3:\n");
    imprimir_arvore(raiz3);
    printf("\n");

    printf("\nChecando se nenhuma árvore foi alterada:\n");
    printf("\nArvore 1:\n");
    imprimir_arvore(raiz);
    printf("\n");

    printf("\nArvore 2:\n");
    imprimir_arvore(raiz2);
    printf("\n");

    return 0;
}