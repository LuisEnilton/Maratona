#include <bits/stdc++.h>
using namespace std;

#define int long long
#define vi vector<int>
#define INF 1000000010
#define ALL(x) x.begin(), x.end()
#define dbg(x) cout << #x << " " << x << endl;
#define MAXL 10
#define endl '\n'
#define pii pair<int, int>
#define vii vector<pii>
#define MAXN 1000010

void solve()
{
    int n, s;
    cin >> n >> s;
    if(n == s){
        cout << 1 << endl;
        return;
    }
    s = s % n;

    int ans = lcm(s, n) / s;

    cout << ans << endl;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tc = 1;
    // cin >> tc;
    while (tc--)
    {
        solve();
    }
    return 0;
}