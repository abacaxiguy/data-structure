#include <stdio.h>
#include <stdlib.h>

#define SEM_TOPO -1

typedef struct no{
    int num;
    struct no *abaixo;
} No;

int Vazia(No *pilha) {
    return pilha == NULL;
}

int Quantidade(No *pilha){
    if (Vazia(pilha)) return 0;
    return 1 + Quantidade(pilha->abaixo);
}

int Topo(No *pilha){
    return pilha == NULL ? SEM_TOPO : pilha->num;
}

No *Cria(int num){
    No *novoNo = (No *)malloc(sizeof(No));

    novoNo->num = num;
    novoNo->abaixo = NULL;
    return novoNo;
}

No *Inserir(No *pilha, int num)
{
    No *novoNo = (No *)malloc(sizeof(No));

    novoNo->num = num;
    novoNo->abaixo = pilha;

    return novoNo;
}

void ImprimirNumeros(No *pilha){
    if (pilha->abaixo == NULL) {
        printf("| %d |\n‾‾‾‾‾\nFLOOR\n", pilha->num);
        return;
    }
    printf("| %d |\n", pilha->num);

    return ImprimirNumeros(pilha->abaixo);
}

void Imprimir(No *pilha){
    if (Vazia(pilha)) {
        printf(" TOP\n_____\n");
        printf("| - |\n‾‾‾‾‾\nFLOOR\n");
        printf("\n\n");
        return;
    }

    printf(" TOP\n_____\n");
    ImprimirNumeros(pilha);
    printf("\n\n");
}

No *Remover(No *pilha){
    if (Vazia(pilha)) return NULL;
    
    No *novoNo = (No *)malloc(sizeof(No));
    novoNo = pilha->abaixo;

    free(pilha);

    return novoNo;
}

int Busca(No *pilha, int num){
    if (Vazia(pilha)) return 0;

    if (pilha-> num == num) return 1;

    return Busca(pilha->abaixo, num);
}

void Ordena(No *pilha, char ordem){
    if (Quantidade(pilha) <= 1) return;

    int i = Quantidade(pilha);
    No *novoNo = pilha;
    
    for (i; i > 0; i--) {
        novoNo = pilha;

        while (novoNo->abaixo != NULL) {
            if (ordem == 'c') {
                if (novoNo->num > novoNo->abaixo->num){
                    int temp = novoNo->num;
                    novoNo->num = novoNo->abaixo->num;
                    novoNo->abaixo->num = temp;
                }
            }
            if (ordem == 'd'){
                if (novoNo->num < novoNo->abaixo->num){
                    int temp = novoNo->num;
                    novoNo->num = novoNo->abaixo->num;
                    novoNo->abaixo->num = temp;
                }  
            }

            novoNo = novoNo->abaixo;
        }
    }

    return;
}

No *Inverter(No *pilha){
    if (Quantidade(pilha) <= 1) return pilha;

    No *novoNo = NULL;

    while (pilha->abaixo != NULL){
        novoNo = Inserir(novoNo, pilha->num);
        No *temp = pilha->abaixo;
        free(pilha);
        pilha = temp;
    }

    novoNo = Inserir(novoNo, pilha->num);
    free(pilha);

    return novoNo;
}

int main() {

    No *pilha = Cria(0);

    printf("✔✔✔✔\n\n");

    pilha = Inserir(pilha, 3);
    pilha = Inserir(pilha, 1);
    pilha = Inserir(pilha, 6);
    pilha = Inserir(pilha, 2);
    pilha = Inserir(pilha, 8);

    Imprimir(pilha);

    pilha = Remover(pilha);
    printf("Removendo o topo da pilha...\n\n");
    
    Imprimir(pilha);

    pilha = Remover(pilha);
    printf("Removendo o topo da pilha...\n\n");

    Imprimir(pilha);

    Busca(pilha, 3) ? printf("3 foi encontrado\n") : printf("3 não foi encontrado\n");

    printf("%d elementos na pilha\n", Quantidade(pilha));

    Vazia(pilha) ? printf("A pilha está vazia\n") : printf("A pilha não está vazia\n");

    Topo(pilha) == SEM_TOPO ? printf("A pilha não tem topo.\n\n") : printf("%d está no topo da pilha\n\n", Topo(pilha));

    Ordena(pilha, 'c'); // c = crescente | d = decrescente
    printf("Ordenando na ordem CRESCENTE...\n\n");

    Imprimir(pilha);

    Ordena(pilha, 'd'); // c = crescente | d = decrescente
    printf("Ordenando na ordem DECRESCENTE...\n\n");

    Imprimir(pilha);

    pilha = Inverter(pilha);
    printf("Invertendo a pilha...\n\n");

    Imprimir(pilha);

    printf("Tentando remover mais do que a pilha tem...\n\n");

    pilha = Remover(pilha);
    pilha = Remover(pilha);
    pilha = Remover(pilha);
    pilha = Remover(pilha);
    pilha = Remover(pilha);
    pilha = Remover(pilha);
    pilha = Remover(pilha);
    pilha = Remover(pilha);
    pilha = Remover(pilha);
    pilha = Remover(pilha);

    Imprimir(pilha);

    Busca(pilha, 3) ? printf("3 foi encontrado\n") : printf("3 não foi encontrado\n");
    printf("%d elementos na pilha\n", Quantidade(pilha));
    Vazia(pilha) ? printf("A pilha está vazia\n") : printf("A pilha não está vazia\n");
    Topo(pilha) == SEM_TOPO ? printf("A pilha não tem topo.\n") : printf("%d está no topo da pilha\n", Topo(pilha));

    return 0;
}