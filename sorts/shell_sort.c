#include <stdio.h>
#include <math.h>

void print_shell(int i, int j, int d){
    printf("%d", i);
    for (int i = 0; i < d; i++) printf(" ");
    printf("%d", j);

    printf("\n");

    printf("|");
    for (int i = 0; i < d; i++) printf(" ");
    printf("|");

    printf("\n");

    for (int i = 0; i < d; i++) printf("-");
}

void shell(int lista[], int tam){
    int meio = ceil(tam / 2);

    for (int d = meio; d > 0; d--){
        for (int i = 0; i + d <= tam - 1; i++){
            if (lista[i] > lista[i + d]){
                int temp = lista[i];
                lista[i] = lista[i + d];
                lista[i + d] = temp;
            }
        }
    }
}

int main(){
    int lista[101] = {82, 49, 93, 39, 53, 48, 6, 12, 51, 24, 69, 13, 84, 62, 79, 41, 10, 100, 22, 68, 76, 37, 66, 78, 64, 2, 31, 99, 87, 63, 44, 8, 65, 92, 23, 47, 75, 9, 19, 4, 59, 55, 72, 56, 57, 17, 36, 96, 5, 14, 42, 90, 67, 61, 74, 40, 54, 1, 28, 80, 50, 34, 43, 35, 81, 20, 89, 32, 3, 98, 38, 70, 25, 88, 71, 95, 18, 58, 26, 85, 33, 94, 77, 27, 73, 11, 91, 86, 46, 29, 52, 45, 7, 60, 30, 15, 21, 16, 97, 83};

    shell(lista, 100);

    printf("[");
    for (int i = 0; i < 100; i++){
        i == 99 ? printf("%d", lista[i]) : printf("%d, ", lista[i]);
    }
    printf("]\n");

    return 0;
}