/* Você está trabalhando em uma nova rede de streaming, e para organizar os filmes na plataforma, decidiu utilizar uma árvore binária de busca ordenada
pelos nomes dos filmes. Faça um programa que insira o nome, gênero, duração em minutos, classificação de idade e ano de cada filme na árvore, e que, dado
o nome de um determinado filme, faça uma pesquisa e mostre as informações do mesmo. */

#include <iostream>
#include <string>
using namespace std;

struct filme {
	string nomeFilme;
	string genero;
	int duracao;
	int classificacao;
	int ano;
};

struct node {
	filme data;
	node *left;
	node *right;
};

void insert(node * &curr, const filme &info) {
    if (curr == NULL) {
        curr = new node;
        curr->data = info;
        curr->left = NULL;
        curr->right = NULL;
    } 
    else if (info.nomeFilme < curr->data.nomeFilme) {
        insert(curr->left, info);
    }
    else {
        insert(curr->right, info);
	}
}

node *search(node *curr, const string &nome) {
    if (curr == NULL) {
		return NULL;
	}
    else if (nome == curr->data.nomeFilme) {
		return curr;
	}
    else if (nome < curr->data.nomeFilme) {
		return search(curr->left, nome);
	}
    else {
		return search(curr->right, nome);
	}
}

int main() {
	node * root = NULL;
	filme info;
	int op;
	string nomeBusca;
	
	do{
		cin >> op;

		switch (op){
			case 0:
				break;
			case 1: {
				cin >> info.nomeFilme;
				cin >> info.genero;
				cin >> info.duracao;
				cin >> info.classificacao;
				cin >> info.ano;
				insert(root, info);
				break;
			}
			case 2: {
				node * result = search(root, nomeBusca);
				if (result != NULL) {
					cout << "Nome: " << result->data.nomeFilme << endl;
	    			cout << "Genero: " << result->data.genero << endl;
	                cout << "Duracao: " << result->data.duracao << " mins";
	                cout << "Classificacao: " << result->data.classificacao << endl;
	                cout << "Ano: " << result->data.ano << endl;
				} else {
					cout << "Filme nao encontrado" << endl;
				}	
				break;
			}
			default: {
				cout << "Operacao invalida" << endl;
				break;
			}
		}
	} while(op != 0);
	
	return 0;
}