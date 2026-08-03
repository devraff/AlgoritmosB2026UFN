#include <iostream>
#include <time.h>

#define TAMANHO 10

using namespace std;

int main () {
    int opcao;
    int vetor[tamanho];
    int qtd_elementos = 0;

    srand(time(NULL)); /* Comando Semeador */

    do {
        system("cls");
        cout << "MENU PRINCIPAL\n";
        cout << "1 - Popular vetor com numeros aleatorios\n";
        cout << "2 - Listar vetor populado\n";
        cout << "3 - Sair\n";
        cout << "Opcao: ";
        cin >> opcao;

    

    switch (opcao) {
        case 1:
            cout << "Popular vetor com numeros aleatorios\n";
            for (int i = 0; i < TAMANHO; i++) {
                vetor[i] = rand() % 100; /* Gera numeros aleatorios de 0 a 99 */
                qtd_elementos++;
            }
            break;
        case 2:
            cout << "Listar vetor populado\n";

            if (qtd_elementos > 0) {
            for (int i = 0; i < TAMANHO; i++) {
                cout << vetor[i] << " ";
            }
            cout << endl;
        } else {
            cout << "Vetor vazio\n";
        }
            break;
        case 3:
            cout << "Sair\n";
            break;
        default:
            cout << "Opcao invalida\n";
             system("pause");
    }

    } while (opcao != 3);


    return 1;
}