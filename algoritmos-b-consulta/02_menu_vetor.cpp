#include <iostream>
#include <cstdlib>
#include <ctime>
#define TAMANHO 10
using namespace std;

int main() {
    int opcao;
    int vetor[TAMANHO];
    int qtd_elementos = 0;

    srand(time(NULL));

    do {
        cout << "\nMENU PRINCIPAL\n";
        cout << "1 - Popular vetor\n";
        cout << "2 - Listar vetor\n";
        cout << "0 - Sair\n";
        cout << "Opcao: ";
        cin >> opcao;

        switch (opcao) {
            case 1:
                for (int i = 0; i < TAMANHO; i++) {
                    vetor[i] = rand() % 100;
                }
                qtd_elementos = TAMANHO;
                cout << "Vetor populado!\n";
                break;

            case 2:
                if (qtd_elementos == 0) {
                    cout << "Vetor vazio!\n";
                } else {
                    for (int i = 0; i < qtd_elementos; i++) {
                        cout << vetor[i] << " ";
                    }
                    cout << endl;
                }
                break;

            case 0:
                break;

            default:
                cout << "Opcao invalida!\n";
        }
    } while (opcao != 0);

    return 0;
}
