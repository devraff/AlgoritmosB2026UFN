#include <iostream>
#include <string>
#define TAM 10
using namespace std;

struct Aluno {
    int matricula;
    string nome;
    float nota;
};

int main() {
    Aluno alunos[TAM];
    int qtd = 0;
    int opcao;

    do {
        cout << "\n1 - Cadastrar\n2 - Listar\n3 - Editar\n0 - Sair\nOpcao: ";
        cin >> opcao;

        switch (opcao) {
            case 1:
                if (qtd < TAM) {
                    cout << "Matricula: "; cin >> alunos[qtd].matricula;
                    cout << "Nome: "; cin.ignore(); getline(cin, alunos[qtd].nome);
                    cout << "Nota: "; cin >> alunos[qtd].nota;
                    qtd++;
                } else cout << "Cadastro cheio!\n";
                break;

            case 2:
                if (qtd == 0) cout << "Nenhum aluno.\n";
                else for (int i = 0; i < qtd; i++)
                    cout << alunos[i].matricula << " - " << alunos[i].nome << " - " << alunos[i].nota << endl;
                break;

            case 3: {
                int matricula;
                bool encontrou = false;
                cout << "Matricula para editar: ";
                cin >> matricula;

                for (int i = 0; i < qtd; i++) {
                    if (alunos[i].matricula == matricula) {
                        cout << "Novo nome: ";
                        cin.ignore();
                        getline(cin, alunos[i].nome);
                        cout << "Nova nota: ";
                        cin >> alunos[i].nota;
                        encontrou = true;
                        cout << "Registro atualizado!\n";
                        break;
                    }
                }

                if (!encontrou) cout << "Aluno nao encontrado.\n";
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
