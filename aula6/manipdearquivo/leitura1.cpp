#include <iostream>
#include <fstream> // Biblioteca para manipulação de arquivos
#include <string>
#include <vector>

using namespace std;

int main() {
    vector<string> vetorNomes;

    // Abrir o arquivo para leitura
    ifstream arquivo("exemplo.txt");

    // Verificar se o arquivo foi aberto corretamente
    if (!arquivo.is_open()) {
        cout << "Erro ao abrir o arquivo!" << endl;
        return 1;
    }

    string linha;

    // Ler cada linha do arquivo e armazenar no vetor
    while (getline(arquivo, linha)) {
        vetorNomes.push_back(linha);
    }

    // Fechar o arquivo
    arquivo.close();

    // Exibe o vetor de nomes
    for(int i = 0; i < vetorNomes.size(); i++) {
        cout << vetorNomes[i] << endl;
    }

    return 0;
}