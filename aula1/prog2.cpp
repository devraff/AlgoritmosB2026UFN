#include <iostream>
#include <string>

using namespace std;

int main() {
    string nome;
    cout << "Digite seu nome completo: ";
    getline(cin, nome);

    cout << "Vc digitou: " << nome << "\n";
    cout << "Esta frase tem: " << nome.length() << " caracteres.\n";
}