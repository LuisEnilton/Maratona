// By SamuellH12
#include <bits/stdc++.h>
#define optimize                 \
    ios::sync_with_stdio(false); \
    cin.tie(NULL);               \
    cout.tie(NULL)
using namespace std;
#define vi vector<int>
#define ll long long
const int MAXN = 1e6 + 5;
#define int ll

struct Tag {
    int val = 0;
    bool op = false;
    
    Tag() {}
    
    Tag(int _val, bool _op) : val(_val), op(_op) {}
    
    void compose(const Tag& t) {
        if (t.op) {
            op = 1;
            val = t.val;
        }else{
            val += t.val;
        }
    }
};

struct Node {
    ll val = 0;
    
    Node(ll v = 0) : val(v) {}
    
    static Node join(const Node& l, const Node& r) {
        return Node(l.val + r.val); 
    }
    
    void apply(const Tag& t, int l, int r) {
        ll len = r - l + 1;
        if (t.op) {
            val = t.val * len;
            return; 
        }
        val += t.val * len; 
    }
};

template <typename NODE, typename TAG>
struct SegTreeLazy {
    int N; vector<NODE> seg; vector<TAG> lazy;
    
    template <typename T>
    SegTreeLazy(const vector<T>& arr) : N(arr.size()), seg(4 * N), lazy(4 * N) { build(1, 1, N, arr); }

    template <typename T>
    void build(int p, int l, int r, const vector<T>& arr) {
        if (l == r) return void(seg[p] = NODE(arr[l - 1]));
        int m = (l + r) >> 1;
        build(p << 1, l, m, arr); build(p << 1 | 1, m + 1, r, arr);
        seg[p] = NODE::join(seg[p << 1], seg[p << 1 | 1]);
    }

    void push(int p, int l, int r) {
        int m = (l + r) >> 1, e = p << 1, d = e | 1;
        seg[e].apply(lazy[p], l, m); lazy[e].compose(lazy[p]);
        seg[d].apply(lazy[p], m + 1, r); lazy[d].compose(lazy[p]);
        lazy[p] = TAG();
    }

    void update(int p, int l, int r, int a, int b, const TAG& v) {
        if (b < l || r < a) return;
        if (a <= l && r <= b) { seg[p].apply(v, l, r); lazy[p].compose(v); return; }
        push(p, l, r); int m = (l + r) >> 1;
        update(p << 1, l, m, a, b, v); update(p << 1 | 1, m + 1, r, a, b, v);
        seg[p] = NODE::join(seg[p << 1], seg[p << 1 | 1]);
    }

    NODE query(int p, int l, int r, int a, int b) {
        if (b < l || r < a) return NODE();
        if (a <= l && r <= b) return seg[p];
        push(p, l, r); int m = (l + r) >> 1;
        return NODE::join(query(p << 1, l, m, a, b), query(p << 1 | 1, m + 1, r, a, b));
    }

    void update(int l, int r, const TAG& v) { update(1, 1, N, l, r, v); }
    NODE query(int l, int r) { return query(1, 1, N, l, r); }
};


void solve()
{
    // https://cses.fi/problemset/task/1735
    int n, q;
    cin >> n >> q;
    vi a(n);
    for (auto &x : a)
        cin >> x;
    SegTreeLazy<Node, Tag> seg(a);

    while (q--)
    {
        int op;
        cin >> op;
        // dbg(op);
        if (op == 1)
        {
            int l, r, v;
            cin >> l >> r >> v;
            auto tag = Tag(v,0);
            seg.update(l, r, tag);
        }
        if (op == 2)
        {
            int l, r, v;
            cin >> l >> r >> v;

            auto tag = Tag(v,1);

            seg.update(l, r, tag);
        }
        if (op == 3)
        {
            int l, r;
            cin >> l >> r;
            int ans = seg.query(l, r).val;
            cout << ans << endl;
        }
    }
}

signed main()
{
    optimize;

    int t = 1;
    // cin >> t;
    for (int i = 1; i <= t; i++)
    {

        solve();
    }
    return 0;
}