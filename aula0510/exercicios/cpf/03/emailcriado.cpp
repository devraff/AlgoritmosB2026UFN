#include <iostream>
#include <fstream>
#include <string>

using namespace std;

string criarEmail(const string& nomeCompleto) {
    size_t pos = nomeCompleto.find(' ');
    if (pos == string::npos) {
        return ""; 
    }

    string primeiroNome = nomeCompleto.substr(0, pos);
    string ultimoNome = nomeCompleto.substr(nomeCompleto.find_last_of(' ') + 1);

    for (char& c : primeiroNome) {
        c = tolower(c);
    }
    for (char& c : ultimoNome) {
        c = tolower(c);
    }

    return primeiroNome + "." + ultimoNome + "@ufn.edu.br";
}

int main() {
    string nomeCompleto;

    cout << "Digite o nome completo: ";
    getline(cin, nomeCompleto);

    string email = criarEmail(nomeCompleto);
    if (!email.empty()) {
        cout << "Email criado: " << email << endl;
    } else {
        cout << "Nome inválido!" << endl;
    }

    return 0;
}