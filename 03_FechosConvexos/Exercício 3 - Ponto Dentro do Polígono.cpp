/* Contexto: Um designer de jogos precisa saber se um objeto (representado por um ponto) está dentro de uma área segura (um polígono) no mapa do jogo.
Entradas: Primeiro, um inteiro N (3 <= N <= 100) representando o número de vértices do polígono, seguido por N pares de inteiros x, y (-100 <= x, y <= 100) para os vértices. Em seguida, um par px, py para o ponto.
Saídas: "DENTRO" se o ponto estiver dentro do polígono, "!(DENTRO)" se não. */

#include <iostream>
using namespace std; 

struct Ponto{
    int x, y;
};

//Um poligono pode ser um triangulo
float areaTriangulo(Ponto a, Ponto b, Ponto c){
    float area = (a.x*b.y - a.y*b.x + a.y*c.x - a.x*c.y + b.x*c.y - b.y*c.x)/2.0;
    
    //Para retornar a area sempre positiva podemos usar o fabs(area) e incluir <cmath>
    return area;
}

int main(){
    int n;
    
    do{
        cin >> n;
    }while(n < 3 ||n > 100);
    
    Ponto vertices[100];
    
    for(int i = 0; i < n; i++){
        cin >> vertices[i].x >> vertices[i].y;
    }
    
    //Leitura do par px e py para o ponto que desejo encontrar
    Ponto p;
    cin >> p.x >> p.y;
    
    //Triangualação em Fan (leque)
    /*Ele escolhe o primeiro vértice (vertices[0]) como ponto fixo e forma 
    triângulos assim: 
    v0, v1, v2
    v0, v2, v3
    v0, v3, v4...
    v0, v(N-2), v(N-1)*/
    
    float areaTotal = 0;
    for(int i = 1; i < n - 1; i++){
        areaTotal += areaTriangulo(vertices[0], vertices[i], vertices[i + 1]);
    }
    
    //Soma das áreas formadas pelo ponto
    float somaAreas = 0;
    for (int i = 0; i < n; i++) {
        somaAreas += areaTriangulo(p, vertices[i], vertices[(i + 1) % n]);
    }
    
    if ((somaAreas - areaTotal) < 0.0001)
        cout << "DENTRO" << endl;
    else
        cout << "!(DENTRO)" << endl;
    
    return 0;
}