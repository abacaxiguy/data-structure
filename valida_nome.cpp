#include <iostream>

using namespace std;

bool eh_minusculo(char letra){
    return letra >= 'a' && letra <= 'z';
}

bool tem_numero(string palavra){
    for(int i = 0; i < palavra.size(); i++){
        if(palavra[i] >= '0' && palavra[i] <= '9') return true;
    }
    return false;
}

bool verificar_nome(string nome){
    if (nome.length() < 1) return false;
    else if (eh_minusculo(nome[0])) return false;
    else if (nome[0] == ' ') return false;
    else if (tem_numero(nome)) return false;
    else return true;
}

int main() {
    string nome;

    cin >> nome;

    if (verificar_nome(nome)){
        cout << "Nome valido" << endl;
    } else {
        cout << "Nome invalido" << endl;
    }
    return 0;
}