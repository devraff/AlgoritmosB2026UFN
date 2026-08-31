#include <iostream>
using namespace std;

int main() {
    int opcao;

    do {
        cout << "\nMENU PRINCIPAL\n";
        cout << "1 - Opcao 1\n";
        cout << "2 - Opcao 2\n";
        cout << "3 - Opcao 3\n";
        cout << "0 - Sair\n";
        cout << "Opcao: ";
        cin >> opcao;

        switch (opcao) {
            case 1:
                cout << "Executando opcao 1\n";
                break;
            case 2:
                cout << "Executando opcao 2\n";
                break;
            case 3:
                cout << "Executando opcao 3\n";
                break;
            case 0:
                cout << "Saindo...\n";
                break;
            default:
                cout << "Opcao invalida!\n";
        }
    } while (opcao != 0);

    return 0;
}
