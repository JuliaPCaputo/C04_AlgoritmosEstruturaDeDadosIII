/* Contexto: Imagine que você está criando um sistema para ajudar árbitros a decidir se dois jogadores de futebol se cruzaram durante uma jogada.
Você precisa determinar se duas linhas no campo se cruzam.
Entradas: Cada linha é definida por quatro inteiros x1, y1, x2, y2 (-1000 <= x1, y1, x2, y2 <= 1000).
Saídas: "SIM" se as linhas se cruzam, "NAO" se não. */

#include <iostream>
using namespace std; 

struct Ponto{
    int x, y;
};

struct segmento{
    Ponto a;
    Ponto b;
};

// Função de orientação: usa determinante (mesmo conceito da área)
//Remove a divisão por 2 da area do triangulo o que faz a formula ser o calculo do paralelogramo!
//Isso se da por que nossa intensão neste código é determinar o sentido através do sinal do determinante!
int orientacao(Ponto a, Ponto b, Ponto c) {
    int det = (a.x*b.y - a.y*b.x + a.y*c.x - a.x*c.y + b.x*c.y - b.y*c.x);

    if (det > 0) return 1;   // anti-horário
    if (det < 0) return -1;  // horário
    return 0;                // colinear
}

// Testa se valor X está dentro do intervalo [a, b]
/*
Caso especial: os três pontos são colineares: Se eles estão colineares, isso não significa 
automaticamente que há interseção. É preciso testar se o ponto C está realmente SOBRE o segmento 
AB, e não apenas na reta infinita. Por isso a necessidade de verificar se X está entre a e b.
*/
bool entreAB(int a, int b, int x) {
    return min(a, b) <= x && x <= max(a, b);
}

// Testa se ponto c está no segmento ab (quando são colineares)
bool pontoNoSegmento(Ponto a, Ponto b, Ponto c) {
    return entreAB(a.x, b.x, c.x) && entreAB(a.y, b.y, c.y);
}

// Função principal: verifica interseção de segmentos AB e CD
bool intersecta(Ponto a, Ponto b, Ponto c, Ponto d) {

    int o1 = orientacao(a, b, c);
    int o2 = orientacao(a, b, d);
    int o3 = orientacao(c, d, a);
    int o4 = orientacao(c, d, b);

    // Caso geral
    if (o1 != o2 && o3 != o4)
        return true;

    // Casos colineares
    if (o1 == 0 && pontoNoSegmento(a, b, c)) return true;
    if (o2 == 0 && pontoNoSegmento(a, b, d)) return true;
    if (o3 == 0 && pontoNoSegmento(c, d, a)) return true;
    if (o4 == 0 && pontoNoSegmento(c, d, b)) return true;

    return false;
}

int main(){
    
    segmento s1, s2;
    
     // Leitura dos dois segmentos
    cin >> s1.a.x >> s1.a.y >> s1.b.x >> s1.b.y;
    cin >> s2.a.x >> s2.a.y >> s2.b.x >> s2.b.y;
    
    if(intersecta(s1.a, s1.b, s2.a, s2.b))
        cout << "SIM" << endl;
    else
        cout << "NAO" << endl;
    
    return 0;
}