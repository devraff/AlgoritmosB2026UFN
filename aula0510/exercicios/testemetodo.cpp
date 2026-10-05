// Método que receba um arquivo de texto e uma palavra e escreva quantas vezes a palavra ocorre no texto do arquivo.

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int contarOcorrencias(const string& nomeArquivo, const string& palavra) {
    ifstream arquivo(nomeArquivo);
    if (!arquivo.is_open()) {
        cerr << "Erro ao abrir o arquivo: " << nomeArquivo << endl;
        return -1;
    }

    int contador = 0;
    string linha;
    while (getline(arquivo, linha)) {
        size_t pos = linha.find(palavra);
        while (pos != string::npos) {
            contador++;
            pos = linha.find(palavra, pos + palavra.length());
        }
    }

    arquivo.close();
    return contador;
}

int main() {
    string nomeArquivo = "nomes.txt";
    string palavra;

    cout << "Digite a palavra a ser contada: ";
    cin >> palavra;

    int ocorrencias = contarOcorrencias(nomeArquivo, palavra);
    if (ocorrencias != -1) {
        cout << "A palavra '" << palavra << "' ocorre " << ocorrencias << " vezes no arquivo '" << nomeArquivo << "'." << endl;
    }

    return 0;
}
