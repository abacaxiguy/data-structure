#include <stdio.h>
#include <string.h>

int so_numeros(char numero[])
{
    for (int i = 0; i < strlen(numero); i++){
        if (numero[i] < '0' || numero[i] > '9'){
            if (numero[i] != ',' && numero[i] != '-' && numero[i] != '+') return 0;
        }
    }

    return 1;
}

int tem_virgula(char numero[])
{
    for (int i = 0; i < strlen(numero); i++){
        if (numero[i] == ',') return 1;
    }

    return 0;
}

int formato_real(char numero[]){
    if (numero[strlen(numero) - 1] == ',' || numero[strlen(numero) - 1] == ',') return 0;

    int virgulas = 0;

    for (int i = 0; i < strlen(numero); i++){
        if (numero[i] == ',') virgulas++;
        if (virgulas > 1) return 0;
    }
    
    return 1;
}

void contar_unidade(char numero[] , char* unidade){
    char unidade_aux[100];
    char dezena_aux[100];
    char centena_aux[100];

    if (strlen(numero) == 1){
        if (numero[0] == '0') strcpy(unidade, "zero");
        else if (numero[0] == '1') strcpy(unidade, "um");
        else if (numero[0] == '2') strcpy(unidade, "dois");
        else if (numero[0] == '3') strcpy(unidade, "três");
        else if (numero[0] == '4') strcpy(unidade, "quatro");
        else if (numero[0] == '5') strcpy(unidade, "cinco");
        else if (numero[0] == '6') strcpy(unidade, "seis");
        else if (numero[0] == '7') strcpy(unidade, "sete");
        else if (numero[0] == '8') strcpy(unidade, "oito");
        else if (numero[0] == '9') strcpy(unidade, "nove");

        return;
    }

    else if (strlen(numero) == 2){
        if (numero[0] == '1'){
            if (numero[1] == '1') strcpy(dezena_aux, "onze");
            else if (numero[1] == '2') strcpy(dezena_aux, "doze");
            else if (numero[1] == '3') strcpy(dezena_aux, "treze");
            else if (numero[1] == '4') strcpy(dezena_aux, "quatorze");
            else if (numero[1] == '5') strcpy(dezena_aux, "quinze");
            else if (numero[1] == '6') strcpy(dezena_aux, "dezesseis");
            else if (numero[1] == '7') strcpy(dezena_aux, "dezessete");
            else if (numero[1] == '8') strcpy(dezena_aux, "dezoito");
            else if (numero[1] == '9') strcpy(dezena_aux, "dezenove");
        } else{
            if (numero[0] == '2') strcpy(dezena_aux, "vinte");
            else if (numero[0] == '3') strcpy(dezena_aux, "trinta");
            else if (numero[0] == '4') strcpy(dezena_aux, "quarenta");
            else if (numero[0] == '5') strcpy(dezena_aux, "cinquenta");
            else if (numero[0] == '6') strcpy(dezena_aux, "sessenta");
            else if (numero[0] == '7') strcpy(dezena_aux, "setenta");
            else if (numero[0] == '8') strcpy(dezena_aux, "oitenta");
            else if (numero[0] == '9') strcpy(dezena_aux, "noventa");

            strcat(dezena_aux, " e ");

            if (numero[1] == '0') strcat(dezena_aux, "zero");
            else if (numero[1] == '1') strcat(dezena_aux, "um");
            else if (numero[1] == '2') strcat(dezena_aux, "dois");
            else if (numero[1] == '3') strcat(dezena_aux, "três");
            else if (numero[1] == '4') strcat(dezena_aux, "quatro");
            else if (numero[1] == '5') strcat(dezena_aux, "cinco");
            else if (numero[1] == '6') strcat(dezena_aux, "seis");
            else if (numero[1] == '7') strcat(dezena_aux, "sete");
            else if (numero[1] == '8') strcat(dezena_aux, "oito");
            else if (numero[1] == '9') strcat(dezena_aux, "nove");
        }

        strcpy(unidade, dezena_aux);
        return;
    }
    else {
        if (numero[0] == '0' && numero[1] == '0') {
            strcpy(centena_aux, "zero");
            strcpy(unidade, centena_aux);
            return;
        }
        else if (numero[0] == '1') strcpy(centena_aux, "cento");
        else if (numero[0] == '2') strcpy(centena_aux, "duzentos");
        else if (numero[0] == '3') strcpy(centena_aux, "trezentos");
        else if (numero[0] == '4') strcpy(centena_aux, "quatrocentos");
        else if (numero[0] == '5') strcpy(centena_aux, "quinhentos");
        else if (numero[0] == '6') strcpy(centena_aux, "seiscentos");
        else if (numero[0] == '7') strcpy(centena_aux, "setecentos");
        else if (numero[0] == '8') strcpy(centena_aux, "oitocentos");
        else if (numero[0] == '9') strcpy(centena_aux, "novecentos");

        strcpy(unidade, centena_aux);
        strcat(unidade, " e ");
        
        if (numero[1] == '1'){
            if (numero[2] == '1') strcpy(dezena_aux, "onze");
            else if (numero[2] == '2') strcpy(dezena_aux, "doze");
            else if (numero[2] == '3') strcpy(dezena_aux, "treze");
            else if (numero[2] == '4') strcpy(dezena_aux, "quatorze");
            else if (numero[2] == '5') strcpy(dezena_aux, "quinze");
            else if (numero[2] == '6') strcpy(dezena_aux, "dezesseis");
            else if (numero[2] == '7') strcpy(dezena_aux, "dezessete");
            else if (numero[2] == '8') strcpy(dezena_aux, "dezoito");
            else if (numero[2] == '9') strcpy(dezena_aux, "dezenove");
        } else{
            if (numero[1] == '2') strcpy(dezena_aux, "vinte");
            else if (numero[1] == '3') strcpy(dezena_aux, "trinta");
            else if (numero[1] == '4') strcpy(dezena_aux, "quarenta");
            else if (numero[1] == '5') strcpy(dezena_aux, "cinquenta");
            else if (numero[1] == '6') strcpy(dezena_aux, "sessenta");
            else if (numero[1] == '7') strcpy(dezena_aux, "setenta");
            else if (numero[1] == '8') strcpy(dezena_aux, "oitenta");
            else if (numero[1] == '9') strcpy(dezena_aux, "noventa");

            strcat(dezena_aux, " e ");

            if (numero[2] == '0') strcat(dezena_aux, "zero");
            else if (numero[2] == '1') strcat(dezena_aux, "um");
            else if (numero[2] == '2') strcat(dezena_aux, "dois");
            else if (numero[2] == '3') strcat(dezena_aux, "três");
            else if (numero[2] == '4') strcat(dezena_aux, "quatro");
            else if (numero[2] == '5') strcat(dezena_aux, "cinco");
            else if (numero[2] == '6') strcat(dezena_aux, "seis");
            else if (numero[2] == '7') strcat(dezena_aux, "sete");
            else if (numero[2] == '8') strcat(dezena_aux, "oito");
            else if (numero[2] == '9') strcat(dezena_aux, "nove");
        }

        strcat(unidade, dezena_aux);
        return;
    }
}

void contar(char numero[]){
    char unidade[100];
    char milhar[100];
    char milhao[100];

    char unidade_aux[3];
    char milhar_aux[3];
    char milhao_aux[3];
    int i;
    int tam_numero = strlen(numero);

    i = tam_numero > 3 ? (tam_numero - 3) : 0;
    
    unidade_aux[0] = numero[i];
    unidade_aux[1] = tam_numero == 1 ? '\0' : numero[i+1];
    unidade_aux[2] = tam_numero == 2 ? '\0' : numero[i+2];
    contar_unidade(unidade_aux, unidade);

    char unidade_final[100];

    strcpy(unidade_final, unidade);

    if (tam_numero > 3) {
        tam_numero > 6 ? i = i + i - 3 : i;
        milhar_aux[0] = numero[i - (tam_numero - 3)];
        milhar_aux[1] = tam_numero == 4 ? '\0' : numero[(i - (tam_numero - 3) + 1)];
        milhar_aux[2] = tam_numero == 5 ? '\0' : numero[(i - (tam_numero - 3) + 2)];
        milhar_aux[3] = '\0';
        contar_unidade(milhar_aux, milhar);

        strcat(milhar, " mil ");
    }

    if (tam_numero > 6) {
        milhao_aux[0] = numero[i - i];
        milhao_aux[1] = tam_numero == 7 ? '\0' : numero[(i - i) + 1];
        milhao_aux[2] = tam_numero == 8 ? '\0' : numero[(i - i) + 2];
        milhao_aux[3] = '\0';
        contar_unidade(milhao_aux, milhao);

        milhao_aux[0] == '1' && tam_numero == 7 ? strcat(milhao, " milhão ") : strcat(milhao, " milhões ");
    }

    if (tam_numero > 6) printf("%s%s%s", milhao, milhar, unidade_final);
    else if (tam_numero > 3) printf("%s%s", milhar, unidade);
    else printf("%s", unidade);
    return;
}

int main(){
    char numero[10];
    scanf("%[^\n]", numero);

    if (!so_numeros(numero) || strlen(numero) > 9) {
        printf("Numero invalido\n");
        return 0;
    }

    if (numero[0] == '+' || numero[0] == '-') {
        char *temp = numero + 1;
        if (numero[0] == '-') printf("menos ");
        strcpy(numero, temp);
    }

    if (tem_virgula(numero)){
        if (!formato_real(numero)) {
            printf("Numero invalido\n");
            return 0;
        }

        char *numero_antes = strtok(numero, ",");
        char *numero_depois = strtok(NULL, ",");
        strcpy(numero, numero_antes);

        contar(numero);

        printf(" vírgula ");

        int zeros = 0;

        for (int x = 0; x < strlen(numero_depois); x++) {
            if (numero_depois[x] == '0') {
                printf("zero ");
                zeros++;
            }
            else {
                char *temp = numero_depois + zeros;
                strcpy(numero_depois, temp);
            }
        }
        
        strcpy(numero, numero_depois);
        contar(numero);
        printf("\n");

        return 0;
    }

    contar(numero);
    printf("\n");

    return 0;
}