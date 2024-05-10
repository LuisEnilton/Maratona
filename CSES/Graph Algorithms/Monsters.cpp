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
#define vb vector<bool>
#define vii vector<pii>
#define os_type int
#define PB push_back
#define EB emplace_back
#define MOD 1000000007
#define PRIME 101
#define MAXN 1010
#define MAXL 23
#define EPS 1e-9
#define endl '\n'

using namespace std;
using namespace __gnu_pbds;

#define ordered_set tree<os_type, null_type,less<os_type>, rb_tree_tag,tree_order_statistics_node_update>

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
string dir = "RDLU";
char grid[MAXN][MAXN];
int dist[MAXN][MAXN], dist2[MAXN][MAXN];
queue<pii > fila;
pii o;
int n, m;

bool check(int x, int y) {
    if (x < 0 || x >= m || y < 0 || y >= n) return false;
    return true;
}

map<pii,char> pai;

void reset(){
    for (int i = 0; i < MAXN; i++) {
        for (int j = 0; j < MAXN; j++) {
            dist[i][j] = INF;
            dist2[i][j] = INF;
        }
    }
}

bool bound(pii p){
    auto [y,x] = p;
    if(y == 0 || y == n-1 || x == 0 || x == m-1) return true;
    return false;
}

pii bfs() {
    reset();
    while (!fila.empty()) {
        auto [y, x] = fila.front();
        fila.pop();
        if (grid[y][x] == '#') continue;
        for (int i = 0; i < 4; i++) {
            int _x = x + dx[i], _y = y + dy[i];
            if(check(_x,_y)){
                dist[_y][_x] = min(dist[_y][_x],dist[x][y] + 1);
            }
        }
    }
    reset();
    fila.push(o);
    pai[o] = 'N';
    while (!fila.empty()) {
        auto [y, x] = fila.front();
        fila.pop();
        if (grid[y][x] == '#') continue;
        if(bound({y,x})){
            return {y,x};
        }
        for (int i = 0; i < 4; i++) {
            int _x = x + dx[i], _y = y + dy[i];
            if(check(_x,_y)){
                dist[_y][_x] = min(dist[_y][_x],dist[x][y] + 1);
                pai[{_y,_x}] = dir[i];
            }
        }
    }
    return {-1,-1};

}

int main() {
    optimize;


    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
            if (grid[i][j] == 'M') {
                dist[i][j] = 0;
                fila.push({i, j});
            }
            if (grid[i][j] == 'A') o = {i, j};
        }
    }
    auto ans = bfs();
    if(ans == make_pair(-1,-1)){
        cout << "NO" << endl;
    }else{
        cout << "YES" << endl;
        cout << dist2[ans.first][ans.second] << endl;
        auto aux = ans;
        while(pai[aux] != 'N'){
            cout << pai[aux];

        }
        cout << endl;
    }
    return 0;
}

