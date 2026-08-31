#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#define TAMANHO 10
using namespace std;

int main() {
    int opcao;
    int vetor[TAMANHO];
    int qtd = 0;
    srand(time(NULL));

    do {
        cout << "\n1 - Popular\n2 - Listar\n3 - Ordenar\n4 - Mediana\n0 - Sair\nOpcao: ";
        cin >> opcao;

        switch (opcao) {
            case 1:
                for (int i = 0; i < TAMANHO; i++) vetor[i] = rand() % 100;
                qtd = TAMANHO;
                break;

            case 2:
                if (qtd == 0) cout << "Vetor vazio!\n";
                else {
                    for (int i = 0; i < qtd; i++) cout << vetor[i] << " ";
                    cout << endl;
                }
                break;

            case 3:
                if (qtd == 0) {
                    cout << "Vetor vazio!\n";
                } else {
                    for (int i = 0; i < qtd - 1; i++) {
                        for (int j = 0; j < qtd - i - 1; j++) {
                            if (vetor[j] > vetor[j + 1]) {
                                int temp = vetor[j];
                                vetor[j] = vetor[j + 1];
                                vetor[j + 1] = temp;
                            }
                        }
                    }
                    cout << "Vetor ordenado!\n";
                }
                break;

            case 4:
                if (qtd == 0) {
                    cout << "Vetor vazio!\n";
                } else {
                    // Ordena antes de calcular a mediana
                    for (int i = 0; i < qtd - 1; i++) {
                        for (int j = 0; j < qtd - i - 1; j++) {
                            if (vetor[j] > vetor[j + 1]) {
                                int temp = vetor[j];
                                vetor[j] = vetor[j + 1];
                                vetor[j + 1] = temp;
                            }
                        }
                    }

                    float mediana;
                    if (qtd % 2 == 0)
                        mediana = (vetor[qtd / 2 - 1] + vetor[qtd / 2]) / 2.0;
                    else
                        mediana = vetor[qtd / 2];

                    cout << fixed << setprecision(2) << "Mediana: " << mediana << endl;
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
