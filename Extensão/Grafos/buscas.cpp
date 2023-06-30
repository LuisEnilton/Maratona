#include <bits/stdc++.h>
using namespace std;
vector<int> adj[6]; //Para armazenar o grafo. Por que o tamanho 6 se o grafo tem 5 nós?
//Poderia ser de tamanho 5, mas teríamos que lidar que
//o nó 1 corresponde ao índice 0, o 2, ao índice 1...
// Para facilitar, foi colocado o tamanho 6, assim:
//o nó 1 corresponde ao índice 1, o 2, ao índice 2... e o 1ª elemento do vetor, o que
//correspoderia ao índice 0, ficou sem nada. (um pouquinho de desperdício de espaço ;)


array<bool,6> visited; //controle dos nós visitados 
//poderia ser, como no slide, bool int[6] visited;
//mas quis usar o método fill para "limpar" entre as chamadas das funções
//dfs e bfs

int dist[6]; //o nome distance, usado no slide da bfs, tinha ambiguidade, por isso usei dist    
//Na bfs, serve para armazenar as distancias de cada nó ao nó inicial.

queue<int> q; //fila usada na bfs para indicar a ordem dos nós que terão seus adjacentes analisados 

void dfs(int s){ //busca em profundidade 
    if (visited[s]) return;
    visited[s] = true;

    cout<< s << " " << endl; //Optei por apenas imprimir o nó visitado,
    //mas, dependendo do problema, poderíamos processá-lo de outra forma.

    for (auto u: adj[s]){ //para cada nó adjacente a s
        dfs(u);
    }
}

void bfs(int x){ //busca em largura 
    visited[x] = true;
    dist[x] = 0;
    cout<< x << " distacia: " << dist[x] << endl; //AQUI APENAS O NÓ INICIAL

    q.push(x);
    while (!q.empty()){ //para cada elemento s da fila
        int s = q.front(); q.pop();
        for (auto u: adj[s]){ //para cada nó adjacente a s
            if (visited[u]) continue;
            visited[u] = true;
            dist[u] = dist[s] + 1;
            cout<< u << " distancia: " << dist[u] << endl; //DEMAIS NÓS!
            q.push(u);
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    adj[1].push_back(2); //grafo não-direcionado com 5 nós, o mesmo do slide 8
    adj[1].push_back(4);
    adj[2].push_back(1);
    adj[2].push_back(3);
    adj[2].push_back(5);
    adj[3].push_back(2);
    adj[3].push_back(5);
    adj[5].push_back(2);
    adj[5].push_back(3);
    cout<<"DFS"<< endl;
    dfs(1);
    visited.fill(false);
    cout<<endl;
    cout<<"BFS"<< endl;
    bfs(1);
    cout<<endl;
    return 0;
}