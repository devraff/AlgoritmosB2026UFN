/* 6) Construa um programa (com módulo/método) que leia n nomes de pessoas DE UM ARQUIVO DE ORIGEM, armazena em um vetor de nomes e os exiba na tela. Porém, é necessário GRAVAR ESSES NOMES JUNTAMENTE COM A QUANTIDADE DE CARACTERES EM UM ARQUIVO DESTINO. */

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

void lerNomesDoArquivo(const string& nomeArquivo, vector<string>& nomes) {
    ifstream arquivo(nomeArquivo);
    if (!arquivo.is_open()) {
        cerr << "Erro ao abrir o arquivo!" << endl;
        return;
    }

    string linha;
    while (getline(arquivo, linha)) {
        nomes.push_back(linha);
    }

    arquivo.close();
}

void exibirNomes(const vector<string>& nomes) {
    for (const auto& nome : nomes) {
        cout << "Nome: " << nome << " | Tamanho: " << nome.size() << " caracteres" << endl;
    }
}

void gravarNomesComTamanho(const string& nomeArquivo, const vector<string>& nomes) {
    ofstream arquivo(nomeArquivo);
    if (!arquivo.is_open()) {
        cerr << "Erro ao abrir o arquivo!" << endl;
        return;
    }

    for (const auto& nome : nomes) {
        arquivo << nome << "; " << nome.size() << endl;
    }

    arquivo.close();
}

int main() {
    vector<string> nomes;
    lerNomesDoArquivo("nomes.txt", nomes);
    exibirNomes(nomes);
    gravarNomesComTamanho("nomes_destino.txt", nomes);
    return 0;
}
