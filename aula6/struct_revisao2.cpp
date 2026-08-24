#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

#include "meusTipos.h"

int main() {
    IndiceMassaCorporal pessoaTMP;
    vector<IndiceMassaCorporal> atletas;
    int quantidadeAtletas;

    cout << "Digite a quantidade de atletas: ";
    cin >> quantidadeAtletas;

    // Remove o '\n' deixado pelo 'cin >> quantidadeAtletas' antes de entrar no loop
    cin.ignore(); 

    // Rotina de persistencia em ram
    for (int i = 0; i < quantidadeAtletas; i++) {
        cout << "\n--- Atleta " << i + 1 << " ---" << endl;
        cout << "Nome atleta: ";
        getline(cin, pessoaTMP.nome); // Lê o nome completo perfeitamente

        // Validação da Altura
        do {
            cout << "Altura atleta (metros): ";
            cin >> pessoaTMP.altura;
            if (pessoaTMP.altura < 0.30 || pessoaTMP.altura > 2.70) {
                cout << "Altura inválida. Digite novamente." << endl;
            }
        } while (pessoaTMP.altura < 0.30 || pessoaTMP.altura > 2.70);

        // Validação do Peso
        do {
            cout << "Peso atleta (kg): ";
            cin >> pessoaTMP.peso;
            if (pessoaTMP.peso < 30.0 || pessoaTMP.peso > 150.0) {
                cout << "Peso inválido. Digite novamente." << endl;
            }
        } while (pessoaTMP.peso < 30.0 || pessoaTMP.peso > 150.0);

        // Remove o '\n' deixado pelo último 'cin >>' para a próxima iteração do getline
        cin.ignore(); 
        
        atletas.push_back(pessoaTMP);
    }

    // Rotina de exibição e cálculo do IMC
    cout << "\n=== RESULTADOS ===" << endl;
    float imc;
    for (size_t i = 0; i < atletas.size(); i++) {
        cout << "Nome: " << atletas[i].nome << endl;
        imc = atletas[i].peso / (atletas[i].altura * atletas[i].altura);
        cout << "IMC: " << fixed << setprecision(2) << imc << endl;
        cout << "-----------------" << endl;
    }

    return 0; // O padrão em C++ para execução bem-sucedida é retornar 0
}
