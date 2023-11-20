//
// Created by Luis on 16/11/2023.
//
//
// Created by luise on 16/11/2023.
//
//Template By eduardocesb
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <cmath>

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

int dx[8] = {2, 1, -1, -2, -2, -1, 1, 2};
int dy[8] = {-1, -2, -2, -1, 1, 2, 2, 1};
vector<vi> grid(8,vi(8,INF));
pii dest;

bool check(int y , int x){
    if(y < 0 || x < 0 || y>=8|| x>=8) return false;
    return true;
}

void bfs(pii o){
    queue<pii> fila;
    fila.push(o);
    grid[o.first][o.second] = 0;
    while(!fila.empty()){
        auto [y,x] = fila.front();
        fila.pop();
        for(int i = 0 ; i < 8;i++){
            int _y = y + dy[i];
            int _x = x + dx[i];
            if(check(_y,_x)){
                if(grid[_y][_x] > grid[y][x] + 1){
                    fila.push({_y,_x});
                    grid[_y][_x] = grid[y][x] + 1;
                }
            }
        }
    }
}

int main() {
    optimize;
    int t; cin >> t;
    pii o;
    while(t--){
        fill(ALL(grid),vi(8,INF));
        char x; cin >> x;
        int y; cin >> y;
        o = {y-1,x - 'a'};
        cin >> x;
        cin >> y;
        dest = {y-1,x - 'a'};
        bfs(o);
        cout << grid[dest.first][dest.second] <<endl;
    }
    return 0;
}

