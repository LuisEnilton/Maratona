#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define br '\n'
#define int ll


void solve() {
    int n,m;
    cin >> n >> m;

    vector<int> qnt(m);
    for(auto&e : qnt) cin >> e;

    vector<vector<char>> g(n, vector<char>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) cin >> g[i][j];
    }

    vector<int> N(m);
    for(auto&e : N) cin >> e;
    vector<vector<int>> ans(n, vector<int>(m));

    for (int i = n-1; i >= 0; i--) {
        for (int j = 0; j < m; j++) {
            if (g[i][j] == '.') {
                ans[i][j] = (i == n-1) ? N[j] : ans[i+1][j];
            }
            else {
                int bst = (i == n-1) ? N[j] : ans[i+1][j];
                
                if (j > 0) {
                    bst = max(bst, (i == n-1 ? N[j-1] : ans[i+1][j-1]));
                }
                if (j < m-1) {
                    bst = max(bst, (i == n-1 ? N[j+1] : ans[i+1][j+1]));
                }

                ans[i][j] = bst;
            }
        }
    }

    ll res = 0;
    for (int i = 0; i < m; i++) {
        res += (ll)qnt[i] * ans[0][i];
    }

    cout << res << br;
    
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("balls.in", "r", stdin);

    int tc = 1;
    cin >> tc;

    while (tc--)
    {
        solve();
    }

    return 0;    
}