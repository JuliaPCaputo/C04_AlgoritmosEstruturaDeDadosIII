/* Contexto: Um arquiteto precisa calcular a área de um triângulo para determinar o espaço disponível para a construção de um novo prédio.
Entradas: Três pares de inteiros x1, y1, x2, y2, x3, y3 (-100 <= x, y <= 100).
Saídas: Um número decimal representando a área do triângulo. */

#include <iostream>
using namespace std; 

struct Ponto{
    int x, y;
};

float areaTriangulo(Ponto a, Ponto b, Ponto c){
    float area = (a.x*b.y - a.y*b.x + a.y*c.x - a.x*c.y + b.x*c.y - b.y*c.x)/2.0;
    
    //Para retornar a area sempre positiva podemos usar o fabs(area) e incluir <cmath>
    return area;
}

int main(){
    Ponto p1, p2, p3;
    
    cin >> p1.x >> p1.y;
    cin >> p2.x >> p2.y; 
    cin >> p3.x >> p3.y;
    
    float area = areaTriangulo(p1, p2, p3);
    
    cout << area << endl;
    
    return 0;
}