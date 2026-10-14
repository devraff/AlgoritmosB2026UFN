#include <ctime>
#include <iostream>
#include <vector>

using namespace std;

void exibirVetor(vector<int> &vA, vector<int> &vB) {
    for (int i = 0; i < vA.size(); i++) {
        cout << vA[i] << "\t";
    }
    cout << endl;
    for (int i = 0; i < vB.size(); i++) {
        cout << vB[i] << "\t";
    }
    cout << endl;
}

void popularVetor(vector<int> &vA, vector<int> &vB, int qtd, int inicio, int fim) {
    srand(time(NULL));
    int numero;
    for(int i = 0; i < qtd; i++) {
        numero = (rand() % (fim - inicio + 1)) + inicio;
        vA.push_back(numero);
        numero = (rand() % (fim - inicio + 1)) + inicio;
        vB.push_back(numero);
    }
}

void exibirResultado(vector<int> &vA, vector<int> &vB) {
    int somaA = 0, somaB = 0, SomaAB = 0;
    for (int i = 0; i < vA.size(); i++) {
        somaA += vA[i];
    }
    for (int i = 0; i < vB.size(); i++) {
        somaB += vB[i];
    }
    SomaAB = somaA + somaB;
    cout << "Soma dos elementos de A: " << somaA << endl;
    cout << "Soma dos elementos de B: " << somaB << endl;
    cout << "Soma dos elementos de A e B: " << SomaAB << endl;
}

int main() {
    vector<int> vetorA;
    vector<int> vetorB;

    popularVetor(vetorA, vetorB, 10, 100, 500);
    exibirVetor(vetorA, vetorB);
    exibirResultado(vetorA, vetorB);

    return 1;
}