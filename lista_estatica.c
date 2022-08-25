#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char nome[31];
    int idade;
} Elem;

typedef struct {
    Elem *elementos;
    int quantidade, tamanho;
} ListaEstatica;

int Criar(ListaEstatica *lista, int tam){
    lista->elementos = calloc(tam, sizeof(Elem));

    if(lista->elementos == NULL) return 0;

    lista->tamanho = tam;
    lista->quantidade = 0;

    return 1;
}

int Vazia(ListaEstatica lista){
    return lista.quantidade == 0;
}

int Cheia (ListaEstatica lista){
    return lista.quantidade == lista.tamanho;
}

int Quantidade(ListaEstatica lista){
    return lista.quantidade;
}

int InserirInicio(ListaEstatica *lista, Elem novo){
    if (Cheia(*lista)) return 0;

    for (int i = lista->quantidade; i > 0; --i) lista->elementos[i] = lista->elementos[i-1];

    lista->elementos[0] = novo;
    lista->quantidade++;

    return 1;
}

int InserirFinal(ListaEstatica *lista, Elem novo){
    if (Cheia(*lista)) return 0;

    lista->elementos[lista->quantidade++] = novo;
    return 1;
}

void Imprimir(ListaEstatica *lista){
    if (Vazia(*lista)) return;

    for (int i = 0; i < lista->quantidade; ++i)
        printf("%s - %d\n", lista->elementos[i].nome, lista->elementos[i].idade);
}

int Pesquisar(ListaEstatica lista, char *nome){
    for (int i = 0; i < lista.quantidade; ++i){
        if (strcmp(lista.elementos[i].nome, nome) == 0) return i;
    }
    return -1;
}

int RemoverInicio(ListaEstatica *lista, Elem *elem){
    if (Vazia(*lista)) return 0;

    *elem = lista->elementos[0];
    --lista->quantidade;

    for (int i = 0; i < lista->quantidade; i++) lista->elementos[i] = lista->elementos[i+1];
    return 1;
}

int RemoverFim(ListaEstatica *lista, Elem *elem){
    if (Vazia(*lista)) return 0;

    *elem = lista->elementos[--lista->quantidade];

    return 1;
}

int Remover(ListaEstatica *lista, Elem *elem) {
    int pos = Pesquisar(*lista, elem->nome);
    if (pos < 0) return 0;

    *elem = lista->elementos[pos];

    for (int i = pos; i < lista->quantidade; ++i) 
        lista->elementos[i] = lista->elementos[i + 1];

    lista->quantidade--;
    return 1;
}

int RemoverTodas(ListaEstatica *lista, Elem *elem){
    int pos = Pesquisar(*lista, elem->nome);
    if (pos < 0) return 0;

    while (pos >= 0){
        *elem = lista->elementos[pos];

        for (int i = pos; i < lista->quantidade; ++i)
            lista->elementos[i] = lista->elementos[i + 1];

        lista->quantidade--;

        pos = Pesquisar(*lista, elem->nome);
    }

    return 1;
}

int ContarElementos(ListaEstatica lista, Elem *elem){
    int cont = 0;
    for (int i = 0; i < lista.quantidade; ++i){
        if (strcmp(lista.elementos[i].nome, elem->nome) == 0) cont++;
    }
    return cont;
}

int ConcatenaLista(ListaEstatica *lista, ListaEstatica *lista2){};

int InverteLista(ListaEstatica *lista){
    if (Vazia(*lista)) return 0;
    if (lista->quantidade == 1) return 1;

    for (int i = 0; i < lista->quantidade / 2; ++i){
        Elem aux = lista->elementos[i];
        lista->elementos[i] = lista->elementos[(lista->quantidade - i) - 1];
        lista->elementos[(lista->quantidade - i) - 1] = aux;
    }

    return 1;
}

int main(){
    ListaEstatica lista;
    Elem elem;
    Criar(&lista, 5);
    InserirInicio(&lista, (Elem){"Joao", 20});
    InserirInicio(&lista, (Elem){"Joao", 20});
    InserirFinal(&lista, (Elem){"Pedro", 30});
    InserirFinal(&lista, (Elem){"Joao", 20});
    InserirFinal(&lista, (Elem){"José", 40});
    Imprimir(&lista);
    printf("\n");
    InverteLista(&lista);
    Imprimir(&lista);
    printf("\n");
    elem = (Elem){"Joao", 20};
    RemoverTodas(&lista, &elem);
    Imprimir(&lista);
    printf("\n");

    return 0;
}