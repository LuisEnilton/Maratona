#include <bits/stdc++.h>

#define F first
#define S second

using namespace std;

using ll = long long;
#define int ll
using vi = vector<int>;
using ii = pair<int, int>;
using vii = vector<ii>;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int p, h, t;

    cin >> p >> h >> t;

    if(t < p + h) cout << 0 << endl; 
    else cout << 1 + (t - p - h) / max(p, h) << endl;
}