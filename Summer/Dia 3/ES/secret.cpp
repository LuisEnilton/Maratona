#include <bits/stdc++.h>
using namespace std;

#define MAXN 1010101
#define MAXL 23
#define int long long
#define vi vector<int>
int m[MAXN][MAXL];

// Funciona pra Min, Max e GCD em 0(1), idempotente
// O(log) para associativas não idempotentes

void precalc(vi &a) {
    int n = a.size();
    // O primeiro nivel são os numeros lidos no input
    for (int i = 0; i < n; i++)
        m[i][0] = a[i];

    for (int k = 1; k < MAXL; k++) {
        for (int i = 0; i + (1 << k) - 1 < n; i++) {
            m[i][k] = min(m[i][k - 1], m[i + (1 << (k - 1))][k - 1]);
        }
    }
}

signed query(int l, int r) {
    // RODAR O PRECALC
    int j = __builtin_clz(1) - __builtin_clz(r - l + 1);

    return min(m[l][j], m[r - (1 << j) + 1][j]);
}


int sum_query(int l, int r) {
    int sum = 0;
    for (int i = MAXL; i >= 0; i--) {
        if ((1 << i) <= r - l + 1) {
            sum += m[i][l];
            l += (1 << i);
        }
    }
}

signed main() {
    int n;
    cin >> n;
    vi nums(n);
    for (auto &x: nums)
        cin >> x;
    precalc(nums);
    int q;
    cin >> q;
    while (q--) {
        int l, r;
        cin >> l >> r;
        cout << query(l, r) << endl;
    }

    return 0;
}
