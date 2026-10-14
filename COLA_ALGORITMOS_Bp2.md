# COLA DE CONSULTA — ALGORITMOS B (C++)

> **Foco:** manipulação de arquivos `.txt` e `.csv`, funções, `string`, `struct` e `vector`. Baseada nos arquivos `leitura1.cpp`, `leitura2.cpp`, `desafios.md`, `desafio1.cpp` a `desafio6.cpp` e demais exemplos enviados. **SQLite não incluído.**
>
> **Uso rápido:** `Ctrl + F` pelo verbo do enunciado: **LER**, **GRAVAR**, **COPIAR**, **CSV**, **SOBRENOME**, **CONTAR**, **BUSCAR**, **VETOR**.

## 0. Qual exemplo usar?

| O professor pedir... | Vá para... | Exemplo original |
|---|---|---|
| Ler e exibir linhas de TXT | [1](#1-ler-um-txt-linha-por-linha) | `leitura1.cpp`, `desafio4.cpp` |
| Guardar conteúdo em vetor | [2](#2-ler-txt-e-guardar-em-vector) | `leitura1.cpp`, `desafio6.cpp` |
| Criar/gravar TXT | [3](#3-gravar-arquivo-txt) | `desafio5.cpp`, `desafio6.cpp` |
| Acrescentar sem apagar | [4](#4-adicionar-sem-apagar-iosapp) | Variação útil |
| Ler CSV e converter número | [5](#5-ler-csv-com-find-substr-e-stof) | `leitura2.cpp` |
| Ler CSV com vários campos | [6](#6-ler-csv-com-varios-campos) | Variação útil |
| Extrair sobrenome e gravar destino | [7](#7-desafio-5-txt--struct--sobrenome--txt) | `desafio5.cpp` |
| Contar caracteres e gravar destino | [8](#8-desafio-6-txt--vector--tamanho--txt) | `desafio6.cpp` |
| Contar ocorrências de palavra | [9](#9-contar-ocorrencias-em-txt) | `testemetodo.cpp` |
| Filtrar, procurar, copiar registros | [10](#10-filtrar-e-copiar-linhas) | Variação dos desafios |
| Criar função, usar `struct`/`vector` | [11](#11-struct-vector-e-funcoes) | `desafio2.cpp`, `struct_revisao2.cpp` |
| Trabalhar com nomes, CPF, data, e-mail | [12](#12-manipulacao-de-strings) | `cpfvalido.cpp`, `dataformat.cpp`, `emailcriado.cpp` |
| Montar menu | [13](#13-esqueleto-de-menu) | `revisaoMenu.cpp` |
| Resolver erros comuns | [14](#14-erros-comuns-na-prova) | — |

## 1. LER um TXT linha por linha

**Enunciado típico:** “Leia os nomes de `nomes.txt` e mostre na tela”.

```cpp
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    ifstream arquivo("nomes.txt"); // ENTRADA: leitura
    if (!arquivo.is_open()) {
        cout << "Erro ao abrir o arquivo!\n";
        return 1;
    }

    string linha;
    while (getline(arquivo, linha)) { // até acabar o arquivo
        cout << linha << endl;
    }

    arquivo.close();
    return 0;
}
```

**Alterar:** nome do arquivo e o processamento dentro do `while`. `getline` preserva espaços (nomes completos). Não usar `while (!arquivo.eof())`.

## 2. LER TXT e guardar em `vector`

**Enunciado típico:** “Armazene os nomes em um vetor e depois liste”.

```cpp
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

int main() {
    ifstream arquivo("nomes.txt");
    if (!arquivo) { cout << "Erro ao abrir!\n"; return 1; }

    vector<string> nomes;
    string linha;
    while (getline(arquivo, linha)) {
        nomes.push_back(linha); // adiciona ao final do vetor
    }
    arquivo.close();

    for (int i = 0; i < (int)nomes.size(); i++) {
        cout << nomes[i] << endl;
    }
    return 0;
}
```

**Memorizar:** `push_back` adiciona; `.size()` informa quantidade; `nomes[i]` acessa posição.

## 3. GRAVAR arquivo TXT

**Enunciado típico:** “Crie um arquivo com os nomes cadastrados”.

```cpp
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    ofstream destino("saida.txt"); // SAÍDA: cria ou SOBRESCREVE
    if (!destino) { cout << "Erro ao criar!\n"; return 1; }

    string nome;
    cout << "Nome completo: ";
    getline(cin, nome);
    destino << nome << endl; // escreve linha no arquivo

    destino.close();
    return 0;
}
```

**ATENÇÃO:** `ofstream("saida.txt")` apaga conteúdo antigo. Para acrescentar, veja seção 4.

## 4. ADICIONAR sem apagar (`ios::app`)

```cpp
ofstream arquivo("nomes.txt", ios::app);
if (!arquivo) { cout << "Erro!\n"; return 1; }
arquivo << "Novo Nome" << endl;
arquivo.close();
```

`ios::app` = escreve no **final**, preservando as linhas anteriores.

## 5. LER CSV com `find`, `substr` e `stof`

**Base do professor:** `leitura2.cpp`, arquivo `inflacao.csv`, formato **mês,valor** (separador vírgula).

```cpp
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

struct Inflacao {
    string mes;
    float valor;
};

int main() {
    ifstream arquivo("inflacao.csv");
    if (!arquivo) { cout << "Erro ao abrir CSV!\n"; return 1; }

    vector<Inflacao> dados;
    string linha;
    while (getline(arquivo, linha)) {
        size_t pos = linha.find(','); // posição da vírgula
        if (pos != string::npos) {    // encontrou a vírgula?
            Inflacao tmp;
            tmp.mes = linha.substr(0, pos);      // antes da vírgula
            tmp.valor = stof(linha.substr(pos + 1)); // depois -> float
            dados.push_back(tmp);
        }
    }
    arquivo.close();

    for (const auto& item : dados) {
        cout << item.mes << " -> " << item.valor << endl;
    }
    cout << "Total: " << dados.size() << endl;
    return 0;
}
```

**Alterar:** `','` para `';'` caso o CSV use ponto e vírgula. `stof` converte texto para `float`; `stoi` para `int`; `stod` para `double`. Se houver cabeçalho, pule a primeira linha com `getline(arquivo, linha);` **antes** do `while`. Atenção: `stof` espera número em formato compatível com a configuração de localidade; `1,25` pode exigir tratamento especial.

### Mini-guia de `find` e `substr`

```cpp
string linha = "Janeiro,0.55";
size_t pos = linha.find(',');     // 7
string mes = linha.substr(0, pos); // "Janeiro"
string valor = linha.substr(pos + 1); // "0.55"
```

`find` devolve `string::npos` se não encontrar. `substr(inicio, quantidade)` recorta texto; `substr(inicio)` pega até o fim.

## 6. LER CSV com vários campos

**Variação para prova:** `nome;idade;nota`.

```cpp
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

int main() {
    ifstream arquivo("alunos.csv");
    if (!arquivo) { cout << "Erro!\n"; return 1; }

    string linha;
    while (getline(arquivo, linha)) {
        stringstream ss(linha);
        string nome, idadeTexto, notaTexto;
        if (getline(ss, nome, ';') &&
            getline(ss, idadeTexto, ';') &&
            getline(ss, notaTexto, ';')) {
            int idade = stoi(idadeTexto);
            float nota = stof(notaTexto);
            cout << nome << " | " << idade << " | " << nota << endl;
        }
    }
    arquivo.close();
    return 0;
}
```

**Obs.:** `stringstream` é uma **alternativa adicional**, não o método empregado em `leitura2.cpp`. Este exemplo supõe dados bem formatados e sem delimitadores dentro dos campos.

## 7. DESAFIO 5: TXT → `struct` → sobrenome → TXT

**Enunciado original:** ler nomes completos de um arquivo, guardar nome/sobrenome em vetor de `Pessoa` e gravar `nomeCompleto; sobreNome` no destino.

```cpp
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

struct Pessoa {
    string nomeCompleto;
    string sobreNome;
};

void extrairSobrenome(const string& nome, string& sobrenome) {
    size_t pos = nome.find_last_of(' '); // última ocorrência de espaço
    if (pos != string::npos) sobrenome = nome.substr(pos + 1);
    else sobrenome = "";
}

int main() {
    ifstream origem("nomes.txt");
    if (!origem) { cout << "Erro na origem!\n"; return 1; }

    vector<Pessoa> pessoas;
    string linha;
    while (getline(origem, linha)) {
        Pessoa p;
        p.nomeCompleto = linha;
        extrairSobrenome(p.nomeCompleto, p.sobreNome);
        pessoas.push_back(p);
    }
    origem.close();

    ofstream destino("nomes_destino.txt");
    if (!destino) { cout << "Erro no destino!\n"; return 1; }

    for (const auto& p : pessoas) {
        destino << p.nomeCompleto << "; " << p.sobreNome << endl;
    }
    destino.close();
    return 0;
}
```

**Adaptação:** para gravar outra informação, mude os campos da `struct`, o processamento no `while` e a linha `destino << ...`. `find_last_of(' ')` procura o último espaço. Se o nome tiver espaços finais, convém removê-los antes.

## 8. DESAFIO 6: TXT → `vector` → tamanho → TXT

**Enunciado original:** ler nomes do arquivo de origem, exibir e gravar nome + quantidade de caracteres no destino.

```cpp
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

void lerNomes(const string& caminho, vector<string>& nomes) {
    ifstream arquivo(caminho);
    if (!arquivo) { cout << "Erro na leitura!\n"; return; }
    string linha;
    while (getline(arquivo, linha)) nomes.push_back(linha);
    arquivo.close();
}

void gravarNomes(const string& caminho, const vector<string>& nomes) {
    ofstream arquivo(caminho);
    if (!arquivo) { cout << "Erro na escrita!\n"; return; }
    for (const auto& nome : nomes) {
        arquivo << nome << "; " << nome.size() << endl;
    }
    arquivo.close();
}

int main() {
    vector<string> nomes;
    lerNomes("nomes.txt", nomes);
    for (const auto& nome : nomes) cout << nome << endl;
    gravarNomes("nomes_destino.txt", nomes);
    return 0;
}
```

**Observação:** `.size()` conta unidades de `char` (bytes em UTF-8), então letras acentuadas podem ocupar mais de um byte. O exemplo segue a abordagem do exercício.

## 9. CONTAR ocorrências em TXT

**Base:** `testemetodo.cpp`. Conta ocorrências de uma sequência de caracteres, inclusive dentro de palavras maiores.

```cpp
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int contarOcorrencias(const string& caminho, const string& palavra) {
    ifstream arquivo(caminho);
    if (!arquivo || palavra.empty()) return -1;

    int contador = 0;
    string linha;
    while (getline(arquivo, linha)) {
        size_t pos = linha.find(palavra);
        while (pos != string::npos) {
            contador++;
            pos = linha.find(palavra, pos + palavra.length());
        }
    }
    arquivo.close();
    return contador;
}

int main() {
    string palavra;
    cout << "Palavra: ";
    cin >> palavra;
    cout << "Ocorrencias: " << contarOcorrencias("nomes.txt", palavra) << endl;
    return 0;
}
```

**Diferencie:** `linha.find("Ana") != string::npos` significa **contém**; `linha == "Ana"` significa **linha exatamente igual**. A busca acima diferencia maiúsculas/minúsculas e não conta ocorrências sobrepostas.

## 10. FILTRAR e COPIAR linhas

**Enunciado típico:** “Copie para outro TXT apenas as linhas que contenham determinado nome”.

```cpp
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    ifstream origem("nomes.txt");
    ofstream destino("filtrados.txt");
    if (!origem || !destino) { cout << "Erro!\n"; return 1; }

    string linha;
    int contador = 0;
    while (getline(origem, linha)) {
        if (linha.find("Silva") != string::npos) { // FILTRO
            destino << linha << endl;
            contador++;
        }
    }
    origem.close();
    destino.close();
    cout << "Linhas copiadas: " << contador << endl;
    return 0;
}
```

**Trocar só o `if`:**

```cpp
if (linha == "Ana Beatriz")              // igual
if (linha.find("Ana") != string::npos)    // contém
if (!linha.empty())                       // não vazia
if (linha.size() > 10)                    // mais de 10 bytes
if (!linha.empty() && linha[0] == 'A')    // começa com A
```

Para **copiar tudo**, retire o `if` e escreva `destino << linha << endl;` diretamente dentro do `while`.

## 11. `struct`, `vector` e FUNÇÕES

**Struct** = agrupa campos; **vector** = lista que cresce; **função** = rotina reaproveitável.

```cpp
#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Aluno {
    string nome;
    float nota;
};

void mostrar(const vector<Aluno>& alunos) { // const &: sem copiar vetor
    for (const auto& a : alunos) {
        cout << a.nome << " - " << a.nota << endl;
    }
}

int main() {
    vector<Aluno> alunos;
    Aluno tmp;
    tmp.nome = "Maria";
    tmp.nota = 8.5;
    alunos.push_back(tmp);
    mostrar(alunos);
    return 0;
}
```

**Passagem por referência:** `void preencher(vector<string>& nomes)` altera o vetor original; `const vector<string>& nomes` consulta sem alterar; `void f(string x)` recebe cópia.

**Entrada com espaços após `cin >>`:**

```cpp
#include <limits>
int idade;
string nome;
cin >> idade;
cin.ignore(numeric_limits<streamsize>::max(), '\n');
getline(cin, nome);
```

## 12. MANIPULAÇÃO de strings

### Sobrenome — `desafio2.cpp` / `desafio5.cpp`

```cpp
string nome = "Ana Beatriz Souza";
size_t pos = nome.find_last_of(' ');
string sobrenome = (pos == string::npos) ? "" : nome.substr(pos + 1);
// "Souza"
```

### Primeiro nome

```cpp
size_t pos = nome.find(' ');
string primeiro = nome.substr(0, pos); // "Ana"
```

### E-mail — `emailcriado.cpp`

```cpp
#include <cctype>
string criarEmail(const string& nomeCompleto) {
    size_t pos = nomeCompleto.find(' ');
    if (pos == string::npos) return "";
    string primeiro = nomeCompleto.substr(0, pos);
    string ultimo = nomeCompleto.substr(nomeCompleto.find_last_of(' ') + 1);
    for (char& c : primeiro) c = tolower((unsigned char)c);
    for (char& c : ultimo) c = tolower((unsigned char)c);
    return primeiro + "." + ultimo + "@ufn.edu.br";
}
```

### CPF e data — validação de FORMATO dos exemplos

```cpp
#include <cctype>

bool formatoCPF(const string& cpf) {
    if (cpf.size() != 11) return false;
    for (char c : cpf)
        if (!isdigit((unsigned char)c)) return false;
    return true;
}

bool formatoData(const string& data) {
    if (data.size() != 10 || data[2] != '/' || data[5] != '/')
        return false;
    for (int i = 0; i < (int)data.size(); i++)
        if (i != 2 && i != 5 && !isdigit((unsigned char)data[i]))
            return false;
    return true;
}
```

**IMPORTANTE:** os exemplos do professor verificam apenas **formato**, não dígitos verificadores do CPF nem se a data existe no calendário.

### Comandos de `string` mais usados

| Comando | Resultado |
|---|---|
| `s.size()` / `s.length()` | tamanho em bytes |
| `s.find("abc")` | posição da primeira ocorrência |
| `s.find_last_of(' ')` | posição do último espaço |
| `s.substr(0, 3)` | 3 caracteres desde posição 0 |
| `s.substr(4)` | da posição 4 até o fim |
| `s.empty()` | `true` se vazia |
| `stoi(s)` | texto → inteiro |
| `stof(s)` | texto → float |
| `to_string(n)` | número → texto |

## 13. ESQUELETO de menu

**Variação simples** do padrão de `revisaoMenu.cpp` (o arquivo original depende de headers externos).

```cpp
#include <iostream>
using namespace std;

int main() {
    int opcao;
    do {
        cout << "\n1 - Ler arquivo\n";
        cout << "2 - Gravar arquivo\n";
        cout << "3 - Listar\n";
        cout << "4 - Sair\n";
        cout << "Opcao: ";
        cin >> opcao;

        switch (opcao) {
            case 1: cout << "Leitura\n"; break;
            case 2: cout << "Gravacao\n"; break;
            case 3: cout << "Listagem\n"; break;
            case 4: cout << "Encerrando...\n"; break;
            default: cout << "Opcao invalida!\n";
        }
    } while (opcao != 4);
    return 0;
}
```

Substituir `cout` de cada `case` pela função correspondente (`lerArquivo()`, `gravarArquivo()` etc.).

## 14. ERROS COMUNS NA PROVA

1. **Não encontra `nomes.txt`:** caminho é relativo à **pasta de execução** do programa, não necessariamente à pasta do `.cpp`.
2. **Arquivo de saída perdeu os dados:** `ofstream` sobrescreve; usar `ios::app` se precisar adicionar.
3. **Nome completo veio vazio:** após `cin >> numero`, usar `cin.ignore(...)` antes de `getline(cin, nome)`.
4. **CSV ficou errado:** conferir se separador é `,` ou `;` e se há cabeçalho.
5. **Erro em `stof`/`stoi`:** campo não numérico, vazio ou decimal com vírgula; validar dados antes de converter.
6. **Acesso inválido a `linha[0]`:** testar `!linha.empty()` primeiro.
7. **Usou `find` como booleano:** usar `find(...) != string::npos`, não `if (linha.find(...))`.
8. **Esqueceu `#include <fstream>`:** necessário para `ifstream` e `ofstream`.
9. **Misturou arquivos:** `ifstream` = leitura; `ofstream` = escrita.
10. **Tentou compilar vários exemplos juntos:** cada bloco completo tem seu próprio `main()`; copiar **um exemplo por vez** para um `.cpp`.

## 15. CHECKLIST PARA MONTAR UMA RESPOSTA DE PROVA

1. **Identificar entrada:** teclado (`cin`/`getline(cin, ...)`) ou arquivo (`ifstream`)?
2. **Identificar saída:** tela (`cout`) ou arquivo (`ofstream`)?
3. **Definir estrutura:** apenas `string`, `vector<string>` ou `struct` + `vector`?
4. **Abrir e testar** os arquivos com `if (!arquivo)`.
5. **Ler:** normalmente `while (getline(arquivo, linha))`.
6. **Processar:** `find`, `substr`, `.size()`, `stoi`, `stof`, `if`.
7. **Salvar:** `destino << campo1 << "; " << campo2 << endl;`.
8. **Fechar:** `arquivo.close()`.
9. **Testar:** arquivo existente, vazio, nomes com espaços, delimitador e saída esperada.

### Cola de 15 segundos

```cpp
ifstream origem("entrada.txt");          // LER
ofstream destino("saida.txt");          // ESCREVER/SOBRESCREVER
// ofstream destino("saida.txt", ios::app); // ADICIONAR
if (!origem || !destino) return 1;
string linha;
while (getline(origem, linha)) {
    // AQUI: calcular, filtrar, separar, contar...
    destino << linha << endl;
}
origem.close();
destino.close();
```

**Esse é o padrão central dos desafios 4, 5 e 6: abrir → ler → processar → gravar.**
