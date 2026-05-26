#include <bits/stdc++.h>

using ll = long long;
#define int ll

using namespace std;

signed main() {
    int t;
    cin >> t;

    while(t--) {
        int n, m, a;
        cin >> n >> m >> a;

        cout << min(n - m, a) << endl;
    }
}