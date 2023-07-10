//
// Created by luise on 10/07/2023.
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

int n, l;
vi atendentes;
vi ligacoes;
vi n_ligacoes;
int main(int argc, char **argv) {       //tempo , (id,tipo)
    optimize;
    priority_queue<pii, vector<pii >, greater<pii>> fila;
    //tempo id

    cin >> n >> l;
    n_ligacoes.resize(n+1);
    ligacoes.resize(l);
    for (auto &x: ligacoes) cin >> x;
    for (int i = 1; i <=n ; i++) {
        fila.push({0,i});
    }
    for (auto lig: ligacoes) {
        pii ele = fila.top();
        fila.pop();
        ele.first += lig;
        fila.push(ele);
        n_ligacoes[ele.second] += 1;
    }

    for (int i = 1; i <=n ; i++) {
        cout<< i << " " << n_ligacoes[i] << endl;
    }
    return 0;
}