//
// Created by luise on 27/08/2023.
//
//Template By eduardocesb
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define optimize ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define INF 1000000010
#define INFLL 1000000000000000010LL
#define ALL(x) x.begin(), x.end()
#define UNIQUE(c) (c).resize(unique(ALL(c)) - (c).begin())
#define REP(i, a, b) for(int i = (a); i <= (b); i++)
#define POS(n, x) (lower_bound(ALL(n), x) - (n).begin())
#define ll long long
#define ld long double
#define pii pair<int,int>
#define vi vector<int>
#define vii vector<pii>
#define os_type int
#define PB push_back
#define EB emplace_back
#define MOD 1000000007
#define PRIME 101
#define MAXN 1010101
#define MAXL 23
#define EPS 1e-9
#define endl '\n'

using namespace std;
using namespace __gnu_pbds;

#define ordered_set tree<os_type, null_type,less<os_type>, rb_tree_tag,tree_order_statistics_node_update>
/*
 Geometria:
 Para representar um ponto no plano, podemos usar a estrutura pair<int,int> ou a struct Point.
    Para representar um vetor no plano, podemos usar a estrutura pair<int,int> ou a struct Vector.
    Para representar uma reta no plano, podemos usar a estrutura pair<int,int> ou a struct Line.
    Outra forma de representar a reta pair<pair<int,int>,int> , para representar o numerador e denominador do a.
    Para representar um segmento de reta, podemos usar a estrutura pair<pair<int,int>,pair<int,int>> ou a struct Segment.
    Para representar um polígono, podemos usar a estrutura vector<pair<int,int>> ou a struct Polygon.

 */
#define x first
#define y second
#define a_num first.first
#define a_den first.second
#define b second
typedef pair<int,int> Point;
typedef pair<pair<int,int>,int> Line;
typedef pair<int,int> Vector;
typedef pair<pair<int,int>,pair<int,int>> Segment;
typedef vector<Point> Polygon;


//Distância entre dois pontos
double distance(Point a, Point b){
    return sqrt((a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y));
}

//Produto interno entre dois pontos
int dot_product(Point a, Point b){
    return a.x*b.x + a.y*b.y;
}

//norma de a
double norm(Point a){
    return dot_product(a,a);
}

//comprimento de a
double length(Point a){
    return sqrt(norm(a));
}

// retorna o angulo entre a e b em radianos
double angle(Point a, Point b){
    return acos(dot_product(a,b)/(length(a)*length(b)));
}

//angulo entre a e b em radianos , tomando c como origem
double angle(Point a, Point b, Point c){
    return angle({a.x - c.x, a.y - c.y},{b.x - c.x, b.y - c.y});
}

//produto vetorial entre dois pontos
int cross_product(Point a, Point b){
    return a.x*b.y - a.y*b.x;
}

//função que encontra a equação da reta dado dois pontos
Line line_equation(Point a, Point b){
    int A = a.second - b.second;
    int B = b.first - a.first;
    int C = A*a.first + B*a.second;
    return {{A,B},C};
}

//calcula o ponto de intersessão entre duas retas
Point intersection_point(Line a, Line b){
    int det = a.first.first*b.first.second - b.first.first*a.first.second;
    int g = (b.first.second*a.second - a.first.second*b.second)/det;
    int h = (a.first.first*b.second - b.first.first*a.second)/det;
    return {g,h};
}


//lei dos cossenos
double cosines_law(double a, double b, double c){
    return acos((a*a + b*b - c*c)/(2*a*b));
}

//distancia do ponto até a reta
double distance_point_line(Point a, Point b, Point c){
    double A = b.second - a.second;
    double B = a.first - b.first;
    double C = A*a.first + B*a.second;
    return abs(A*c.first + B*c.second - C)/sqrt(A*A + B*B);
}

//Calcula a area de um poligono p
double area(Polygon p){
    double area = 0;
    for(int i = 0;i < p.size();i++){
        int j = (i+1)%p.size();
        area += p[i].x*p[j].y - p[j].x*p[i].y;
    }
    return abs(area)/2.0;
}

// testa se o ponto c esta a esquerda da reta ab
int is_left(Point a, Point b, Point c){
    int val = (b.y - a.y)*(c.x - b.x) - (b.x - a.x)*(c.y - b.y);
    if(val == 0) return 0; // colinear
    return (val > 0) ? 1 : -1; // 1 se c esta a esquerda de ab, -1 se esta a direita
}

// checa se o ponto p esta dentro do poligono p
bool is_inside(Polygon p, Point q) {
    int n = p.size();
    for (int i = 0; i < n; i++)
        if (is_left(p[i], p[(i+1)%n], q) == -1)
            return false;
    return true;
}
int main(int argc, char** argv)
{
    optimize;
    return 0;
}

