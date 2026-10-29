/* Sua amiga Isabela anda muito atarefada ultimamente com seu novo emprego como geóloga, e quer uma forma mais eficiente de organizar os nomes e
classificações de suas amostras de rochas. Para ajudá-la, você decidiu fazer um programa que utiliza de uma árvore binária de busca, que guardará o nome
e tipo de cada amostra, ordenando-a por seus nomes. O programa deve permitir que Isabela insira novas amostras na árvore; pesquise uma amostra pelo seu
nome, mostrando todas as suas informações como resultado da pesquisa; e remova as amostras que foram descartadas, dados o nome e o tipo da rocha.
Entrada
A entrada terá 4 opções: 1 para inserir, 2 para pesquisar, 3 remover e 0 para terminar o programa. Na inserção serão informados o nome e o tipo da rocha,
para a pesquisa, apenas o nome será dado, e para a remoção o nome e o tipo da pedra devem estar de acordo com as informações contidas na árvore.
Saída
Quando uma pedra for pesquisada, mostre seu nome e tipo se for encontrada, senão, mostre a mensagem "Rocha nao encontrada". Ao remover uma pedra, informe
se ela foi removida com sucesso ou não. Adicionalmente, se um usuário entrar com uma opção que não seja uma das quatro anteriores, mostre a mensagem
"Operação inválida".
 */

# define MAXP 100 //maximo de rochas
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
    
    treenode* arvore = NULL;
    int op = -1;
    string nome[MAXP], tipo[MAXP];
    int total = 0; // total de pedras

    cin >> op; 
    cin.ignore();
    
    while(op != 0){
        switch(op){
            case 1: {
                getline(cin, nome[total]);
                getline(cin, tipo[total]);
                total++;
                tInsert(arvore, total);
                break;
            }
            case 2: {
                string nomeBusca; 
                getline(cin, nomeBusca);
                
                bool encontrado = false;
                
                for(int i = 0; i < total; i++){
                    if(nome[i] == nomeBusca){
                        cout << "Nome: " << nome [i] << endl;
                        cout << "Tipo: " << tipo[i] << endl;
                        encontrado = true;
                        
                        break;
                     }
                }
                
                if(!encontrado)
                    cout << "Rocha nao encontrada" << endl;
                    
                break;
            }
                
            case 3: {
                string nomeRemove, tipoRemove;
                getline(cin, nomeRemove);
                getline(cin, tipoRemove);
                
                bool encontrado = false;
                int aux = -1;
                
                // procurar índice
                for (int i = 0; i < total; i++) {
                    if (nome[i] == nomeRemove && tipo[i] == tipoRemove) {
                        aux = i + 1; // ID começa em 1
                        encontrado = true;
                        break;
                    }
                }

                if (!encontrado) {
                    cout << "Rocha nao encontrada para remocao" << endl;
                    break;
                }
                
                bool ok = tRemove(arvore, aux);
                
                if(ok){
                    cout << "Rocha removida com sucesso" << endl;
                    
                    // remover do vetor
                    for (int j = aux - 1; j < total - 1; j++) {
                        nome[j] = nome[j + 1];
                        tipo[j] = tipo[j + 1];
                    }
                    total--;
                } else {
                    cout << "Rocha nao encontrada para remocao" << endl;
                }
                
                break;
            }
            
            default: 
                cout << "Rocha nao encontrada" << endl;
                break;
        }
        
        cin >> op; 
        cin.ignore();
    }
    
    return 0;
}