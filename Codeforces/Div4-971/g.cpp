//
// Created by Nil on 03/12/2024.
//
//
// Created by Luis on 06/09/2023.
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

#define vi vector<int>
int m[MAXN][MAXL];

// Funciona pra Min, Max e GCD

void precalc(vi &a)
{
    int n = a.size();
    // O primeiro nivel são os numeros lidos no input
    for (int i = 0; i < n; i++)
        m[i][0] = a[i];

    for (int k = 1; k < MAXL; k++)
    {
        for (int i = 0; i + (1 << k) - 1 < n; i++)
        {
            m[i][k] = max(m[i][k - 1], m[i + (1 << (k - 1))][k - 1]);
        }
    }
}

int query(int l, int r)
{
    // RODAR O PRECALC
    int j = __builtin_clz(1) - __builtin_clz(r - l + 1);

    return max(m[l][j], m[r - (1 << j) + 1][j]);
}


int n,k,q;

void solve() {
    cin >> n >> k >> q;
    vi a (n),cnt(n, 1);
    for(auto & x : a) cin >> x;

    for(int i = 1; i < n;i++) {
        if(cnt[i] == cnt[i - 1]) {
            cnt[i] = cnt[i - 1] + 1;
        }else {
            cnt[i] = 1;
        }
    }

    precalc(cnt);

    while(q--) {
        int l,r; cin >> l >> r;
        int q = (r - l + 1);
        int maxi = query(l,r);
    }

}


int main() {
    optimize;
    int t; cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}

