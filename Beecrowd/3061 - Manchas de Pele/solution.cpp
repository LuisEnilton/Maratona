//
// Created by luise on 05/07/2023.
//
//
// Created by luise on 04/07/2023.
//
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <string>
#include <algorithm>
#include <set>

#define optimize                 \
    ios::sync_with_stdio(false); \
    cin.tie(NULL);               \
    cout.tie(NULL)
#define INF 100000010
#define ALL(x) x.begin(), x.end()
#define UNIQUE(c) (c).resize(unique(ALL(c)) - (c).begin())
#define REP(i, a, b) for (int i = (a); i <= (b); i++)
#define POS(n, x) (lower_bound(ALL(n), x) - (n).begin())
#define ll long long
#define ld long double
#define pii pair<int, int>
#define vi vector<int>
#define vii vector<pii>
#define os_type int
#define PB push_back
#define EB emplace_back
#define MOD 1000000007
#define PRIME 101
#define MAXN 1010
#define MAXL 23
#define endl '\n'
#define ordered_set tree<os_type, null_type, less<os_type>, rb_tree_tag, tree_order_statistics_node_update>

using namespace std;
using namespace __gnu_pbds;

int dx[] = {0, 1, 0, -1};
int dy[] = {-1, 0, 1, 0};
//cima direita baixo esquerda


int N, M;

int pixels[MAXN][MAXN];
int cont = 0;

bool check(int x, int y) {
    if (x < 0 || x >= N || y < 0 || y >= M) {
        return false;
    }
    return true;
}


void dfs(pii origem) {
    cont++;
    queue<pii > fila;

    fila.push(origem);
    while (!fila.empty()) {
        pii atual = fila.front();

        fila.pop();
        if (pixels[atual.first][atual.second] == 0) continue;

        pixels[atual.first][atual.second] = 0;

        for (int i = 0; i < 4; i++) {
            int xx = dx[i];
            int yy = dy[i];
            if (check(atual.first + yy, atual.second + xx)) {
                fila.push({atual.first + yy, atual.second + xx});
            }

        }
    }
}


int solve() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (pixels[i][j] == 1) {
                dfs({i, j});
            }
        }
    }
}

int main() {
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            int c;
            cin >> c;
            pixels[i][j] = c;
        }
    }
    solve();
    cout << cont << endl;


    return 0;
}