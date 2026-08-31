#include <iostream>
#include <string>
#define TAM 10
using namespace std;

struct Produto {
    int codigo;
    string nome;
};

int main() {
    Produto produtos[TAM];
    int qtd = 0;
    int opcao;

    do {
        cout << "\n1 - Cadastrar\n2 - Listar\n3 - Remover\n0 - Sair\nOpcao: ";
        cin >> opcao;

        switch (opcao) {
            case 1:
                if (qtd < TAM) {
                    cout << "Codigo: "; cin >> produtos[qtd].codigo;
                    cout << "Nome: "; cin.ignore(); getline(cin, produtos[qtd].nome);
                    qtd++;
                } else cout << "Cadastro cheio!\n";
                break;

            case 2:
                if (qtd == 0) cout << "Nenhum produto.\n";
                else for (int i = 0; i < qtd; i++)
                    cout << produtos[i].codigo << " - " << produtos[i].nome << endl;
                break;

            case 3: {
                int codigo;
                bool encontrou = false;
                cout << "Codigo para remover: ";
                cin >> codigo;

                for (int i = 0; i < qtd; i++) {
                    if (produtos[i].codigo == codigo) {
                        for (int j = i; j < qtd - 1; j++) {
                            produtos[j] = produtos[j + 1];
                        }
                        qtd--;
                        encontrou = true;
                        cout << "Registro removido!\n";
                        break;
                    }
                }

                if (!encontrou) cout << "Produto nao encontrado.\n";
                break;
            }

            case 0:
                break;

            default:
                cout << "Opcao invalida!\n";
        }
    } while (opcao != 0);

    return 0;
}
