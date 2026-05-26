//
// Created by Luis on 15/09/2023.
//
// Template By eduardocesb
#include <bits/stdc++.h>
#define optimize                 \
    ios::sync_with_stdio(false); \
    cin.tie(NULL);               \
    cout.tie(NULL)
#define INF 1000000010
#define INFLL 1000000000000000010LL
#define ALL(x) x.begin(), x.end()
#define ll long long
#define vi vector<int>
#define PB push_back
#define EB emplace_back
#define MAXN 1010101
#define endl '\n'
#define int ll
using namespace std;

struct SegTree
{
    int n;
    vi arr;
    vi seg;
    int NEUTRO = 0;
    //  vetor 0- indexado
    // querie 1 indexado
    SegTree(vi &nums)
    {
        n = nums.size();
        seg.resize(4 * n);
        this->arr = nums;

        build(1, 1, n);
    }

    int join(int a, int b)
    {
        return a + b;
    }

    void build(int no, int l, int r)
    {
        if (l == r)
        {
            seg[no] = arr[l - 1];
            return;
        }

        int e = 2 * no;
        int d = e + 1;
        int mid = (l + r) / 2;
        build(e, l, mid);
        build(d, mid + 1, r);
        seg[no] = join(seg[e], seg[d]);
    }

    void update(int pos, int val, int no = 1, int l = 1, int r = -1)
    {
        if (r == -1)
            r = n;
        if (r < pos || l > pos)
        {
            return;
        }

        if (l == r)
        {
            seg[no] = val;
            return;
        }

        int e = 2 * no;
        int d = e + 1;
        int mid = (l + r) / 2;
        update(pos, val, e, l, mid);
        update(pos, val, d, mid + 1, r);

        seg[no] = join(seg[e], seg[d]);
    }

    int query(int a, int b, int l = 1, int r = -1, int no = 1)
    {
        if (r == -1)
            r = n;
        if (r < a || l > b)
        {
            return NEUTRO;
        }

        if (l >= a && r <= b)
        {
            return seg[no];
        }
        int e = 2 * no;
        int d = e + 1;
        int mid = (l + r) / 2;
        return join(query(a, b, l, mid, e), query(a, b, mid + 1, r, d));
    }
};

void solve()
{
    int n, q;
    cin >> n >> q;
    vi a(n);
    for (auto &x : a)
        cin >> x;
    auto seg = SegTree(a);

    while (q--)
    {
        int op;
        cin >> op;
        if (op == 1)
        {
            int pos, k;
            cin >> pos >> k;
            seg.update(pos, k);
        }
        else
        {
            int l, r;
            cin >> l >> r;
            auto ans = seg.query(l, r);
            cout << ans << endl;
        }
    }
}

signed main()
{
    optimize;
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}