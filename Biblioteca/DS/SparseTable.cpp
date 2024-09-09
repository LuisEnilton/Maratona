#include <bits/stdc++.h>
using namespace std;

#define MAXN 1010101
#define MAXL 23
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
            m[i][k] = min(m[i][k - 1], m[i + (1 << (k - 1))][k - 1]);
        }
    }
}

int query(int l, int r)
{
    int j = __builtin_clz(1) - __builtin_clz(r - l + 1);

    return min(m[l][j], m[r - (1 << j) + 1][j]);
}

signed main()
{
    int n;
    cin >> n;
    vi nums(n);
    for (auto &x : nums)
        cin >> x;
    precalc(nums);
    int q;
    cin >> q;
    while (q--)
    {
        int l, r;
        cin >> l >> r;
        cout << query(l, r) << endl;
    }

    return 0;
}