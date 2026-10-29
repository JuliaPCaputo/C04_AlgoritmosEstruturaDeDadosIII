#include <iostream>
#include <list>
#define MAXV 1000
#define INF 9999
using namespace std;

struct no {
    int v;     // vértice adjacente
    int peso;  // peso da aresta
};

// Função para criar aresta
void cria_aresta(list<no> adj[], int u, int v, int p, int orientado) // u = vertice de origem; v = vertice de destino
{
    no novo_no;
    novo_no.v = v;
    novo_no.peso = p;
    adj[u].push_back(novo_no);

    // Se o grafo não for orientado, cria também a aresta inversa
    if (orientado == 0) {
        novo_no.v = u;
        adj[v].push_back(novo_no);
    }
}

// Função de Prim
void prim(list<no>adj[], int nVertices, int start) {
    bool intree[10]; // indica se o vértice está na árvore
    int distance[10]; // menor peso conhecido até o vértice
    int parent[10]; // pai do vértice na árvore

    for (int i = 0; i < nVertices; i++) {
        intree[i] = false; // começa com false
        distance[i] = INF; // começa com infinito
        parent[i] = -1; // começa com -1
    }

    distance[start] = 0;
    int v = start;

    while (intree[v] == false) {
        intree[v] = true;

        // Percorre os vértices adjacentes de v
        list<no>::iterator it;
        for (it = adj[v].begin(); it != adj[v].end(); ++it) {
            int destino = it->v;
            int weight = it->peso;
            if (distance[destino] > weight && intree[destino] == false) {
                distance[destino] = weight;
                parent[destino] = v;
            }
        }

        // Escolhe o próximo vértice com menor distância
        int dist = MAXV;
        for (int u = 0; u < nVertices; u++) {
            if (intree[u] == false && distance[u] < dist) {
                dist = distance[u];
                v = u;
            }
        }

        if (dist == MAXV)
            break;
    }

    // Exibe as arestas da árvore geradora mínima
    int custo_total = 0;
    cout << "Arvore Geradora Minima:" << endl;
    for (int i = 0; i < nVertices; i++) {
        if (parent[i] != -1) {
            cout << parent[i] << " " << i << endl;
            custo_total += distance[i];
        }
    }
    cout << "Custo: " << custo_total << endl;
}

int main() {
    int n_vertices, orientado, start;
    cin >> n_vertices >> orientado >> start;

    list<no> adj[n_vertices];

    int u, v, p;
    while (true) {
        cin >> u >> v >> p;
        if (u == -1 && v == -1 && p == -1)
            break;
        cria_aresta(adj, u, v, p, orientado);
    }

    prim(adj, n_vertices, start);

    return 0;
}