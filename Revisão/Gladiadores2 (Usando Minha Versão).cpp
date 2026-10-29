#include <iostream>
#include <string>
#include <cmath>
using namespace std;

struct gladiador
{
	string nome; // nome do gladiador
	int forca; // força do gladiador
	int habilidade; // habilidade do gladiador
	int idade;
};

int combate(gladiador g1,gladiador g2)
{
	int vidag1 = 100; // começa com 100 pontos de vida
	int vidag2 = 100; // vida do gladiador 2
	int dano; // dano sofrido
	int i = 0; // contador
	
	while(vidag1 > 0 && vidag2 > 0)
	{
		if(i % 2 == 0)
		{
			dano = g1.forca + (pow(2, g1.habilidade));
			vidag2 -= dano;	
		}
		else
		{
			dano = g2.forca + (pow(2, g2.habilidade));
			vidag1 -= dano;
		}
		i++;
	}
	
	if(vidag2 <= 0) // 1 ganhou
		return 0;
	else if(vidag1 <= 0) // 2 ganhou
		return 1;
	else // em caso de erro
		return -1;
}

int main()
{
	gladiador info[1000]; // vetor com as informações do gladiador
	int i = 0; // contador
	int g1; // posição do gladiador 1 no vetor
	int g2; // posição do gladiador 2 no vetor
	int vencedor;
	int op; // opção do jogador
	
	do {
		cin >> op;
	}while(op < 1 || op > 3);
	
	while(op != 3) {
		if(op == 1) // cadastrar novo gladiador
		{
			cin >> info[i].nome;
			cin >> info[i].forca;
			cin >> info[i].habilidade;
			cin >> info[i].idade;
			i++;
		}
		
		else if(op == 2 && i <= 1)
		{
			cout << "Para batalhar, e necessario o cadastro de dois os mais gladiadores." << endl;
		}
		
		else if(op == 2 && i > 1) // fazer uma batalha entre 2 gladiadores
		{
			cin >> g1 >> g2;		
			vencedor = combate(info[g1], info[g2]);
			if(vencedor == 0)
			{
				cout << info[g1].nome << " ganhou a batalha contra " << info[g2].nome << "." << endl;
			}
			else if (vencedor == 1)
			{
				cout << info[g2].nome << " ganhou a batalha contra " << info[g1].nome << "." << endl;
			}
			else
				cout << "Erro";
		}
		
		do {
			cin >> op;
		}while(op < 1 || op > 3);
	}
	
	return 0;
}