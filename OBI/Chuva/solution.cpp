//
// Created by Luis on 18/11/2023.
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
const int maxn = 503;
char grid[maxn][maxn];
int n, m;
int dx[3] = {0, -1, 1};
int dy[3] = {1, 0, 0};

bool check(int y, int x) {
    if (x < 0 || x >= m || y < 0 || y >= n) return false;
    if (grid[y][x] == '#' || grid[y][x] == 'o') return false;
    return true;
}

void bfs(pii o) {
    queue<pii > fila;
    fila.push(o);
    while (!fila.empty()) {
        auto [y, x] = fila.front();
        fila.pop();
        grid[y][x] = 'o';
        if (y == n - 1) continue;
        bool ok = false;
        for (int i = 0; i < 3 && !ok; i++) {
            int _y = y + dy[i];
            int _x = x + dx[i];
            if (check(_y, _x)) {
                if (i == 0) ok = true;
                fila.push({_y, _x});
            }
        }

    }
}

int main() {
    optimize;
    cin >> n >> m;
    pii o;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
            if (grid[i][j] == 'o') o = {i, j};
        }
    }
    bfs(o);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << grid[i][j] ;
        }
        cout << endl;
    }
    return 0;
}

