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
        cout << "\n1 - Popular\n2 - Listar\n3 - Media\n4 - Maior e menor\n0 - Sair\nOpcao: ";
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
                    int soma = 0;
                    for (int i = 0; i < qtd; i++) soma += vetor[i];
                    float media = soma / static_cast<float>(qtd);
                    cout << fixed << setprecision(2) << "Media: " << media << endl;
                }
                break;

            case 4:
                if (qtd == 0) {
                    cout << "Vetor vazio!\n";
                } else {
                    int menor = vetor[0];
                    int maior = vetor[0];
                    for (int i = 1; i < qtd; i++) {
                        if (vetor[i] < menor) menor = vetor[i];
                        if (vetor[i] > maior) maior = vetor[i];
                    }
                    cout << "Menor: " << menor << "\nMaior: " << maior << endl;
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
