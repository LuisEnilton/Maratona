//
// Created by Luis on 15/01/2024.
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

// O( sqrt(N) )
vector<ll> get_divisores(ll N)
{
    vector<ll> divisores;

    for (ll i = 1; i * i <= N; i++)
    {
        if (N % i != 0) continue;

        divisores.push_back(i);

        if (i * i != N)
            divisores.push_back(N / i);
    }

    return divisores;
}
// fatora o numero em fatores primos
// cada indice é um par {numero,quantidade}
vii fatora(ll N)
{
    vii ans;

    // O(sqrt(N))
    for (ll i = 2; i * i <= N; i++)
    {
        if (N % i != 0) continue;

        int qtd = 0;

        while (N % i == 0)
        {
            qtd++;
            N /= i;
        }

        ans.push_back({i, qtd});
    }

    if (N != 1)
        ans.push_back({N, 1});

    return ans;
}

int main() {
    optimize;

    return 0;
}

