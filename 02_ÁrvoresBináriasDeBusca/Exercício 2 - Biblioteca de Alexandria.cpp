/* Imagine que você é um bibliotecário na renomada Biblioteca de Alexandria. Sua tarefa é organizar uma vasta coleção de manuscritos usando uma técnica
antiga, mas incrivelmente eficaz, conhecida como Árvore Binária de Busca (BST). Cada manuscrito é representado por um número único e deve ser facilmente
acessível. Seu desafio é desenvolver um sistema para inserir números de manuscritos na BST de modo que possam ser recuperados rapidamente quando
pesquisados. A eficiência do seu sistema será testada através de uma série de inserções e buscas, refletindo o trabalho diário de catalogar e localizar
manuscritos na biblioteca. */

#include<iostream>
#include <locale>
using namespace std;

struct node {
  int data;
  node *left;
  node *right;
};

void insert(node * & curr, int data) {
  if (curr == NULL) {
    curr = new node;
    curr->data = data;
    curr->left = NULL;
    curr->right = NULL;
  } else if (data < curr->data) {
    insert(curr->left, data);
  } else {
    insert(curr->right, data);
  }
}

node * search(node * curr, int data) {
  if (curr == NULL) {
    return NULL;
  } else if (data == curr->data) {
    return curr;
  } else if (data < curr->data) {
    return search(curr->left, data);
  } else {
    return search(curr->right, data);
  }
}

int main() {
	setlocale(LC_ALL, "Portuguese");
	
	node * root = NULL;
	int N;
	int x;
	char op;
  
	do{
		cin >> N;
	}while(N < 0 || N > 100);
  
	for(int i = 0; i < N; i++) {
		cin >> op;
		if(op == 'i') {
			cin >> x;
			insert(root, x);
		}
		else {
			cin >> x;
			node * result = search(root, x);
			if (result != NULL) {
				cout << "Sim" << endl;
			} else {
			    cout << "Não" << endl;
			}
		}
	}
  
  return 0;
}