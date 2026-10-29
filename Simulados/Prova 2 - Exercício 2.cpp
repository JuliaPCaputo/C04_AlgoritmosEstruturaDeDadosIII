/*
Nestes dias se pensa muito em economia, mesmo em Anatricé. Para reduzir custos operacionais, o prefeito decidiu otimizar a iluminação das estradas.
Até agora, todas as rotas eram iluminadas durante toda noite, o que custava um real por metro a cada dia. Para economizar, eles decidiram não iluminar
mais todas as estradas e desligar a iluminação de algumas delas. Para ter certeza que os habitantes de Anatricé continuem a se sentirem seguros, eles
querem otimizar o sistema de tal forma que após desligar a iluminação de algumas estradas à noite, sempre existirá algum caminho iluminado de qualquer
junção para qualquer outra junção. Qual é a quantidade máxima de dinheiro que o governo pode economizar, sem fazer os seus habitantes sentirem-se
inseguros?

Entrada
A entrada contém vários casos de teste. Cada caso de teste inicia com dois números m (1 = m = 200000) e n (m-1 = n = 200000), que são o número de junções
da cidade e o número de estradas, respectivamente. Seguem n conjuntos de três valores inteiros, x, y e z, especificando qual será a estrada bidirecional
entre x e y com z metros (0 = x, y < m e x ? y).
A entrada termina com m=n=0. O grafo especificado em cada caso de teste é conectado. O tamanho total de todas as estradas em cada caso de teste é menor
do que 231.

Saída
Para cada caso de teste imprima uma linha contendo a máxima quantidade diária de reais que o governo pode economizar.
*/

#define INF 9999
#define MAXV 100

#include<iostream>
#include<list>
using namespace std;

struct Aresta{
    int destino, peso;
};

int prim_lista(list<Aresta> listas_adj[], int vertices, int origem){
    bool visitado[vertices];
    int melhor_aresta[vertices], pai[vertices], atual, melhor_aresta_atual;
    list<Aresta>::iterator it;
    
    for(int i = 0; i < vertices; i++){
        visitado[i] = false;
        pai[i] = -1;
        melhor_aresta[i] = INF;
    }
	
    atual = origem;
    melhor_aresta[atual] = 0;
    
	while(!visitado[atual]){
        visitado[atual] = true;
        for(it = listas_adj[atual].begin(); it != listas_adj[atual].end(); it++){
            int destino_adj = it->destino, peso_adj = it->peso;
            
			if(!visitado[destino_adj] && peso_adj < melhor_aresta[destino_adj]){
                melhor_aresta[destino_adj] = peso_adj;
                pai[destino_adj] = atual;
            }
        }
        
		melhor_aresta_atual = INF;
        for(int i = 0; i < vertices; i++){
            if(!visitado[i] && melhor_aresta[i] < melhor_aresta_atual){
                melhor_aresta_atual = melhor_aresta[i];
                atual = i;
            }
        }
    }
    
    int soma = 0;
    for(int i = 0; i < vertices; i++){
        if(visitado[i]){
            soma += melhor_aresta[i];
        }
    }
    
    return soma;
}

int main(){
    list<Aresta> listas_adj[MAXV];   
    int m, n, x, y, z, soma=0, economia=0;
    
    while(cin >> m >> n && m != 0 && n != 0){
        for(int i = 0; i < m; i++ ){
            listas_adj[i].clear();
        }
        for(int i = 0; i < n; i++){
            cin >> x >> y >> z;
            listas_adj[x].push_back({y, z});
            listas_adj[y].push_back({x, z});
            soma += z;
        }
        economia += soma - prim_lista(listas_adj, m, 0);
    }
    
    cout << economia << endl;
    
    return 0;
}