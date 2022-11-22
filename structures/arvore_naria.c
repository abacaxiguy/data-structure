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

int main(){

    no *raiz = cria_no(1);
    no *filho1 = cria_no(2);
    no *filho2 = cria_no(3);
    no *filho3 = cria_no(4);

    insere_filho(raiz, filho1);
    insere_filho(raiz, filho2);
    insere_filho(raiz, filho3);

    printf("\n");
    imprimir_arvore(raiz);
    printf("\n");

    if (busca(raiz, 4) == 1){
        printf("Achou");
    } else {
        printf("Nao achou");
    }


    return 0;
}