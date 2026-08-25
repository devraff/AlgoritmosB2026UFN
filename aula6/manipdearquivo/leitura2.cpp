#include <iostream>
#include <fstream> // Biblioteca para manipulação de arquivos
#include <string>
#include <vector>

using namespace std;

typedef struct {
    string mes;
    float valor;
} Inflacao;

int main() {
    vector<Inflacao> vetorInflacao;
    Inflacao tmp;

    // Abrir o arquivo para leitura
    ifstream arquivo("inflacao.csv");

    // Verificar se o arquivo foi aberto corretamente
    if (!arquivo.is_open()) {
        cout << "Erro ao abrir o arquivo!" << endl;
        return 1;
    }

    string linha;

    // Ler cada linha do arquivo e armazenar no vetor
    while (getline(arquivo, linha)) {
        // fazer find para encontrar a vírgula e separar o mês do valor
        size_t pos = linha.find(",");

        if (pos != string::npos) {
            tmp.mes = linha.substr(0, pos);
            tmp.valor = stof(linha.substr(pos + 1));
            vetorInflacao.push_back(tmp);
        }
    }

    // Fechar o arquivo
    arquivo.close();

    // Exibe o vetor de nomes
    for  (int i = 0; i < vetorInflacao.size(); i++) {
        cout << "Mes: " << vetorInflacao[i].mes << " - Valor: " << vetorInflacao[i].valor << endl;
    }

    cout << "Total de registros lidos: " << vetorInflacao.size() << endl;

    return 0;
}