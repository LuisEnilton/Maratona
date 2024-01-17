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

struct SegTree {

    vector<ll> seg, lazy, nums;
    int n;
    ll NEUTRO = 0;

    SegTree() {

    }

    SegTree(vector<ll> &nums,int &n) {
        this->n = n;
        seg.resize(4 * n);
        lazy.resize(4 * n);

        this->nums = nums;

        build(1, 0, n - 1, nums);
    }

    ll join(ll a, ll b) {
        return a + b;
    }

    void unlazy(int no, int l, int r) {
        if (lazy[no] == 0) return;

        int  e = no * 2, d = no * 2 + 1;

        seg[no] = (r - l + 1) * lazy[no];

        if (l != r) {
            lazy[e] = lazy[no];
            lazy[d] = lazy[no];
        }

        lazy[no] = NEUTRO;
    }

    ll query(int no, int l, int r, int a, int b) {
        unlazy(no, l, r);
        if (b < l || r < a) return NEUTRO;
        if (a <= l && r <= b) return seg[no];

        int m = (l + r) >> 1, e = no * 2, d = no * 2 + 1;

        return query(e, l, m, a, b) + query(d, m + 1, r, a, b);
    }

    void update(int no, int l, int r, int a, int b, ll v) {
        unlazy(no, l, r);
        if (b < l || r < a) return;
        if (a <= l && r <= b) {
            lazy[no] = v;
            unlazy(no, l, r);
            return;
        }

        int m = (l + r) >> 1, e = no * 2, d = no * 2 + 1;

        update(e, l, m, a, b, v);
        update(d, m + 1, r, a, b, v);

        seg[no] = join(seg[e], seg[d]);
    }


    void build(int no, int l, int r, vector<ll> &lista) {
        if (l == r) {
            seg[no] = lista[l];
            return;
        }

        int m = (l + r) >> 1, e = no * 2, d = no * 2 + 1;

        build(e, l, m, lista);
        build(d, m + 1, r, lista);

        seg[no] = join(seg[e], seg[d]);
    }
};


struct HLD {
    vector<vi > g;
    vi sz, h, pai; // tamanho da subarvore, altura e pai de cada nó
    vi pos;
    int t = 0; // posição de cada vertice no array , o msm que passa pra seg tree
    vector<ll> val; // Valor associado a cada vértice
    vector<ll> nums;
    SegTree seg;

    explicit HLD(int n) {
        g.resize(n + 2);
        sz.resize(n + 2);
        h.resize(n + 2);
        pai.resize(n + 2);
        pos.resize(n + 2);
        val.resize(n + 2);
        nums.resize(n + 2);
    }

    void dfs(int i, int p = -1) {
        sz[i] = 1;
        for (int &j: g[i])
            if (j != p) {
                dfs(j, i);
                sz[i] += sz[j];
                if (sz[j] > sz[g[i][0]]) swap(j, g[i][0]);
            }
    }

    void build_hld(int i, int p = -1) {
        pos[i] = t++;
        nums[pos[i]] = val[i];
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
        seg = SegTree(nums,t);
    }


    int lca(int a, int b) {
        if (pos[a] < pos[b]) swap(a, b);
        return h[a] == h[b] ? b : lca(pai[h[a]], b);
    }

    ll query_path(int a, int b) {
        if (pos[a] < pos[b]) swap(a, b);
        if (h[a] == h[b])
            return seg.query(1, 0, t - 1, pos[b], pos[a]);
        return seg.query(1, 0, t - 1, pos[h[a]], pos[a]) + query_path(pai[h[a]], b);
    }

    void update_path(int a, int b, ll x){
        if(pos[a] < pos[b]) swap(a,b);
        if(h[a] == h[b]){
            seg.update(1,0,t-1,pos[b],pos[a],x);
            return;
        }
        seg.update(1,0,t-1,pos[h[a]],pos[a],x);
        update_path(pai[h[a]],b,x);
    }
};

int main() {
    optimize;
    int n, q;
    HLD hld(n);
    cin >> n >> q;
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
        int op;
        cin >> op;
        if (op == 1) {
            int s; cin >> s;
            s--;
            ll x;
            cin >> x;
            hld.update_path(s,s,x);
        } else {
            int s;
            cin >> s;s--;
            cout << hld.query_path(0,s) << endl;
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

