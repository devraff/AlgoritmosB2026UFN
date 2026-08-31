#include <iostream>
#include <string>
#define TAM 4
using namespace std;

struct Emprestimo {
    string descricao;
    string nome;
    string celular;
    string data;
};

int main() {
    Emprestimo itens[TAM];
    int qtd = 0;
    int opcao;

    do {
        cout << "\nM E N U\n";
        cout << "1 - Emprestar\n2 - Devolver\n3 - Listar emprestimos\n4 - Sair\nOpcao: ";
        cin >> opcao;

        switch (opcao) {
            case 1:
                if (qtd >= TAM) {
                    cout << "Limite atingido.\n";
                } else {
                    cin.ignore();
                    cout << "Item: "; getline(cin, itens[qtd].descricao);
                    cout << "Pessoa: "; getline(cin, itens[qtd].nome);
                    cout << "Celular: "; getline(cin, itens[qtd].celular);
                    cout << "Data: "; getline(cin, itens[qtd].data);
                    qtd++;
                }
                break;

            case 2: {
                if (qtd == 0) {
                    cout << "Nenhum item emprestado.\n";
                    break;
                }

                string descricao;
                bool encontrou = false;
                cin.ignore();
                cout << "Descricao do item devolvido: ";
                getline(cin, descricao);

                for (int i = 0; i < qtd; i++) {
                    if (itens[i].descricao == descricao) {
                        for (int j = i; j < qtd - 1; j++) itens[j] = itens[j + 1];
                        qtd--;
                        encontrou = true;
                        cout << "Devolucao registrada.\n";
                        break;
                    }
                }

                if (!encontrou) cout << "Item nao encontrado.\n";
                break;
            }

            case 3:
                if (qtd == 0) cout << "Nenhum item esta emprestado.\n";
                else {
                    for (int i = 0; i < qtd; i++) {
                        cout << "Item: " << itens[i].descricao << endl;
                        cout << "Pessoa: " << itens[i].nome << ". Celular: " << itens[i].celular << endl;
                        cout << "Data: " << itens[i].data << endl;
                        cout << "----------------------------\n";
                    }
                }
                break;

            case 4:
                cout << "Encerrando...\n";
                break;

            default:
                cout << "Opcao invalida.\n";
        }
    } while (opcao != 4);

    return 0;
}
