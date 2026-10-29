#include <iostream>
#include <string>
using namespace std;

struct Item {
    int codigo;
    string nome;
    int preco;
};

int hashLinear(int codigo, int m, int i) {
    return (codigo + i) % m;
}

int main() {
    const int M = 43;
    Item tabela[M];
    bool ocupado[M] = {false}; // marcação de posições ocupadas

    int N;
    cin >> N;

    // Cadastro de itens
    for (int i = 0; i < N; i++) {
        Item item;
        cin >> item.codigo >> item.nome >> item.preco;

        int j = 0, pos;
        do {
            pos = hashLinear(item.codigo, M, j);
            j++;
        } while (ocupado[pos] && j < M);

        tabela[pos] = item;
        ocupado[pos] = true;
    }

    // Leitura dos códigos vendidos (-1 finaliza)
    int vendas[100], qtdVendas = 0;
    int cod;
    while (cin >> cod && cod != -1) {
        vendas[qtdVendas++] = cod;
    }

    // Leitura dos códigos comprados (-1 finaliza)
    int compras[100], qtdCompras = 0;
    while (cin >> cod && cod != -1) {
        compras[qtdCompras++] = cod;
    }

    // Leitura de V e C
    int V, C;
    cin >> V >> C;

    int totalVendas = 0;
    int totalCompras = 0;

    // Processar as V primeiras vendas (fila: ordem normal)
    for (int i = 0; i < V && i < qtdVendas; i++) {
        int codigo = vendas[i];

        int j = 0, pos;
        while (j < M) {
            pos = hashLinear(codigo, M, j);
            if (ocupado[pos] && tabela[pos].codigo == codigo) {
                totalVendas += tabela[pos].preco;
                break;
            }
            j++;
        }
    }

    // Processar as C últimas compras (pilha: ordem reversa)
    for (int i = 0; i < C && i < qtdCompras; i++) {
        int codigo = compras[qtdCompras - 1 - i];

        int j = 0, pos;
        while (j < M) {
            pos = hashLinear(codigo, M, j);
            if (ocupado[pos] && tabela[pos].codigo == codigo) {
                totalCompras += tabela[pos].preco;
                break;
            }
            j++;
        }
    }

    // Calcular e imprimir lucro
    int lucro = totalVendas - totalCompras;
    cout << lucro << " moeda(s)." << endl;

    return 0;
}