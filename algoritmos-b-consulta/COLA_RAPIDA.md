# COLA RÁPIDA — Algoritmos B

## 1. Menu

```cpp
int opcao;
do {
    cout << "1 - Cadastrar\n";
    cout << "2 - Listar\n";
    cout << "0 - Sair\n";
    cout << "Opcao: ";
    cin >> opcao;

    switch (opcao) {
        case 1:
            break;
        case 2:
            break;
        case 0:
            cout << "Saindo...\n";
            break;
        default:
            cout << "Opcao invalida!\n";
    }
} while (opcao != 0);
```

## 2. Struct

```cpp
struct Pessoa {
    int codigo;
    string nome;
    int idade;
};
```

## 3. Vetor de structs + contador

```cpp
#define TAM 100
Pessoa pessoas[TAM];
int qtd = 0;
```

**`TAM`** = capacidade máxima.  
**`qtd`** = quantos registros realmente existem.

## 4. Cadastrar

```cpp
if (qtd < TAM) {
    cout << "Codigo: ";
    cin >> pessoas[qtd].codigo;

    cout << "Nome: ";
    cin.ignore();
    getline(cin, pessoas[qtd].nome);

    cout << "Idade: ";
    cin >> pessoas[qtd].idade;

    qtd++;
} else {
    cout << "Vetor cheio!\n";
}
```

## 5. Listar

```cpp
if (qtd == 0) {
    cout << "Nenhum registro.\n";
} else {
    for (int i = 0; i < qtd; i++) {
        cout << pessoas[i].codigo << " - "
             << pessoas[i].nome << " - "
             << pessoas[i].idade << endl;
    }
}
```

## 6. Buscar

```cpp
int codigo;
bool encontrou = false;

cout << "Codigo: ";
cin >> codigo;

for (int i = 0; i < qtd; i++) {
    if (pessoas[i].codigo == codigo) {
        cout << pessoas[i].nome << endl;
        encontrou = true;
        break;
    }
}

if (!encontrou) {
    cout << "Nao encontrado.\n";
}
```

## 7. Editar

```cpp
for (int i = 0; i < qtd; i++) {
    if (pessoas[i].codigo == codigo) {
        cin.ignore();
        getline(cin, pessoas[i].nome);
        cin >> pessoas[i].idade;
        encontrou = true;
        break;
    }
}
```

## 8. Remover

```cpp
for (int i = 0; i < qtd; i++) {
    if (pessoas[i].codigo == codigo) {
        for (int j = i; j < qtd - 1; j++) {
            pessoas[j] = pessoas[j + 1];
        }
        qtd--;
        encontrou = true;
        break;
    }
}
```

## 9. Somar / média de vetor

```cpp
int soma = 0;
for (int i = 0; i < TAM; i++) {
    soma += vetor[i];
}
float media = soma / static_cast<float>(TAM);
```

## 10. Maior e menor

```cpp
int menor = vetor[0];
int maior = vetor[0];

for (int i = 1; i < TAM; i++) {
    if (vetor[i] < menor) menor = vetor[i];
    if (vetor[i] > maior) maior = vetor[i];
}
```

## 11. Bubble Sort

```cpp
for (int i = 0; i < TAM - 1; i++) {
    for (int j = 0; j < TAM - i - 1; j++) {
        if (vetor[j] > vetor[j + 1]) {
            int temp = vetor[j];
            vetor[j] = vetor[j + 1];
            vetor[j + 1] = temp;
        }
    }
}
```

## 12. Mediana após ordenar

```cpp
float mediana;
if (TAM % 2 == 0) {
    mediana = (vetor[TAM / 2 - 1] + vetor[TAM / 2]) / 2.0;
} else {
    mediana = vetor[TAM / 2];
}
```

## Erros que mais ferram prova

- esquecer `break;` no `case`;
- colocar `switch` fora do `do...while`;
- percorrer até `TAM` quando só existem `qtd` registros cadastrados;
- esquecer `qtd++` depois de cadastrar;
- esquecer `qtd--` depois de remover;
- acessar `vetor[0]` com vetor vazio;
- usar divisão inteira na média;
- confundir `=` com `==` em comparação;
- esquecer `cin.ignore()` antes de `getline` após usar `cin >>`.
