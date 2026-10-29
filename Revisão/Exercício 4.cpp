#include <iostream>
#include <string>
using namespace std;

int binaria(int vetor[],int tamanho, int x)
{
	bool achou; // var aux p/ busca
	int baixo, meio, alto; // var aux
	
	baixo = 0;
	alto = tamanho-1;
	achou = false;
	
	while ((baixo <= alto) && (achou == false))
	{
		meio = (baixo + alto) / 2;
		if (x < vetor[meio])
			alto = meio - 1;
		else
		{
			if (x > vetor[meio])
				baixo = meio + 1;
			else
				achou = true;
		}
	}
	
	if (achou)
		return meio;
	else
		return -1;
}

int main()
{
	int N; // quantidade de produtos cadastrados
	int codigo[100]; // vetor de 100 posições com o código do produto
	string produto[100]; // vetor de 100 posições com o nome do produto
	int quantidade[100]; // vetor de 100 posições com a quantidade em estoque
	int i = 0; // contador
	int procurar; // código a ser buscado
	int resultado; // resultado da busca
	
	do {
		cin >> N;
	}while(N < 0 || N > 100);
	
	while(i < N)
	{
		cin >> codigo[i];
		cin >> produto[i];
		cin >> quantidade[i];
		i++;
	}
	
	cin >> procurar;
	resultado = binaria(codigo, N, procurar);
	
	if(resultado == -1)
		cout << "Nao existem produtos com esse codigo em estoque!" << endl;
	else
		cout << produto[resultado] << " em estoque!" << endl;
	
	return 0;
}