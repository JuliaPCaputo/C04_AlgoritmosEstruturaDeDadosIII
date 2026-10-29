#include <iostream>
#include <cmath>
#include <stack>
#include <stdlib.h> // Para o qsort
#include <iomanip>

using namespace std;

struct Point {
	int x, y;
};

Point p0;

// Função utilitária para retornar o segundo elemento do topo sem remover
Point nextToTop(stack<Point> &S)
{
    Point p = S.top();
    S.pop();
    Point res = S.top();
    S.push(p);
    return res;
}
 
// A utility function to swap two points
void swap(Point &p1, Point &p2)
{
    Point temp = p1;
    p1 = p2;
    p2 = temp;
}
 
// A utility function to return square of distance between p1 and p2
// Para o perímetro, precisa colocar na raíz
int distSq(Point p1, Point p2)
{
    return (p1.x - p2.x)*(p1.x - p2.x) +
           (p1.y - p2.y)*(p1.y - p2.y);
}
 
// To find orientation of ordered triplet (p, q, r).
// The function returns following values
// 0 --> p, q and r are collinear
// 1 --> Clockwise
// 2 --> Counterclockwise
int orientation(Point p, Point q, Point r)
{
    int val = (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y);
 
    if (val == 0) return 0;  // collinear
    return (val > 0)? 1: 2; // 1 = clockwise, 2 = counterclockwise
}
 
// A function used by library function qsort() to sort an array of
// points with respect to the first point
int compare(const void *vp1, const void *vp2)
{
   Point *p1 = (Point *)vp1;
   Point *p2 = (Point *)vp2;
 
   // Find orientation
   int o = orientation(p0, *p1, *p2);
   if (o == 0)
     // Se for colinear, o ponto mais distante de p0 vem primeiro (-1)
     return (distSq(p0, *p2) >= distSq(p0, *p1))? -1 : 1;
 
   // Se for anti-horário, p1 vem antes de p2 (-1)
   return (o == 2)? -1: 1;
}
 
// Prints convex hull of a set of n points.
float grahan_scan(Point points[], int n)
{
    if (n <= 2) {
        // Fecho convexo trivial para 0, 1 ou 2 pontos.
        // O perímetro é 0 para 0 ou 1 ponto, ou a distância de p1 a p2 para 2 pontos.
        if (n == 2) {
            return sqrt((float)distSq(points[0], points[1]));
        }
        return 0.0f;
    }

    // Find the bottommost point
    int ymin = points[0].y, min = 0;
    for (int i = 1; i < n; i++)
    {
        int y = points[i].y;
        
        // Pick the bottom-most or choose the left most point in case of tie
        if ((y < ymin) || (ymin == y && points[i].x < points[min].x)) {
            ymin = points[i].y, min = i;
        }
    }
 
     // Place the bottom-most point at first position
    swap(points[0], points[min]);
 
    /* Sort n-1 points with respect to the first point.
	A point p1 comes before p2 in sorted output if p2 has
	larger polar angle (in counterclockwise direction)
	than p1 */
    p0 = points[0];
    qsort(&points[1], n-1, sizeof(Point), compare);
 
    /* If two or more points make same angle with p0,
	remove all but the one that is farthest from p0
	Remember that, in above sorting, our criteria was
	to keep the farthest point at the end when more than
	one points have same angle. */
    int m = 1; // Initialize size of modified array
    for (int i=1; i<n; i++)
    {
        /* Keep removing i while angle of i and i+1 is same
			with respect to p0(já que o qsort garantiu que o mais distante está no final) */
        while (i < n-1 && orientation(p0, points[i], points[i+1]) == 0)
            i++;
 
        points[m] = points[i];
        m++;  // Update size of modified array
    }
 
    // If modified array of points has less than 3 points,
   // convex hull is not possible
    if (m < 3) return 0.0f;
 
    // Create an empty stack and push first three points to it.
    stack<Point> S;
    S.push(points[0]);
    S.push(points[1]);
    S.push(points[2]);
    
    // Process remaining n-3 points
    for (int i = 3; i < m; i++)
    {
        /* Keep removing top while the angle formed by
		points next-to-top, top, and points[i] makes
		a non-left turn */
        while (S.size()>1 && orientation(nextToTop(S), S.top(), points[i]) != 2)
           S.pop();
        S.push(points[i]);
    }

    // Calcula o perímetro a partir da pilha final
    float perimeter = 0.0f;
    int hull_size = S.size();
    
    // Transfere os pontos da pilha para um array (a pilha será esvaziada)
    Point hull_points[50];
    for (int i = hull_size - 1; i >= 0; i--) {
        hull_points[i] = S.top();
        S.pop();
    }
    // hull_points agora contém os pontos na ordem correta (p0, p1, ..., pk)

    for (int j = 0; j < hull_size; j++) {
        // Ponto atual
        Point p1 = hull_points[j];
        
        // Ponto seguinte, usando módulo % hull_size para fechar o ciclo
        // (o último ponto conecta-se ao primeiro)
        Point p2 = hull_points[(j + 1) % hull_size]; 
        
        // Soma a raiz quadrada da distância ao quadrado
        perimeter += sqrt((float)distSq(p1, p2));
    }

    return perimeter;
}

int main(){
	Point points[50]; // Suporta até 50 árvores por reserva
	float total_material = 0.0f;
	int n, r; // n = número de árvores, r = número de reservas
	
	cout << fixed << setprecision(4);
	
	cin >> r;
	
	for(int j = 0; j < r; j++) {
		cin >> n;

		// Leitura das coordenadas das árvores
		for(int i = 0; i < n; i++) {
			cin >> points[i].x >> points[i].y;
		}
		
		// Calcula o perímetro do fecho convexo para a reserva e soma ao total
		total_material += grahan_scan(points, n);
	}
	
	cout << total_material << endl;
	
	return 0;
}