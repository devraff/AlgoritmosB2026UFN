#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct Pessoa {
    string nomeCompleto;
    string sobreNome;
};

string extrairSobrenome(const string& nomeCompleto) {
    size_t pos = nomeCompleto.find_last_of(' ');
    if (pos != string::npos) {
        return nomeCompleto.substr(pos + 1);
    }
    return ""; // Retorna uma string vazia se não houver sobrenome
}

int main() {
    int n;
    cout << "Digite o número de pessoas: ";
    cin >> n;
    cin.ignore(); // Limpar o buffer do teclado

    vector<Pessoa> pessoas(n);

    for (int i = 0; i < n; ++i) {
        cout << "Digite o nome completo da pessoa " << (i + 1) << ": ";
        getline(cin, pessoas[i].nomeCompleto);
        pessoas[i].sobreNome = extrairSobrenome(pessoas[i].nomeCompleto);
    }

    cout << "\nNomes completos e sobrenomes:\n";
    for (const auto& pessoa : pessoas) {
        cout << "Nome Completo: " << pessoa.nomeCompleto << ", Sobrenome: " << pessoa.sobreNome << endl;
    }

    return 0;
}