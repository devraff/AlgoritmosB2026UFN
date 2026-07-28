#include <iostream>
#include <locale>
using namespace std;

int main() {
    setlocale(LC_ALL, "Portuguese");

    int totalCarboidratoIngerido;
    cout << "Digite o total de carboidratos ingeridos: ";
    cin >> totalCarboidratoIngerido;

    int boulosalimentar;
    cout << "Digite a quantidade de insulina necessária para a quantidade de carboidratos (boulosalimentar): ";
    cin >> boulosalimentar;

    int quantidadeInsulinaCorrecao;
    quantidadeInsulinaCorrecao = totalCarboidratoIngerido / boulosalimentar; // Exemplo de cálculo

    cout << "A quantidade de insulina de correção necessária é: " << quantidadeInsulinaCorrecao << endl;

    return 1;
}