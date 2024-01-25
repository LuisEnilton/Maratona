//
// Created by Luis on 18/01/2024.
//
//
// Created by Luis on 14/01/2024.
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
#define MAX 200010
#define PRIME 101
#define MAXN 1010101
#define MAXL 23
#define EPS 1e-9
#define endl '\n'

using namespace std;
using namespace __gnu_pbds;

#define ordered_set tree<os_type, null_type,less<os_type>, rb_tree_tag,tree_order_statistics_node_update>

// from brunomaletta

// Responde https://cses.fi/problemset/task/1138/
namespace seg {
    ll seg[4 * MAX], lazy[4 * MAX];
    int n, *v;

    ll build(int p = 1, int l = 0, int r = n - 1) {
        lazy[p] = 0;
        if (l == r) return seg[p] = v[l];
        int m = (l + r) / 2;
        return seg[p] = build(2 * p, l, m) + build(2 * p + 1, m + 1, r);
    }

    void build(int n2, int *v2) {
        n = n2, v = v2;
        build();
    }

    void prop(int p, int l, int r) {
        if (lazy[p] == 0) return;
        seg[p] = lazy[p] * (r - l + 1);
        if (l != r) lazy[2 * p] = lazy[p], lazy[2 * p + 1] = lazy[p];
        lazy[p] = 0;
    }

    ll query(int a, int b, int p = 1, int l = 0, int r = n - 1) {
        prop(p, l, r);
        if (a <= l and r <= b) return seg[p];
        if (b < l or r < a) return 0;
        int m = (l + r) / 2;
        return query(a, b, 2 * p, l, m) + query(a, b, 2 * p + 1, m + 1, r);
    }

    ll update(int a, int b, ll x, int p = 1, int l = 0, int r = n - 1) {
        prop(p, l, r);
        if (a <= l and r <= b) {
            lazy[p] = x;
            prop(p, l, r);
            return seg[p];
        }
        if (b < l or r < a) return seg[p];
        int m = (l + r) / 2;
        return seg[p] = update(a, b, x, 2 * p, l, m) +
                        update(a, b, x, 2 * p + 1, m + 1, r);
    }
};


namespace hld {
    vi g[MAX];
    int sz[MAX], h[MAX], pai[MAX]; // tamanho da subarvore, altura e pai de cada nó
    int pos[MAX];
    int t = 0; // posição de cada vertice no array , o msm que passa pra seg tree
    int val[MAX]; // Valor associado a cada vértice
    int v[MAX];


    void dfs(int i, int p = -1) {
        sz[i] = 1;
        for (int &j: g[i])
            if (j != p) {
                dfs(j, i);
                sz[i] += sz[j];
                if (sz[j] > sz[g[i][0]] or g[i][0] == p) swap(j, g[i][0]);
            }
    }

    void build_hld(int i, int p = -1) {
        pos[i] = t++;
        v[pos[i]] = val[i];
        for (int j: g[i])
            if (j != p) {
                pai[j] = i;
                // se j for igual ao filho mais pesado ele fica na msm chain
                h[j] = (j == g[i][0] ? h[i] : j);
                build_hld(j, i);
            }
    }

    void build() {
        t = 0;
        h[0] = 0;
        dfs(0);
        build_hld(0);
        seg::build(t, v);
    }

    // soma do caminho entre a e b
    ll query_path(int a, int b) {
        if (pos[a] < pos[b]) swap(a, b);
        if (h[a] == h[b])
            return seg::query(pos[b], pos[a]);
        return seg::query(pos[h[a]], pos[a]) + query_path(pai[h[a]], b);
    }

    void update_path(int a, int b, ll x) {
        if (pos[a] < pos[b]) swap(a, b);
        if (h[a] == h[b]) return (void) seg::update(pos[b], pos[a], x);
        seg::update(pos[h[a]], pos[a], x);
        update_path(pai[h[a]], b, x);
    }
    //soma de todos os valores na subtree de a
    ll query_subtree(int a) {
        ll ans = seg::query(pos[a], pos[a] + sz[a] - 1);
        return ans;
    }

    // update de todos os valores na subtree, todos estão num range[l,r] no vetor v
    void update_subtree(int a, ll x) {
        seg::update(pos[a], pos[a] + sz[a] - 1, x);
    }

    int lca(int a, int b) {
        if (pos[a] < pos[b]) swap(a, b);
        return h[a] == h[b] ? b : lca(pai[h[a]], b);
    }
};

// Responde https://cses.fi/problemset/task/1138/
int main() {
    optimize;
    int n, q;
    cin >> n >> q;
    for (int i = 0; i < n; i++) cin >> hld::val[i];
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        hld::g[u].PB(v);
        hld::g[v].PB(u);
    }
    hld::build();
    while (q--) {
        int op, s;
        cin >> op >> s;
        s--;
        if (op == 1) {
            ll x;
            cin >> x;
            hld::update_path(s, s, x);
        } else {
            auto ans = hld::query_subtree(s);
            cout << ans << endl;
        }
    }

    return 0;
}

/*
 5 5
1 2 3 4 5
1 2
1 3
3 4
3 5
2 3 4
2 4 3
2 4 5
4 5 1
4 5 3
 * */

