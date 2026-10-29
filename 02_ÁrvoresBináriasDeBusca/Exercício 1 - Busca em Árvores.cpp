/* Faça um programa que leia N números inteiros e os insira em uma árvore binária.
Depois o programa deve ler um outro número X e verificar se o mesmo está ou não na árvore*/

#include<iostream>
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

  node * root = NULL;
  int N;
  int x;
  int procurar;
  
  do{
	  cin >> N;
  }while(N < 0 || N > 100);
  
  for(int i = 0; i < N; i++) {
  	cin >> x;
	insert(root, x);
  }  

  cin >> procurar;
  
  node * result = search(root, procurar);
  if (result != NULL) {
    cout << "Encontrado" << endl;
  } else {
    cout << "Nao encontrado" << endl;
  }
  
  return 0;
}