#include <iostream>
#include <string>
#include <iomanip>
#define TAM 20
using namespace std;

struct Produto {
    int codigo;
    string nome;
    float preco;
    int estoque;
};

int main() {
    Produto produtos[TAM];
    int qtd = 0;
    int opcao;

    do {
        cout << "\n===== MENU =====\n";
        cout << "1 - Cadastrar\n";
        cout << "2 - Listar\n";
        cout << "3 - Buscar\n";
        cout << "4 - Editar\n";
        cout << "5 - Remover\n";
        cout << "6 - Media dos precos\n";
        cout << "0 - Sair\n";
        cout << "Opcao: ";
        cin >> opcao;

        switch (opcao) {
            case 1:
                if (qtd >= TAM) {
                    cout << "Cadastro cheio!\n";
                } else {
                    cout << "Codigo: "; cin >> produtos[qtd].codigo;
                    cout << "Nome: "; cin.ignore(); getline(cin, produtos[qtd].nome);
                    cout << "Preco: "; cin >> produtos[qtd].preco;
                    cout << "Estoque: "; cin >> produtos[qtd].estoque;
                    qtd++;
                    cout << "Cadastrado!\n";
                }
                break;

            case 2:
                if (qtd == 0) {
                    cout << "Nenhum produto.\n";
                } else {
                    for (int i = 0; i < qtd; i++) {
                        cout << "\nCodigo: " << produtos[i].codigo << endl;
                        cout << "Nome: " << produtos[i].nome << endl;
                        cout << fixed << setprecision(2) << "Preco: " << produtos[i].preco << endl;
                        cout << "Estoque: " << produtos[i].estoque << endl;
                    }
                }
                break;

            case 3: {
                int codigo;
                bool encontrou = false;
                cout << "Codigo: "; cin >> codigo;
                for (int i = 0; i < qtd; i++) {
                    if (produtos[i].codigo == codigo) {
                        cout << produtos[i].nome << " | R$ " << fixed << setprecision(2)
                             << produtos[i].preco << " | estoque: " << produtos[i].estoque << endl;
                        encontrou = true;
                        break;
                    }
                }
                if (!encontrou) cout << "Nao encontrado.\n";
                break;
            }

            case 4: {
                int codigo;
                bool encontrou = false;
                cout << "Codigo: "; cin >> codigo;
                for (int i = 0; i < qtd; i++) {
                    if (produtos[i].codigo == codigo) {
                        cout << "Novo nome: "; cin.ignore(); getline(cin, produtos[i].nome);
                        cout << "Novo preco: "; cin >> produtos[i].preco;
                        cout << "Novo estoque: "; cin >> produtos[i].estoque;
                        encontrou = true;
                        cout << "Atualizado!\n";
                        break;
                    }
                }
                if (!encontrou) cout << "Nao encontrado.\n";
                break;
            }

            case 5: {
                int codigo;
                bool encontrou = false;
                cout << "Codigo: "; cin >> codigo;
                for (int i = 0; i < qtd; i++) {
                    if (produtos[i].codigo == codigo) {
                        for (int j = i; j < qtd - 1; j++) produtos[j] = produtos[j + 1];
                        qtd--;
                        encontrou = true;
                        cout << "Removido!\n";
                        break;
                    }
                }
                if (!encontrou) cout << "Nao encontrado.\n";
                break;
            }

            case 6:
                if (qtd == 0) {
                    cout << "Nenhum produto.\n";
                } else {
                    float soma = 0;
                    for (int i = 0; i < qtd; i++) soma += produtos[i].preco;
                    cout << fixed << setprecision(2) << "Media: " << soma / qtd << endl;
                }
                break;

            case 0:
                cout << "Encerrando...\n";
                break;

            default:
                cout << "Opcao invalida!\n";
        }
    } while (opcao != 0);

    return 0;
}
