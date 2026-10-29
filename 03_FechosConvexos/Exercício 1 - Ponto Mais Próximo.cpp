/* Contexto: Um jogo de realidade aumentada precisa identificar o ponto mais próximo de um usuário dentro de um conjunto de pontos de interesse.
Entradas: Primeiro um inteiro N (1 <= N <= 100), seguido por N pares de inteiros x, y (-1000 <= x, y <= 1000) representando os pontos de interesse,
e um par ux, uy representando a posição do usuário.
Saídas: O par de inteiros mais próximo do usuário. Em caso de empate, apresente o ponto com menor x, e se ainda for necessário, desempate com o menor y. */

#include <iostream>
#include <cmath>

using namespace std; 

struct Ponto{
    int x, y;
};

//Função para Calcular a distancia ao Quadrado!
/*Ela calcula a distância ao quadrado entre dois pontos do plano 
cartesiano. Por isso o nome dist2*/

int dist2(Ponto a, Ponto b){
    //X é a largura da projeção horizontal entre os pontos.
    //Y é a altura da projeção vertical entre os pontos.
    
    int dx = a.x - b.x; //delta x - diferença entre as coordenadas x dos dois pontos.
    int dy = a.y - b.y;//delta y - diferença entre as coordenadas y dos dois pontos.
    
    return dx*dx + dy*dy;
}

int main(){
    int n;
    
    do{
        cin >> n;
    }while(n < 1 && n > 100);
    
    Ponto pontos[n]; //criando os pontos na main!
    
    for(int i = 0; i < n; i++){
        cin >> pontos[i].x >> pontos[i].y;
    }
    
    //Pontos de posição do usuario:
    Ponto u;
    
    cin >> u.x >> u.y;
    
    // Começa assumindo que o ponto 0 é o melhor
    Ponto melhor = pontos[0];
    int melhorDist = dist2(melhor, u);
    
    // Verifica os demais
    for(int i = 0; i < n; i++){
        int d = dist2(pontos[i], u);
        
        if(d < melhorDist){
            melhorDist = d;
            melhor = pontos[i];
        }
        else if(d == melhorDist){
            // Desempate: menor x
            if (pontos[i].x < melhor.x ||
               (pontos[i].x == melhor.x && pontos[i].y < melhor.y)) {
                melhor = pontos[i];
            }
        }
    }
    
    cout << melhor.x << " " << melhor.y << endl;
    
    return 0;
}