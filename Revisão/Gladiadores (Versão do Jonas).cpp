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
	int forca, habilidade, idade, tamanho=2, gladiador1, gladiador2;
	Gladiador gladiadores[1000];

	for (int i=0; i<tamanho; i++) {
		cin >> nome >> forca >> habilidade >> idade;
		gladiadores[i] = {nome, forca, habilidade, idade, 100};
	}

	while (cin >> gladiador1 >> gladiador2 && gladiador1 != -1 && gladiador2 != -1) {
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
	return 0;
}
