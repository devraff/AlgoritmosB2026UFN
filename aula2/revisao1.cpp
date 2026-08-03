#include <iostream>

using namespace std;

int main () {
    int opcao;

    do {
        system("cls");
        cout << "MENU PRINCIPAL\n";
        cout << "1 - Popular vetor com numeros aleatorios\n";
        cout << "2 - Listar vetor populado\n";
        cout << "3 - Sair\n";
        cout << "Opcao: ";
        cin >> opcao;

    } while (opcao != 3);

    switch (opcao) {
        case 1:
            cout << "Popular vetor com numeros aleatorios\n";
            break;
        case 2:
            cout << "Listar vetor populado\n";
            break;
        case 3:
            cout << "Sair\n";
            break;
        default:
            cout << "Opcao invalida\n";
    }

    system("pause");

    return 0;
}