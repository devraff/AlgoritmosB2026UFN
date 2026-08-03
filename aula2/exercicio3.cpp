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
        cout << "3 - Exibir o menor e o maior dos elementos do vetor\n";
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
            cout << "Exibir o menor e o maior dos elementos do vetor\n";
            if (qtd_elementos > 0)
            {
                int menor = vetor[0];
                int maior = vetor[0];

                for (int i = 1; i < TAMANHO; i++)
                {
                    if (vetor[i] < menor)
                    {
                        menor = vetor[i];
                    }
                    if (vetor[i] > maior)
                    {
                        maior = vetor[i];
                    }
                }

                cout << "O menor elemento do vetor e: " << menor << endl;
                cout << "O maior elemento do vetor e: " << maior << endl;
            }
            else
            {
                cout << "Vetor vazio\n";
            }

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