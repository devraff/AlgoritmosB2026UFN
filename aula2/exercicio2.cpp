#include <iostream>
#include <iomanip>
#include <time.h>

#define TAMANHO 10

using namespace std;

int main()
{
    int opcao;
    int vetor[TAMANHO];
    int qtd_elementos = 0;

    srand(time(NULL)); /* Comando Semeador */

    do
    {
        system("cls");
        cout << "MENU PRINCIPAL\n";
        cout << "1 - Popular vetor com numeros aleatorios\n";
        cout << "2 - Listar vetor populado\n";
        cout << "3 - Exibir mediana dos elementos do vetor\n";
        cout << "4 - Sair\n";
        cout << "Opcao: ";
        cin >> opcao;

        switch (opcao)
        {
        case 1:
            cout << "Popular vetor com numeros aleatorios\n";
            for (int i = 0; i < TAMANHO; i++)
            {
                vetor[i] = rand() % 100; /* Gera numeros aleatorios de 0 a 99 */
                qtd_elementos++;
            }
            break;
        case 2:
            cout << "Listar vetor populado\n";

            if (qtd_elementos > 0)
            {
                for (int i = 0; i < TAMANHO; i++)
                {
                    cout << vetor[i] << " ";
                }
                cout << endl;
            }
            else
            {
                cout << "Vetor vazio\n";
            }
            break;

        case 3:
            cout << "Exibir a mediana dos elementos do vetor\n";
             if (qtd_elementos > 0) {
                for (int i = 0; i < TAMANHO - 1; i++) {
                    for (int j = 0; j < TAMANHO - i - 1; j++) {
                        if (vetor[j] > vetor[j + 1]) {
                            int temp = vetor[j];
                            vetor[j] = vetor[j + 1];
                            vetor[j + 1] = temp;
                        }
                    }
                }
                float mediana;
                if (TAMANHO % 2 == 0) {
                    mediana = (vetor[TAMANHO / 2 - 1] + vetor [TAMANHO / 2]) / 2.0;
                } else {
                    mediana = vetor[TAMANHO / 2];
                }
                cout << "A mediana dos elementos do vetor e: " << ::fixed << setprecision(2) << mediana << endl;
            } else {
                cout << "Vetor vazio\n";
            }
            break;

        case 4:
            cout << "Sair\n";
            break;
        default:
            cout << "Opcao invalida\n";
            break;
        }

        system("pause");

    } while (opcao != 4);

    return 0;
}