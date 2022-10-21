#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int info;
    struct no *esq;
    struct no *dir;

} no;

no *Criar() {
    return NULL;
}

no *Remover (no *raiz, int info)
{
    no *aux1, *aux2;

    if (raiz == NULL) return NULL;

    if (raiz->info > info) {
        raiz->esq = Remover(raiz->esq, info);
    }
    else if (raiz->info < info) {
        raiz->dir = Remover(raiz->dir, info);
    }

    else {
        if (raiz->esq == NULL && raiz->dir == NULL) {
            free(raiz);
            raiz = NULL;
        }
        else if (raiz->dir == NULL) {
            aux1 = raiz;
            raiz = raiz->esq;
            free(aux1);
        }
        else if (raiz->esq == NULL) {
            aux1 = raiz;
            raiz = raiz->dir;
            free(aux1);
        }

        else {
            aux2 = raiz->esq;
            while (raiz->dir != NULL)
            {
                raiz = raiz->dir;
            }
            raiz->info = aux2->info;

            aux2->info = info;
            raiz->esq = Remover(raiz->esq, info);
        }
    }

    return raiz;
}

int Buscar(no *raiz, int info)
{
    if (raiz == NULL) return 0;

    else{
        if (raiz->info == info) {
            return 1;
        }
        else if (raiz->info > info) {
            Buscar(raiz->esq, info);
        }
        else if (raiz->info < info) {
            Buscar(raiz->dir, info);
        }
    }
}

void Imprimir(no *raiz, int nivel) {
    if (raiz == NULL) return;
    
    else {
        nivel += 7;

        Imprimir(raiz->esq, nivel);
        printf("\n");

        for (int i = 7; i < nivel; i++) printf(" ");

        printf("%d\n", raiz->info);

        Imprimir(raiz->dir, nivel);
    }
}

no *Inserir(no *raiz, int info)
{
    if (raiz == NULL) {
        raiz = (no*) malloc(sizeof(no));
        raiz->info = info;
        raiz->esq = NULL;
        raiz->dir = NULL;
    }

    else {
        if (raiz->info > info) { // Se aceita duplicações, trocar para >=
            raiz->esq = Inserir(raiz->esq, info);
        }
        else if (raiz->info < info) {
            raiz->dir = Inserir(raiz->dir, info);
        }
    }

    return raiz;
}

no *Uniao(no *node1, no *node2)
{
    if (node2 != NULL)
    {
        node1 = Inserir(node1, node2->info);
        Uniao(node1, node2->esq);
        Uniao(node1, node2->dir);
    }

    return node1;
}

no *Interseccao(no *node1, no *node2)
{
    no *node3 = Criar();

    if (Buscar(node1, node2->info))
    {
        node3 = Inserir(node3, node2->info);
    }

    while (node2->esq != NULL && node2->dir != NULL)
    {
        if (Buscar(node1, node2->esq->info))
        {
            node3 = Inserir(node3, node2->esq->info);
        }

        if (Buscar(node1, node2->dir->info))
        {
            node3 = Inserir(node3, node2->dir->info);
        }

        node2->esq = node2->esq->esq;
        node2->dir = node2->dir->dir;
    }

    return node3;
}

no *Diferenca(no *node1, no *node2){
    no *node3 = Criar();

    while (node2->esq != NULL && node2->dir != NULL)
    {
        if (!Buscar(node1, node2->esq->info))
        {
            node3 = Inserir(node3, node2->esq->info);
        }

        if (!Buscar(node1, node2->dir->info))
        {
            node3 = Inserir(node3, node2->dir->info);
        }

        node2->esq = node2->esq->esq;
        node2->dir = node2->dir->dir;
    }

    return node3;
}

int main()
{
    no *raiz;
    no *raiz2;
    no *raiz3;
    no *raiz4;

    raiz = Criar();
    raiz2 = Criar();

    raiz = Inserir(raiz, 5);
    raiz = Inserir(raiz, 11);
    raiz = Inserir(raiz, 7);
    raiz = Inserir(raiz, 1);
    raiz = Inserir(raiz, 3);
    raiz = Inserir(raiz, 13);
    raiz = Inserir(raiz, 1);

    raiz2 = Inserir(raiz2, 2);
    raiz2 = Inserir(raiz2, 5);
    raiz2 = Inserir(raiz2, 4);
    raiz2 = Inserir(raiz2, 1);
    raiz2 = Inserir(raiz2, 0);
    raiz2 = Inserir(raiz2, 7);

    printf("Arvore 1: \n");
    Imprimir(raiz, 0);
    printf("\n\n");
    printf("Arvore 2: \n");
    Imprimir(raiz2, 0);

    no *raizUniao;
    raizUniao = Criar();
    no *node1Copy = raiz;
    raizUniao = Uniao(node1Copy, raiz2);

    printf("\n\n");
    printf("Arvore Uniao: \n");
    Imprimir(raizUniao, 0);

    raiz3 = Criar();
    raiz4 = Criar();

    raiz3 = Inserir(raiz3, 2);
    raiz3 = Inserir(raiz3, 1);
    raiz3 = Inserir(raiz3, 3);
    raiz3 = Inserir(raiz3, 4);
    raiz3 = Inserir(raiz3, 13);
    raiz3 = Inserir(raiz3, 19);

    raiz4 = Inserir(raiz4, 6);
    raiz4 = Inserir(raiz4, 1);
    raiz4 = Inserir(raiz4, 3);
    raiz4 = Inserir(raiz4, 20);
    raiz4 = Inserir(raiz4, 13);
    raiz4 = Inserir(raiz4, 29);

    printf("\n\n");
    printf("Arvore 3: \n");
    Imprimir(raiz3, 0);
    printf("\n\n");
    printf("Arvore 4: \n");
    Imprimir(raiz4, 0);

    no *raizInterseccao = Interseccao(raiz4, raiz3);

    printf("\n\n");
    printf("Arvore Intersecção: \n");
    Imprimir(raizInterseccao, 0);
}