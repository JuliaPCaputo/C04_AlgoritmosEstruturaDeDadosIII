/* No reino de Dataland, os dados são organizados em estruturas mágicas chamadas Árvores Binárias de Busca (BST). Você, um mago dos dados, recebeu uma
tarefa especial: gerenciar essas árvores, inserindo, removendo e verificando a presença de elementos. Você precisa garantir que os elementos possam ser
adicionados e removidos eficientemente e que, após a remoção, eles realmente desapareçam da árvore. Este exercício simulará estas operações para testar
suas habilidades de manipulação da BST.
Entradas
Número de Operações (N): O primeiro número inteiro na entrada (1 = N = 100) indica quantas operações serão realizadas.
Operações: Cada uma das próximas N linhas descreve uma operação e pode ser de três tipos:
i x: Insere o inteiro x na árvore binária (onde -10^9 = x = 10^9).
r x: Remove o inteiro x da árvore binária.
b x: Busca o inteiro x na árvore binária e retorna se o elemento ainda está presente ou não.
Saída
Para cada operação de busca (b x), imprima "Sim" se o elemento x ainda está presente na árvore após as operações de inserção e remoção, e "Não" se o
elemento foi removido com sucesso e não está mais presente. */

#include <iostream>
#include <cstring>
#include <list>
using namespace std;

struct treenode{
  int info;
  struct treenode * left;
  struct treenode * right;
};

void tInsert(treenode* &p, int x){
    if(p == NULL){
        p = new treenode;
        p -> info = x;
        p -> left = NULL;
        p -> right = NULL;
    }else if(x < p -> info){
        tInsert(p -> left, x);
    }else{ 
        tInsert(p -> right, x);
    }
}

treenode* tSearch(treenode* p, int x){
    if(p == NULL){
        return NULL;
    }else if(x == p -> info){
        return p;
    }else{
        if(x < p-> info)
            return tSearch(p -> left, x);
        else
            return tSearch(p -> right, x);
    }
}

//Algoritimo de Remoção
treenode* tPointSmaller(treenode* &p){
    treenode* t = p;
    if(p -> left == NULL){
        p = p -> right;
        return t;
    }else
        return tPointSmaller(p -> left);
}

bool tRemove(treenode* &p, int x){
    treenode* t;
    if(p == NULL) return false;
    if(x == p -> info){
        t = p;
        if(p -> left == NULL)
            p = p -> right;
        else if(p -> right == NULL)
            p = p -> left;
        else{
            t = tPointSmaller(p -> right);
            p -> info = t -> info;
        }
        delete t;
        return true;
    }else if(x < p -> info)
        return tRemove(p -> left, x);
    else
        return tRemove(p -> right, x);
}

int main (){
    
    treenode* arvore = NULL; //arvore vazia 
    int n, valor;
    char op;
    
    do{
        cin >> n;
    }while(n < 1 || n > 100);
    
    
    for(int i = 0; i < n; i++){
        cin >> op >> valor;
        
        switch(op){
            case 'i': 
                tInsert(arvore, valor);
                break;
            case 'r':
                tRemove(arvore, valor);
                break;
            case 'b':
                if(tSearch(arvore, valor) != NULL)
                    cout << "Sim" << endl;
                else
                    cout << "Não" << endl;
                    
                break;
        }
    }
    
    return 0;
}