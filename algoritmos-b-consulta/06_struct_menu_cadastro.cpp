#include <iostream>
#include <string>
#define TAM 10
using namespace std;

struct Produto {
    int codigo;
    string nome;
    float preco;
};

int main() {
    Produto produtos[TAM];
    int qtd = 0;
    int opcao;

    do {
        cout << "\n1 - Cadastrar produto\n2 - Listar produtos\n0 - Sair\nOpcao: ";
        cin >> opcao;

        switch (opcao) {
            case 1:
                if (qtd >= TAM) {
                    cout << "Cadastro cheio!\n";
                } else {
                    cout << "Codigo: ";
                    cin >> produtos[qtd].codigo;
                    cout << "Nome: ";
                    cin.ignore();
                    getline(cin, produtos[qtd].nome);
                    cout << "Preco: ";
                    cin >> produtos[qtd].preco;
                    qtd++;
                    cout << "Produto cadastrado!\n";
                }
                break;

            case 2:
                if (qtd == 0) {
                    cout << "Nenhum produto cadastrado.\n";
                } else {
                    for (int i = 0; i < qtd; i++) {
                        cout << "\nProduto " << i + 1 << endl;
                        cout << "Codigo: " << produtos[i].codigo << endl;
                        cout << "Nome: " << produtos[i].nome << endl;
                        cout << "Preco: " << produtos[i].preco << endl;
                    }
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
