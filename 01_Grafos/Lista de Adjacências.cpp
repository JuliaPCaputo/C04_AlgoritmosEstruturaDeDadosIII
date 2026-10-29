#include <iostream>
#include <list>
using namespace std;

struct no {
    int v;     // vértice adjacente
    int peso;  // peso da aresta
};

// Função para criar aresta
void cria_aresta(list<no> adj[], int u, int v, int p, int orientado) {
    no novo_no;
    novo_no.v = v;
    novo_no.peso = p;
    adj[u].push_back(novo_no);

    // Se o grafo for não orientado, cria também a aresta inversa
    if (orientado == 0) {
        novo_no.v = u;
        adj[v].push_back(novo_no);
    }
}

int main() {
    int n_vertices, orientado;
    cin >> n_vertices >> orientado;

    list<no> adj[n_vertices];

    int u, v, p;
    while (true) {
        cin >> u >> v >> p;
        if (u == -1 && v == -1 && p == -1)
            break;
        cria_aresta(adj, u, v, p, orientado);
    }

    // Exibe o grafo
    for (int i = 0; i < n_vertices; i++) {
        list<no>::iterator it;
        for (it = adj[i].begin(); it != adj[i].end(); ++it) {
        	cout << i << " ";
            cout << it->v << " " << it->peso;
            cout << endl;
        }
    }

    return 0;
}