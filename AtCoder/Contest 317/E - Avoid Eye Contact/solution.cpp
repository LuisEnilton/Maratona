//
// Created by Luis on 26/08/2023.
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
#define MAXN 2002
#define MAXL 23
#define EPS 1e-9
#define endl '\n'

using namespace std;
using namespace __gnu_pbds;

#define ordered_set tree<os_type, null_type,less<os_type>, rb_tree_tag,tree_order_statistics_node_update>

int dx[] = {0, 1, 0, -1};
int dy[] = {-1, 0, 1, 0};
//cima direita baixo esquerda
int h ,w;
char grid[MAXN][MAXN];
map<pair<int,int>,char> obs;

bool check2(char c){
    if(c == '#' || c =='>' || c =='^' || c == 'v' || c == '<'){
        return true;
    }
    return false;
}
void obstruir(char dir,pii coord){
    int y = coord.first;
    int x = coord.second;
    if(dir == '>'){
        while(x < w ){
            if(check2(grid[y][x]) && pair{y,x} != coord) return;
            grid[y][x] = '#';
            x++;
        }
    }
    if(dir == 'v'){
        while(y < h ){
            if(check2(grid[y][x]) && pair{y,x} != coord ) return;
            grid[y][x] = '#';
            y++;
        }
    }

    if(dir == '<'){
        while(x >= 0  ){
            if(check2(grid[y][x]) && pair{y,x} != coord) return;
            grid[y][x] = '#';
            x--;
        }
    }

    if(dir == '^'){
        while(y > 0 ){
            if(check2(grid[y][x]) && pair{y,x} != coord) return;
            grid[y][x] = '#';
            y--;
        }
    }
}
bool check(int x, int y) {
    if (x < 0 || x >= w || y < 0 || y >= h) {
        return false;
    }
    if(grid[x][y] == '#') return false;
    return true;
}

vii vizinhos(pii u){
    vii vizi;
    for (int i = 0; i < 4; i++) {
        int xx = dx[i];
        int yy = dy[i];
        if (check(u.first + yy, u.second + xx)) {
            vizi.PB({u.first + yy, u.second + xx});
        }

    }
    return vizi;
}

map<pii,int> dijkstra(pii origem) {
    //fila.top () = (distancia, vertice)
    priority_queue<pair<int,pii>, vector<pair<int,pii> >, greater<pair<int,pii>>> fila;

    map<pii,int> distancias;

    distancias[origem] = 0;

    fila.emplace(0, origem);

    map<pii,bool> visitados;

    while (!fila.empty()) {
        auto [dist, atual] = fila.top();

        fila.pop();

        if (visitados.count(atual) == 1) continue;

        visitados[atual] = true;

        for (auto vizinho: vizinhos(atual)) {
            if (distancias.count(vizinho) == 0) {
                if(distancias[vizinho] > dist +1){
                    distancias[vizinho] = dist + 1;
                    fila.emplace(distancias[vizinho], vizinho);
                }
            }
        }
    }
    return distancias;

}

int main(int argc, char** argv)
{
    optimize;

    cin >> h >> w;
    pii origem,final;
    for(int i =0;i < h ;i++){
        for(int j =0;j < w;j++){
            char c; cin >> c;
            grid[i][j] = c;
            if(c == '^' || c == 'v' || c == '>' || c == '<')
                obs[{i,j}] = c;
            if(c =='S') origem = {i,j};
            if(c == 'G') final = {i,j};
        }
    }
    for(auto x : obs){
        obstruir(x.second,x.first);
    }
    auto dist = dijkstra(origem);
    if(dist.count(final) == 0) cout << -1 << endl;
    else cout << dist[final] << endl;

    return 0;
}

