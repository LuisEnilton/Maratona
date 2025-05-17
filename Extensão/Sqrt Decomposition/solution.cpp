//
// Created by Luis on 23/10/2023.
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
//Estrutura de Dados para manter os dados em blocos sqrt
struct sqrt_decomp {
    int len;
    vi a;
    vi b;

    //Construtor para decompor o vetor na estrutura
    sqrt_decomp(vector<int> &v) {
        int n = v.size();
        a = v;
        len = (int) sqrt(n + .0) + 1;
        len = (int) sqrt(n + .0);
        if (len == 0) len = 1;
        b = vi(len);
        for (int i = 0; i < n; ++i)
            b[i / len] += a[i];
    }

    //muda o ponto a para o valor  v
    void update(int pos,int v) {
        b[pos / len] -= a[pos];
        a[pos] = v;
        b[pos / len] += a[pos];
    }


    //Retorna o valor de  [a,b];
    int query(int l,int r) {
        int sum = 0;
        int c_l = l / len, c_r = r / len;

        if (c_l == c_r) {
            for (int i = l; i <= r; ++i)
                sum += a[i];
        } else {
            for (int i = l, end = (c_l + 1) * len - 1; i <= end; ++i)
                sum += a[i];
            for (int i = c_l + 1; i <= c_r - 1; ++i)
                sum += b[i];
            for (int i = c_r * len; i <= r; ++i)
                sum += a[i];
        }
        return sum;
    }
};


void solve() {
    int n, q;
    cin >> n >> q;
    vi a(n);

    for (auto &x: a) cin >> x;

    auto sq = sqrt_decomp(a);

    while (q--) {
        int op;
        cin >> op;

        if (op == 1) {
            int k, u;
            cin >> k >> u;
            k--;
            sq.update(k, u);
        }

        if (op == 2) {
            int l, r;
            cin >> l >> r;
            l--,r--;
            cout << sq.query(l, r) << endl;
        }
    }
}

signed main() {
    optimize;


    int t = 1;

    for (int i = 1; i <= t; i++) {
        solve();
    }
}

