#include <iostream>
#include <list>
using namespace std;

int h1(int k, int m)
{
	int h;
	
	h = k % m;
	if(h < 0)
		h += m;
	
	return h;
}

int h2(int k, int m)
{
 	 return 1 + (k % (m - 1));
}

int dhash(int k, int m, int i) // função de double hashing
{
	int h;
	
	h = (h1(k, m) + i * h2(k, m)) % m;
	if(h < 0)
		h += m;
	return h;
}

int main()
{
	int M; // tamanho da tabela
	int quantidade; // quantidade de elementos a serem inseridos
	int elemento; // elementos a serem inseridos
	list <int> lista; // "ponteiro" p/ lista
	list <int>::iterator p; // ponteiro auxiliar
	int tabela[100]; // para inserir os elementos na tabela hash
	int i = 0; // contador
	int k; // chave
	int pos; // posição
	int tentativas; // tentativas de inserir na lista
	
	do{
		cin >> M;
	}while(M <= 1);
	
	do {
		cin >> quantidade;
	}while(quantidade < 0 || quantidade > 100);
	
	for(i = 0; i < quantidade; i++)
	{
		cin >> elemento;
		lista.push_front(elemento);
	}
	
	for(i = 0; i < M; i++)
	{
		tabela[i] = -1;
	}
	
	for(p = lista.begin(); p != lista.end(); p++)
	{
		tentativas = 0;
        k = *p;

        do{
            pos = dhash(k, M, tentativas);
            tentativas++;
        }while (tabela[pos] != -1 && tentativas < M);

        tabela[pos] = k;
	}

	for (int i = 0; i < M; i++)
	{
		cout << tabela[i] << " ";
	}
	
	return 0;
}