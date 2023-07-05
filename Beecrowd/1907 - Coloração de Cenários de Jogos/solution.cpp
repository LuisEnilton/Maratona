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
#define MAXN 110010
#define MAXL 23
#define endl '\n'

using namespace std;
using namespace __gnu_pbds;

#define ordered_set tree<os_type, null_type, less<os_type>, rb_tree_tag, tree_order_statistics_node_update>
using namespace std;
int N, M;

vector<char> pixels(MAXN);
int cont = 0;

vector<int> vizinhos(int origem) {
    vector<int> vizinhos;
    if (origem / M != 0) {
        if (pixels[origem] == '.')
            vizinhos.emplace_back(origem - M);//cima
    }

    if (origem % M != 1) {
        if (pixels[origem] == '.')
            vizinhos.EB(origem - 1);//esquerda
    }
    if (origem / M < N - 1) {
        if (pixels[origem] == '.')
            vizinhos.emplace_back(origem+M);//baixo
    }
    if (origem % M != 0) {
        if (pixels[origem] == '.')
            vizinhos.EB(origem + 1);//direita
    }
    return vizinhos;
}


void dfs(int origem, vector<bool> &visitados) {
    cont++;
    queue<int> fila;

    fila.push(origem);


    while (!fila.empty()) {
        int atual = fila.front();

        fila.pop();

        if (visitados[atual]) {
            continue; //não processa o msm cara 2 vezes

        }

        visitados[atual] = true;
        /*
         calcula o que precisa

        */

        for (auto proximo: vizinhos(atual)) {
            if (!visitados[proximo]) {
                fila.push(proximo);
            }
        }


    }
}


int solve() {
    vector<bool> visitados(N * M + 1, false);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (visitados[M * i + j + 1] == true || pixels[M * i + j + 1] == 'o') continue;
            dfs(M * i + j + 1, visitados);
        }
    }
}

int main() {
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            char s;
            cin >> s;
            pixels[i * M + j + 1] = s;
        }
    }
    solve();
    cout << cont << endl;


    return 0;
}