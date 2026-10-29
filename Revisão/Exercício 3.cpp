#include <iostream>
#include <string>
using namespace std;

// Função de busca sequencial
int sequencial(string vetor[],int tamanho, string x)
{
	bool achou = false; // var aux p/ busca
	int i = 0; // contador
	
	while(achou == false && i < tamanho)
		achou = vetor[i++] == x;
	
	if(achou)
		return (i-1);
	else
		return -1;
}

int main()
{
	string produto[100]; // vetor de até 100 posições com os produtos a serem adicionados à lista
	int quantidade[100]; // vetor de 100 posições com a quantidade em estoque
	int N; // quantidade de produtos a serem cadastrados
	string procurar; // produto a ser procurado
	int resultado; // resultado da busca
	int i = 0; // contador
	
	do {
		cin >> N;
	}while(N < 0 || N > 100);
	
	while(i < N)
	{
		cin.ignore();
		cin >> produto[i];
		cin >> quantidade[i];
		i++;
	}
	
	cin >> procurar;
	resultado = sequencial(produto, N, procurar);
	
	if(resultado == -1)
		cout << "Nao existe " << procurar << " em estoque!" << endl;
	else
		cout << procurar << " em estoque!" << endl;
	
	return 0;
}