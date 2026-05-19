#include <bits/stdc++.h>

#define PB push_back
#define EB emplace_back
#define F first
#define S second
#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f
#define ALL(x) x.begin(),x.end()
using namespace std;

using ll = long long;
#define int ll
using vi = vector<int>;
using ii = pair<int, int>;
using vii = vector<ii>;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    map<int, vi> ruas;

    for(int i = 0; i < n; i++) {
        int r, c;
        cin >> r >> c;

        ruas[r].PB(c);
    }

    for(auto &[k, v]: ruas) sort(ALL(v));

    int ans = 0;

    for(auto &[k, v]: ruas) {
        int medi = v[v.size() / 2];

        for(auto &i: v) {
            ans += abs(medi - i);
        }
    }

    cout << ans << endl;
}