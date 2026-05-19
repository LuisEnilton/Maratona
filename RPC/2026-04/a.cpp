#include <bits/stdc++.h>

#define F first
#define S second

using namespace std;

using ll = long long;
#define int ll
using vi = vector<int>;
using ii = pair<int, int>;
using vii = vector<ii>;

using ld = long double;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    // ld t = 0;
    // int idk = 100;
    // while(idk--) {
    //     cout << floor(100 * t) / 100 << endl;
    //     t += 0.015;
    // }

    int n;
    cin >> n;

    const ld eps = 1e-4;

    while(n--) {
        ld x;
        cin >> x;

        int X = (x / 0.015);
        int ok = 0;
        for(int i = max(0ll, X - 2); i <= X + 2; i++) {
            ld rnd = floor(i * 0.015 * 100 + eps) / 100;

            if(fabs(rnd - x) < eps) {
                ok = 1;
                break;
            }
        }
        cout << (ok ? "VALID" : "IMPOSSIBLE") << endl;
    }
}