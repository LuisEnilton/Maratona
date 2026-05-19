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

    int n; cin >> n;

    vi a(n);
    map<int,int> freq;
    int maxi = 0;
    for(auto &x : a) cin >> x,freq[x]++,maxi = max(maxi,x);
    int ans = 0;

    vi dp(maxi + 1,0);
    for(auto &[k,v] : freq){
        dp[k] += v;
        ans = max(ans,dp[k]);
        int val = k;
        while(val <= maxi){
            dp[val] = max(dp[val],dp[k]);
            val += k;
        }
    }

    cout << ans << endl;
}