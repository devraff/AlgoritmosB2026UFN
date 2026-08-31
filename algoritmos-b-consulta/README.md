# Algoritmos B — Consulta rápida para prova

Material de consulta baseado no padrão dos exercícios da disciplina: `do...while`, `switch`, vetores, `struct`, contador de registros e operações de cadastro/listagem/busca.

## Qual arquivo abrir?

| Se o enunciado pedir... | Abra |
|---|---|
| Menu simples | `01_menu_base.cpp` |
| Vetor + popular + listar | `02_menu_vetor.cpp` |
| Média, maior ou menor | `03_vetor_calculos.cpp` |
| Ordenar vetor / mediana | `04_ordenacao_mediana.cpp` |
| Struct básica | `05_struct_basica.cpp` |
| Cadastro + listagem com struct | `06_struct_menu_cadastro.cpp` |
| Buscar registro | `07_struct_busca.cpp` |
| Editar registro | `08_struct_editar.cpp` |
| Remover registro | `09_struct_remover.cpp` |
| Modelo mais completo | `10_crud_struct_completo.cpp` |
| Lembrar sintaxe rapidamente | `COLA_RAPIDA.md` |

## Estratégia na prova

1. Identifique os **dados**: nome, idade, nota etc. → provavelmente viram campos da `struct`.
2. Identifique a **quantidade de registros** → vetor de `struct` + contador.
3. Identifique as **ações** → cada ação vira um `case` do `switch`.
4. Antes de listar/buscar/editar/remover, teste se `qtd == 0`.
5. Para cadastrar, teste se `qtd < TAM`.
6. Para buscar, percorra `for (int i = 0; i < qtd; i++)` e compare o campo identificador.
7. Para remover, desloque os elementos seguintes uma posição para a esquerda e faça `qtd--`.

## Estrutura mental do menu

```cpp
do {
    // mostrar opções
    cin >> opcao;

    switch (opcao) {
        case 1:
            // ação 1
            break;
        case 2:
            // ação 2
            break;
        case 0:
            break;
        default:
            cout << "Opcao invalida!\n";
    }
} while (opcao != 0);
```

## Observação importante

Os exemplos aqui são autocontidos: cada `.cpp` compila sozinho, sem depender de headers externos.
