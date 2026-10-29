/* Soebad Saliv é um cozinheiro renomado e excêntrico. Ele costuma usar espécies exóticas de peixes, pescados na represa de Anatricé em seus preparos. 
Atualmente, o prato que tem feito muito sucesso e garantiu vários prêmios para Soebad é sua torta de jaca e peixe. Com isso, inúmeros turistas passam em
seu restaurante e fazem pedidos online das suas tortas. Ele desenvolveu um sistema de precificação para facilitar a venda das tortas. Sua missão é
ajudá-lo a completar esse sistema! Faça um programa que leia inicialmente a quantidade de tortas T a serem cadastradas no sistema. Depois, o programa
deve ler as características de cada torta T[i] (0 <= i < T), que são números reais representando a espessura da massa (EM), o peso (P), o diâmetro (D) e
a altura (A) da torta. O preço final PF da torta é calculado de acordo com a formula: PF = (EM*P*A+D+A). Insira o código i e o preço final PF de cada
torta T[i] em uma árvore binária de busca e faça uma listagem em ordem crescente do preço. */

#include <iostream>

using namespace std;

// Funções para Árvore Binária de Busca ---------------------------------------

typedef int KeyType;
typedef int ValueType;

struct DataType {
	KeyType key;
	ValueType value;
};

struct Node {
	DataType data;
	Node * right;
	Node * left;
} ;


void insert(Node *& curr, DataType data){	
	if(curr == NULL){
		curr = new Node;
		curr->data = data;
		curr->right = NULL;
		curr->left = NULL;
	} else {
		if(data.key >= curr->data.key){
			insert(curr->right, data);
		} else if(data.key < curr->data.key) {
			insert(curr->left, data);
		}		
	}	
}

Node * search(Node * curr, KeyType key){
	if(curr == NULL)
		return NULL;
	if(key == curr->data.key){
		return curr;
	} else {
		if(key > curr->data.key){
			return search(curr->right, key);
		} else if(key < curr->data.key){
			return search(curr->left, key);
		}
	}
	return NULL;
}

void show_ordered(Node * curr){
	if(curr->left != NULL)
		show_ordered(curr->left);
	cout << curr->data.key << ":" << curr->data.value << endl;
	if(curr->right != NULL)
		show_ordered(curr->right);
}

Node * disconnect_lesser(Node *& curr){
	Node * aux = curr;
	if(aux->left == NULL){ 	
		curr = curr->right; 
		return aux;			
	} else {				
		return disconnect_lesser(curr->left);
	}
}


int remove(Node *& curr, KeyType key){
	if(curr == NULL){
		return 0;
	}
	Node * aux;
	if(curr->data.key == key){
		aux = curr;		
		if(curr->left == NULL){
			curr = aux->right;
		} else if(curr->right == NULL){
			curr = aux->left;
		} else {
			aux = disconnect_lesser(curr->right);
			curr->data = aux->data;
		}		
		delete aux;
		return 1;		
	} else {
		if(key > curr->data.key){
			return remove(curr->right, key);
		} else if(key < curr->data.key) {
			return remove(curr->left, key);
		}
	}
	return 0;
}


void destruct(Node *& curr){
	if(curr->left != NULL)
		destruct(curr->left);
	if(curr->right != NULL)
	   	destruct(curr->right);
	delete curr;
	curr = NULL;
	return;
}