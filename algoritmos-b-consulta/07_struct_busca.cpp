#include <iostream>
#include <string>
#define TAM 10
using namespace std;

struct Pessoa {
    int codigo;
    string nome;
    int idade;
};

int main() {
    Pessoa pessoas[TAM];
    int qtd = 0;
    int opcao;

    do {
        cout << "\n1 - Cadastrar\n2 - Listar\n3 - Buscar por codigo\n0 - Sair\nOpcao: ";
        cin >> opcao;

        switch (opcao) {
            case 1:
                if (qtd < TAM) {
                    cout << "Codigo: "; cin >> pessoas[qtd].codigo;
                    cout << "Nome: "; cin.ignore(); getline(cin, pessoas[qtd].nome);
                    cout << "Idade: "; cin >> pessoas[qtd].idade;
                    qtd++;
                } else cout << "Cadastro cheio!\n";
                break;

            case 2:
                if (qtd == 0) cout << "Nenhum registro.\n";
                else {
                    for (int i = 0; i < qtd; i++)
                        cout << pessoas[i].codigo << " - " << pessoas[i].nome << " - " << pessoas[i].idade << endl;
                }
                break;

            case 3: {
                if (qtd == 0) {
                    cout << "Nenhum registro.\n";
                    break;
                }

                int codigo;
                bool encontrou = false;
                cout << "Codigo para buscar: ";
                cin >> codigo;

                for (int i = 0; i < qtd; i++) {
                    if (pessoas[i].codigo == codigo) {
                        cout << "Nome: " << pessoas[i].nome << "\nIdade: " << pessoas[i].idade << endl;
                        encontrou = true;
                        break;
                    }
                }

                if (!encontrou) cout << "Registro nao encontrado.\n";
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
