#include <iostream>
#include <string>
#include <vector>

using namespace std;

typedef struct {
    char nome[50];
    int matricula;
    float nota;
} Aluno;

int main() {
    int opcao;
    Aluno tmp;
    vector<Aluno> vetorAlunos;

    // 1. Loop de Cadastro
    do {
        cout << "Digite a matricula do aluno: ";
        cin >> tmp.matricula;
        cin.ignore(); // Limpa o buffer do teclado

        cout << "Digite o nome do aluno: ";
        cin.getline(tmp.nome, 50);

        do {
            cout << "Digite a nota do aluno (0 a 10): ";
            cin >> tmp.nota;
            if (tmp.nota < 0 || tmp.nota > 10) {
                cout << "Nota inválida. Digite novamente.\n";
            }
        } while (tmp.nota < 0 || tmp.nota > 10);

        vetorAlunos.push_back(tmp);

        cout << "Deseja cadastrar outro aluno? (1 - Sim / 0 - Nao): ";
        cin >> opcao;
    } while (opcao == 1);

    // 2. Entrada da Busca
    int matriculaBusca;
    cout << "\nDigite a matrícula para busca: ";
    cin >> matriculaBusca;

    // 3. Busca direta dentro da main
    int indiceEncontrado = -1; // -1 significa "não encontrado"
    for (size_t i = 0; i < vetorAlunos.size(); i++) {
        if (vetorAlunos[i].matricula == matriculaBusca) {
            indiceEncontrado = i; // Guarda a posição onde achou
            break;
        }
    }

    // 4. Exibição dos resultados baseada no índice
    if (indiceEncontrado != -1) {
        cout << "\nAluno encontrado:\n";
        cout << "Nome: " << vetorAlunos[indiceEncontrado].nome << endl;
        cout << "Matricula: " << vetorAlunos[indiceEncontrado].matricula << endl;
        cout << "Nota: " << vetorAlunos[indiceEncontrado].nota << endl;
    } else {
        cout << "\nAluno não encontrado.\n";
    }

    return 0;
}
