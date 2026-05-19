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

    int n,l; cin >> n >> l;
    vi a(n);
    for(auto & x : a) cin >> x;
    sort(ALL(a));
    reverse(ALL(a));
    int ans = 0;
    for(auto x : a){
        int q = (100 - x);
        if(q > l) break;
        l -= q;
        ans ++;
    }
    cout << ans << endl;
}