#include <iostream>
#include <string>
using namespace std;

struct inseto
{
	string especie;
	double tamanho;
};

void insercaoDireta(inseto vetor[], int tamanho)
{
	int i, j; // contadores
	inseto chave;

	for (j = 1; j < tamanho; j++)
	{
		chave = vetor[j];
		i = j - 1;
		while ((i >= 0) && (vetor[i].tamanho > chave.tamanho))
		{
			vetor[i + 1] = vetor[i];
			i--;
		}
		vetor[i + 1] = chave;
	}
}

int main()
{
	inseto info[100]; // vetor de até 100 posições para os insetos
	int N; // tamanho do vetor
	int i; // contador
	
	cin >> N;
	
	for(i = 0; i < N; i++)
	{
		cin.ignore();
		getline(cin, info[i].especie);
		cin >> info[i].tamanho;
	}
	
	insercaoDireta(info, N);
	
	for(i = 0; i < N; i++)
	{
		cout << info[i].especie << endl;
	}
	
	return 0;
}