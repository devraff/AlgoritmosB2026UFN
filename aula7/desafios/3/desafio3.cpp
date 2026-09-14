#include <iostream>
#include <vector>
#include <string>

using namespace std;

void exibirNomesComTamanhos(const vector<string>& nomes) {
    for (const auto& nome : nomes) {
        cout << "Nome: " << nome << ", Tamanho: " << nome.length() << " caracteres" << endl;
    }
}

int main() {
    int n;
    cout << "Digite o número de pessoas: ";
    cin >> n;
    cin.ignore(); // Limpar o buffer do teclado

    vector<string> nomes(n);

    for (int i = 0; i < n; ++i) {
        cout << "Digite o nome da pessoa " << (i + 1) << ": ";
        getline(cin, nomes[i]);
    }

    exibirNomesComTamanhos(nomes);

    return 0;
}
