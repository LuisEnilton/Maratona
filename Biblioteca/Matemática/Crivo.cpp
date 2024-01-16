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

vector<ll> primos;
vector<int> crivo(ll N)
{
    vector<int> eh_primo(N + 1, 1);

    eh_primo[0] = eh_primo[1] = 0;

    int pos = 1;

    // O(N * log N)
    for (ll i = 2; i <= N; i++)
    {
        if (!eh_primo[i]) continue;

        eh_primo[i] = pos++;

        // i é primo
        primos.push_back(i);

        for (ll j = i * i; j <= N; j += i)
            eh_primo[j] = 0;
    }

    return eh_primo;
}



int main() {
    optimize;
    auto a = crivo(56);
    for(auto x : a){
        cout << x << " ";
    }
    return 0;
}

