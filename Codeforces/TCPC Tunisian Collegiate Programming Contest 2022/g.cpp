#include <bits/stdc++.h>

using ll = long long;
#define int ll

using namespace std;

signed main() {
    int n, x, ans = 0;
    cin >> n >> x;

    string s, t;
    cin >> s >> t;

    for(int i = 0; i < n; i++) {
        int j = (i + x) % n;

        if(t[j] != s[i]) {
            ans++;
        }
    }

    cout << ans << endl;
}