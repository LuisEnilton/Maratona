#include <bits/stdc++.h>
using namespace std;

#define ALL(x) x.begin(), x.end()
const int MAXN = 1e6 + 5;


/*DSU*/ int pai[MAXN], sz[MAXN]; inline int find(int u); inline void join(int u, int v); inline void resetDSU();

struct Aresta{ int u, v, c; };
bool compAresta(Aresta a, Aresta b){ return a.c < b.c; }

vector<Aresta> arestas; 			//Lista de Arestas



int kruskal(){
	sort(ALL(arestas), compAresta);	//Ordena pelo custo

	int resp = 0;					//Custo total da MST

	for(auto a : arestas)
		if( find(a.u) != find(a.v) )
		{
			resp += a.c;
			join(a.u, a.v);
		}

	return resp;
}




int main(){
	cout << "Kruskal - Minimum Spanning Tree" << endl;
	return 0;	
}