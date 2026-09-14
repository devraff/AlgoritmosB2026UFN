//* 1) Construa um programa (com módulo/método) que leia n nomes completos de pessoas e os exiba na tela;

#include <iostream>
#include <string>

using namespace std;

int main() {
    int n;
    cout << "Digite o número de pessoas: ";
    cin >> n;
    cin.ignore(); // Limpar o buffer do teclado

    for (int i = 0; i < n; ++i) {
    string nome;
    cout << "Digite o nome completo da pessoa " << (i + 1) << ": ";
    getline(cin, nome);
    cout << "Nome Completo: " << nome << endl;
    }

    return 0;
}