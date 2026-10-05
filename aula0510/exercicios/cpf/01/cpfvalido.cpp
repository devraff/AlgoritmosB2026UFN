#include <iostream>
#include <fstream>
#include <string>

using namespace std;

bool validarCPF(const string& cpf) {
    if (cpf.length() != 11) {
        return false;
    }

    for (char c : cpf) {
        if (!isdigit(c)) {
            return false;
        }
    }

    return true;
}

int main() {
    string cpf;

    cout << "Digite o CPF (somente números): ";
    cin >> cpf;

    if (validarCPF(cpf)) {
        cout << "CPF válido!" << endl;
    } else {
        cout << "CPF inválido!" << endl;
    }

    return 0;
}