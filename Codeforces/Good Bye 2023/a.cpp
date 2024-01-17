//
// Created by Luis on 30/12/2023.
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

vector<ll> get_divisores(ll N) {
    vector<ll> divisores;

    for (ll i = 1; i * i <= N; i++) {
        if (N % i != 0) continue;

        divisores.push_back(i);

        if (i * i != N)
            divisores.push_back(N / i);
    }

    return divisores;
}

vi divisores = {7, 17, 119, 289, 2023};


void solve() {
    int n, k;
    cin >> n >> k;
    ll p = 1;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        p*=x;
    }
    ll val = 2023 % p;
    if(val !=0 || val > p ){
        cout << "NO" << endl;
    }else{
        cout << "YES" <<endl;
        ll v = 2023/p;
        cout << v << " ";
        for(int i = 1; i < k;i++){
            cout << 1 << " ";

        }
        cout << endl;
    }

}


int main() {
    optimize;
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
