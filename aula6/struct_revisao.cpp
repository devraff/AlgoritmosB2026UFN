/**
    Fazer um programa que armazene N dados de pessoas em um vetor (ou vector), contendo nome, altura(metros) e peso(kg)
*/

#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

#include "meusTipos.h"

int main() {
    IndiceMassaCorporal pessoaTMP;
    
    pessoaTMP.nome = "Rafael Figueiredo";
    pessoaTMP.altura = 1.70;
    pessoaTMP.peso = 76.0;

    cout << "Nome: " << pessoaTMP.nome << endl;
    cout << "Altura(M): " << fixed << setprecision(2) << pessoaTMP.altura << endl;
    cout << "Peso(KG): " << fixed << setprecision(2) << pessoaTMP.peso << endl;

    //rotina de calculo do IMC = peso / (altura * altura)
    float imc = pessoaTMP.peso / (pessoaTMP.altura * pessoaTMP.altura);

    cout << "IMC: " << fixed << setprecision(2) << imc << endl;

    return 0;
}