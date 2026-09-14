#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

void exibirNomesDoArquivo(const string& nomeArquivo) {
    ifstream arquivo("nomes.txt");
    if (!arquivo.is_open()) {
        cerr << "Erro ao abrir o arquivo!" << endl;
        return;
    }

    string linha;
    while (getline(arquivo, linha)) {
        cout << "Nome Completo: " << linha << endl;
    }

    arquivo.close();
}

int main() {
    exibirNomesDoArquivo("nomes.txt");
    return 0;
}