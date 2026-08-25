#include <iostream>
#include <string>
#include <vector>
#include "sqlite3.h" // Biblioteca do SQLite

using namespace std;

typedef struct {
    string mes;
    float valor;
} Inflacao;

// Função auxiliar (callback) que o SQLite usa para cada linha retornada pelo SELECT
int callback(void* data, int argc, char** argv, char** azColName) {
    // Converte o ponteiro de dados de volta para o vetor
    vector<Inflacao>* vetor = static_cast<vector<Inflacao>*>(data);
    
    Inflacao tmp;
    // argv[0] é a coluna MES, argv[1] é a coluna VALOR
    tmp.mes = argv[0] ? argv[0] : "";
    tmp.valor = argv[1] ? stof(argv[1]) : 0.0f;
    
    vetor->push_back(tmp);
    return 0;
}

int main() {
    sqlite3* DB;
    char* mensagemErro = 0;

    // 1. Abrir ou criar o arquivo de banco de dados
    int resultado = sqlite3_open("banco_inflacao.db", &DB);
    if (resultado) {
        cout << "Erro ao abrir o banco de dados: " << sqlite3_errmsg(DB) << endl;
        return 1;
    }

    // 2. Criar a tabela (equivalente a garantir que o arquivo existe)
    string sqlCriarTabela = "CREATE TABLE IF NOT EXISTS INFLACAO(" \
                            "MES TEXT PRIMARY KEY NOT NULL, " \
                            "VALOR REAL NOT NULL);";
                            
    resultado = sqlite3_exec(DB, sqlCriarTabela.c_str(), NULL, 0, &mensagemErro);
    if (resultado != SQLITE_OK) {
        cout << "Erro ao criar tabela: " << mensagemErro << endl;
        sqlite3_free(mensagemErro);
        sqlite3_close(DB);
        return 1;
    }

    // 3. Exemplo de inserção de dados (Opcional - simulando novos dados)
    // Usamos INSERT OR IGNORE para não duplicar se você rodar o programa várias vezes
    string sqlInserir = "INSERT OR IGNORE INTO INFLACAO (MES, VALOR) VALUES " \
                        "('Janeiro/2026', 0.55), " \
                        "('Fevereiro/2026', 0.42), " \
                        "('Março/2026', 0.38);";
                        
    sqlite3_exec(DB, sqlInserir.c_str(), NULL, 0, &mensagemErro);

    // 4. Ler os dados do banco e armazenar no vetor (Substitui o ifstream e getline)
    vector<Inflacao> vetorInflacao;
    string sqlConsultar = "SELECT MES, VALOR FROM INFLACAO;";

    // Passamos o endereço de 'vetorInflacao' como o 4º parâmetro para o callback usar
    resultado = sqlite3_exec(DB, sqlConsultar.c_str(), callback, &vetorInflacao, &mensagemErro);

    if (resultado != SQLITE_OK) {
        cout << "Erro ao consultar dados: " << mensagemErro << endl;
        sqlite3_free(mensagemErro);
    } else {
        // 5. Exibir o vetor na tela (Igual ao seu código original)
        for (size_t i = 0; i < vetorInflacao.size(); i++) {
            cout << "Mes: " << vetorInflacao[i].mes << " - Valor: " << vetorInflacao[i].valor << endl;
        }
        cout << "Total de registros lidos do banco: " << vetorInflacao.size() << endl;
    }

    // 6. Fechar a conexão com o banco de dados
    sqlite3_close(DB);
    return 0;
}
