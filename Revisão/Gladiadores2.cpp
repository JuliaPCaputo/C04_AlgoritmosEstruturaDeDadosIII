#include<iostream>
using namespace std;

struct Gladiador{
   	string nome;
   	int forca, habilidade, idade, vida;
};

int potencia(int base, int exp) {
	if (exp == 0) return 1;
	if (exp == 1) return base;
	return base * potencia(base, exp - 1);
}

int ataque(Gladiador gladiador) {
	return gladiador.forca + potencia(2, gladiador.habilidade);
}

bool combate(Gladiador gladiador1, Gladiador gladiador2) {
	while (gladiador1.vida > 0 && gladiador2.vida > 0) {
		gladiador2.vida -= ataque(gladiador1);
		gladiador1.vida -= ataque(gladiador2);
	}
	if (gladiador2.vida <= 0) return true;
	else return false;
}

int main(){
	string nome;
	int forca, habilidade, idade, gladiador1, gladiador2;
	Gladiador gladiadores[1000];
	int i = 0;
	int op; // opção escolhida pelo jogador
	
	do {
		cin >> op;
	}while(op < 1 || op > 3);
	
	while(op != 3) {
		if(op == 1) // cadastrar novo gladiador
		{
			cin >> nome >> forca >> habilidade >> idade;
			gladiadores[i] = {nome, forca, habilidade, idade, 100};
			i++;
		}
		
		else if(op == 2 && i <= 1)
		{
			cout << "Para batalhar, e necessario o cadastro de dois os mais gladiadores." << endl;
		}
		
		else if(op == 2 && i > 1) // fazer uma batalha entre 2 gladiadores
		{
			cin >> gladiador1 >> gladiador2;		
			if (combate(gladiadores[gladiador1], gladiadores[gladiador2])) {
				cout << gladiadores[gladiador1].nome;
				cout << " ganhou  batalha contra ";
				cout << gladiadores[gladiador2].nome;
				cout << "." << endl;
			} else {
				cout << gladiadores[gladiador2].nome;
				cout << " ganhou  batalha contra ";
				cout << gladiadores[gladiador1].nome;
				cout << "." << endl;
			}
		 }	
		 	
		do {
			cin >> op;
		}while(op < 1 || op > 3);
	}
	return 0;
}
