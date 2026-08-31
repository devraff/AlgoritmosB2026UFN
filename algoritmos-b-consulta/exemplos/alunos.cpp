#include <iostream>
#include <string>
#include <iomanip>
#define TAM 30
using namespace std;

struct Aluno {
    int matricula;
    string nome;
    float nota1;
    float nota2;
};

int main() {
    Aluno alunos[TAM];
    int qtd = 0;
    int opcao;

    do {
        cout << "\n1 - Cadastrar\n2 - Listar\n3 - Mostrar medias\n0 - Sair\nOpcao: ";
        cin >> opcao;

        switch (opcao) {
            case 1:
                if (qtd < TAM) {
                    cout << "Matricula: "; cin >> alunos[qtd].matricula;
                    cout << "Nome: "; cin.ignore(); getline(cin, alunos[qtd].nome);
                    cout << "Nota 1: "; cin >> alunos[qtd].nota1;
                    cout << "Nota 2: "; cin >> alunos[qtd].nota2;
                    qtd++;
                }
                break;

            case 2:
                for (int i = 0; i < qtd; i++)
                    cout << alunos[i].matricula << " - " << alunos[i].nome << endl;
                break;

            case 3:
                for (int i = 0; i < qtd; i++) {
                    float media = (alunos[i].nota1 + alunos[i].nota2) / 2.0;
                    cout << fixed << setprecision(2) << alunos[i].nome << ": " << media << endl;
                }
                break;

            case 0:
                break;
        }
    } while (opcao != 0);

    return 0;
}
