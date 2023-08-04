//
// Created by Luis on 27/06/2023.
//
//
// Created by Luis on 27/06/2023.
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
#define MAXN 1010010
#define MAXL 23
#define endl '\n'

using namespace std;
using namespace __gnu_pbds;

#define ordered_set tree<os_type, null_type, less<os_type>, rb_tree_tag, tree_order_statistics_node_update>
using namespace std;

int N,K;


int main() {
    optimize;
    cin >>N>>K;
    vi valores(N);

    for(auto &x:valores) cin >>x;

    ll ans = 0,soma = 0;

    vi prefix_sum;

    prefix_sum.PB(0);

    int i = 0;
    for(auto x:valores){
        soma+=x;

        ll falta = soma - K;
        //subtrae quantos são maiores de cada quantos são maiores ou iguais e acha os iguais
        ll qtd = upper_bound(ALL(prefix_sum),falta) - lower_bound(ALL(prefix_sum),falta);

        ans +=qtd;
        // adiciona pra evitar o caso 0 0 que contaria 2 somas . porém é só uma
        prefix_sum.PB(soma);

    }

    cout<< ans <<endl;
}

// 0 0 0 0 0 5 12 0 1 0 0 0 51 0 0
//


