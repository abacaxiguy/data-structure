#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Elem {
    int info;
    struct Elem *prox;
} Elem;

Elem *Criar(int info){
    Elem *novo = malloc(sizeof(Elem));
    novo->info = info;
    novo->prox = NULL;
    return novo;
}

int Vazia(Elem *lista){
    return lista == NULL;
}

int Quantidade(Elem *lista){
    if (Vazia(lista)) return 0;
    return 1 + Quantidade(lista->prox);
}

Elem *InserirInicio(Elem *lista, int info){
    Elem *novo = Criar(info);
    novo->prox = lista;
    return novo;
}

Elem *InserirFinal(Elem *lista, int info){
    if (Vazia(lista)) return Criar(info);
    lista->prox = InserirFinal(lista->prox, info);
    return lista;
}

Elem *RemoverInicio(Elem *lista){
    if (Vazia(lista)) return NULL;
    Elem *temp = lista->prox;
    free(lista);
    return temp;
}

int RemoverFinal(Elem *lista){
    if (Vazia(lista)) return 0;
    if ((lista->prox)->prox == NULL) {
        free(lista->prox);
        lista->prox = NULL;
        return 1;
    }
    else RemoverFinal(lista->prox);
}

int Busca(Elem *lista, int info){
    if (Vazia(lista)) return 0;
    else if (lista->info == info) return 1;
    else return Busca(lista->prox, info);
}

void Imprimir(Elem *lista){
    if (Vazia(lista)) return;
    printf("%d ", lista->info);
    Imprimir(lista->prox);
}

int main(){
    Elem *lista = NULL;
    lista = InserirInicio(lista, 1);
    lista = InserirInicio(lista, 2);
    lista = InserirInicio(lista, 3);
    lista = InserirFinal(lista, 4);
    lista = InserirFinal(lista, 5);
    lista = InserirFinal(lista, 6);
    Imprimir(lista);
    printf("\n");
    Vazia(lista) ? printf("Lista vazia\n") : printf("Lista com elementos\n");
    Quantidade(lista) ? printf("Lista com %d elementos\n", Quantidade(lista)) : printf("Lista vazia\n");
    Busca(lista, 3) ? printf("Elemento 3 encontrado\n") : printf("Elemento 3 não encontrado\n");
    
    lista = RemoverInicio(lista);
    Imprimir(lista);
    printf("\n");
    RemoverFinal(lista) ? printf("Elemento removido\n") : printf("Lista vazia\n");
    Imprimir(lista);
    
    return 0;
}