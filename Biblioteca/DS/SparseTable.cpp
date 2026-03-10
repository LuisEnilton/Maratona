#include <bits/stdc++.h>
using namespace std;

#define MAXN 1010101
#define MAXL 23
#define int long long
#define vi vector<int>
#define INF 1000000010

struct SparseTable
{

    vector<vi> m;
    int n, maxl;
    SparseTable(vi &a)
    {
        n = a.size();
        maxl = log2(a.size()) + 1;
        m.resize(n, vi(maxl, -INF));
        precalc(a);
    }

    void precalc(vi &a)
    {
        for (int i = 0; i < n; i++)
            m[i][0] = a[i];
        for (int k = 1; k < maxl; k++)
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
};

signed main()
{
    int n;
    cin >> n;
    vi nums(n);
    for (auto &x : nums)
        cin >> x;
    auto st = SparseTable(nums);
    int q;
    cin >> q;
    while (q--)
    {
        int l, r;
        cin >> l >> r;
        cout << st.query(l, r) << endl;
    }

    return 0;
}
