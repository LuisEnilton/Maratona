#include <bits/stdc++.h>

using namespace std;

using ll = long long;
#define int ll
using vi = vector<int>;

signed main() {
    int n;
    cin >> n;

    vi vec(n);

    for(int i = 0; i < n; i++) {
        cin >> vec[i];

        if(i) vec[i] += vec[i - 1];
    }

    int q;
    cin >> q;

    while(q--) {
        int x, y, m;
        cin >> x >> y >> m;

        cout << min(vec[m - 1] + y, max(x, vec.back())) << endl;
    }
}