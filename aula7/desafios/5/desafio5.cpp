#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

struct Pessoa {
    string nomeCompleto;
    string sobreNome;
};

void extrairSobrenome(const string& nomeCompleto, string& sobreNome) {
    size_t pos = nomeCompleto.find_last_of(' ');
    if (pos != string::npos) {
        sobreNome = nomeCompleto.substr(pos + 1);
    } else {
        sobreNome = ""; // Retorna uma string vazia se não houver sobrenome
    }
}

int main() {
    vector<Pessoa> vetorPessoas;

    // Abrir o arquivo para leitura
    ifstream arquivoOrigem("nomes.txt");
    if (!arquivoOrigem.is_open()) {
        cerr << "Erro ao abrir o arquivo de origem!" << endl;
        return 1;
    }

    string linha;
    while (getline(arquivoOrigem, linha)) {
        Pessoa p;
        p.nomeCompleto = linha;
        extrairSobrenome(p.nomeCompleto, p.sobreNome);
        vetorPessoas.push_back(p);
    }

    arquivoOrigem.close();

    // Abrir o arquivo para escrita
    ofstream arquivoDestino("nomes_destino.txt");
    if (!arquivoDestino.is_open()) {
        cerr << "Erro ao abrir o arquivo de destino!" << endl;
        return 1;
    }

    for (const auto& pessoa : vetorPessoas) {
        arquivoDestino << pessoa.nomeCompleto << "; " << pessoa.sobreNome << endl;
    }

    arquivoDestino.close();

    cout << "Dados salvos com sucesso no arquivo de destino!" << endl;

    return 0;
}