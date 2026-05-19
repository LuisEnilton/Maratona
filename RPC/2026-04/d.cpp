#include <bits/stdc++.h>

#define F first
#define S second
#define ALL(x) x.begin(), x.end()
#define SQ(x) (x)*(x)

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

    vii pts(n);
    for(auto &[x, y]: pts) cin >> x >> y;

    int curr = 0, farthest = 0, extreme = 0;

    for(int i = 1; i < n; i++) {
        int norm = SQ(pts[i].F - pts[0].F) + SQ(pts[i].S - pts[0].S);
        if(norm > curr) {
            farthest = i;
            curr = norm;
        }
    }

    int x = pts[farthest].F, y = pts[farthest].S;
    curr = 0;

    for(int i = 0; i < n; i++) {
        if(i == farthest) continue;
        int norm = SQ(pts[i].F - x) + SQ(pts[i].S - y);
        if(norm > curr) {
            extreme = i;
            curr = norm;
        }
    }

    int ex = pts[extreme].F, ey = pts[extreme].S;

    for(auto &[x, y]: pts) {
        x -= ex;
        y -= ey;
    }

    sort(ALL(pts), [](ii a, ii b) {
        return SQ(a.F) + SQ(a.S) < SQ(b.F) + SQ(b.S);
    });

    ld ans = 0;

    for(int i = 1; i < n; i++) {
        ans += hypot(
            pts[i - 1].F - pts[i].F,
            pts[i - 1].S - pts[i].S
        );
    }

    cout << fixed << setprecision(10) << ans << endl;
}