//
// Created by Luis on 16/01/2024.
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
#define PRIME 101
#define MAXN 1010101
#define MAXL 23
#define EPS 1e-9
#define endl '\n'

using namespace std;
using namespace __gnu_pbds;

#define ordered_set tree<os_type, null_type,less<os_type>, rb_tree_tag,tree_order_statistics_node_update>

const int MAX = 1e5 + 10;

struct Count {
    vector<vi > oc;

    Count() {

    }

    Count(int n) {
        oc.resize(n + 2);
    }

    void build(int n, vi &v) {
        for (int i = 0; i < n; i++) {
            oc[v[i]].PB(i);
        }
    }

    int query(int l, int r, int x) {
        return upper_bound(ALL(oc[x]), r)
               - lower_bound(ALL(oc[x]), l);
    }
};


struct HLD {
    vector<vi > g;
    vi sz, h, pai; // tamanho da subarvore, altura e pai de cada nó
    vi pos;
    int t = 0; // posição de cada vertice no array , o msm que passa pra seg tree
    vi val; // Valor associado a cada vértice
    vi v;
    Count cnt;

    explicit HLD(int n) {
        g.resize(n + 2);
        sz.resize(n + 2);
        h.resize(n + 2);
        pai.resize(n + 2);
        pos.resize(n + 2);
        val.resize(n + 2);
        v.resize(n + 2);
        cnt = Count(n);

    }

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
        cnt.build(t, v);
    }


    int lca(int a, int b) {
        if (pos[a] < pos[b]) swap(a, b);
        return h[a] == h[b] ? b : lca(pai[h[a]], b);
    }

    int query(int a, int b, int c) {
        if (pos[a] < pos[b]) swap(a, b);
        if (h[a] == h[b])
            return cnt.query(pos[b], pos[a], c);
        auto aux = cnt.query(pos[h[a]], pos[a], c);
        return aux + query(pai[h[a]], b, c);
    }
};

int main() {
    //optimize;
    int n, q;
    while (cin >> n >> q) {

        HLD hld(n);

        for (int i = 0; i < n; i++) cin >> hld.val[i];

        for (int i = 0; i < n - 1; i++) {
            int u, v;
            cin >> u >> v;
            u--, v--;
            hld.g[u].PB(v);
            hld.g[v].PB(u);
        }
        hld.build();
        while (q--) {
            int a, b, c;
            cin >> a >> b >> c;
            a--, b--;
            if (hld.query(a, b, c)) cout << "Find" << endl;
            else cout << "NotFind" << endl;
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

