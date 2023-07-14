//
// Created by Luis on 06/07/2023.
//
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define optimize                 \
    ios::sync_with_stdio(false); \
    cin.tie(NULL);               \
    cout.tie(NULL)
#define INF 1000000010
#define INFLL 1000000000000000010LL
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
#define MAXN 1010101
#define MAXL 23
#define EPS 1e-9
#define endl '\n'

using namespace std;
using namespace __gnu_pbds;

#define ordered_set tree<os_type, null_type, less<os_type>, rb_tree_tag, tree_order_statistics_node_update>

int N, M;

int pai[MAXN];
int tamanho[MAXN];

int find(int u)
{
    if (u == pai[u])
        return u;
    return pai[u] = find(pai[u]);
    // dp para não pesquisar o pai 2 vezes
}

void join(int u, int v)
{
    u = find(u);
    v = find(v);
    if (u == v)
        return;

    if (tamanho[u] > tamanho[v])
        swap(u, v);

    pai[u] = v;

    tamanho[v] += tamanho[u];
}

int main()
{
    optimize;
    cin >> N >> M;
    for (int i = 1; i <= N; i++)
    {
        pai[i] = i;
        tamanho[i] = 1;
    }

    for (int i = 0; i < M; i++)
    {
        int u, v;
        cin >> u >> v;
        join(u, v);
    }
    set<int> pais;
    int cont = 0;
    for (int i = N; i > 0; i--)
    {
        int pai2 = find(i);
        pais.insert(pai2);
    }
    cout << pais.size() << endl;
}
