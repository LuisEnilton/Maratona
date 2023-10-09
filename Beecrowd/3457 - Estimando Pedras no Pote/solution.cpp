//
// Created by Luis on 07/10/2023.
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
multiset<ll> erros;
vi palpites;
int n;
set<ll> ans;

bool check(int code) {
    ll maiorErro = *(erros.rbegin());
    ll valor1;
    if (code == 1)
        valor1 = palpites[0] + maiorErro;
    if (code == 2)
        valor1 = palpites[n - 1] - maiorErro;
    if(valor1 < 1 || valor1 > 1000000000) return false;
    map<ll, int> qtdDesvios;
    for (int i = 0; i < n; i++) {
        qtdDesvios[abs(valor1 - palpites[i])] += 1;
    }
    bool ok = true;
    // a qtd de desvios tem que ser igual pra essa opção tem que ser igual aos erros dados na questão
    for (auto x: qtdDesvios) {
        if (erros.count(x.first) != x.second) {
            ok = false;
        }
    }
    if (ok) {
        ans.insert(valor1);
    }
    return ok;
}


int main(int argc, char **argv) {
    optimize;

    cin >> n;
    palpites.resize(n);
    for (auto &x: palpites) cin >> x;
    sort(ALL(palpites));

    for (int i = 0; i < n; i++) {
        int e;
        cin >> e;
        erros.insert(e);
    }
    // tem que testar o maior desvio com o menor palpite e com o maior palpite
    for (int i = 1; i <= 2; i++) {
        check(i);
    }
    for (auto x: ans) {
        cout << x << endl;
    }


    return 0;
}

