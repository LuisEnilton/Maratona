//
// Created by Luis on 16/01/2024.
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


struct Jedi {
    ll maior;
    ll soma; // soma
    int id;
    Jedi() {
        this->maior = 0;
        this->soma = 0;
    }

    Jedi(ll maior,ll soma,int id){
        this->maior = maior;
        this->soma = soma;
        this->id = id;
    }

    bool operator<(const Jedi &j) {
        return (this->soma - this->maior) < (j.soma - j.maior);
    }
};



int bb(vector<ll> v, ll p){
    return upper_bound(ALL(v),p) - v.begin();
}

int main() {
    optimize;
    int n; cin >> n;
    vector<Jedi> v;
    for (int i = 0; i < n; i++) {
        ll soma = 0;
         ll a,b,c; cin >> a >> b >> c;
         ll maior = max({a,b,c});
         v.emplace_back(soma,maior,i);
    }
    vector<Jedi> sla = v;
    sort(ALL(v));
    vector<ll> aux;
    vi ordem;
    for(auto x : v){
        aux.EB(x.soma - x.maior);

    }
    for(auto x : sla){
        cout << bb(aux,x.soma)  << " ";
    }
    cout << endl;
    return 0;
}

