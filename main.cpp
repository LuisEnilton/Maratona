//Template By eduardocesb
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <cmath>

#define optimize ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define INF 1000000010
#define INFLL 1000000000000000010LL
#define ALL(x) x.begin(), x.end()
#define UNIQUE(c) (c).resize(unique(ALL(c)) - (c).begin())
#define REP(i, a, b) for(int i = (a); i <= (b); i++)
#define POS(n, x) (lower_bound(ALL(n), x) - (n).begin())
#define ll long long
#define ld long double
#define pii pair<int,int>
#define vi vector<int>
#define vb vector<bool>
#define vii vector<pii>
#define os_type int
#define PB push_back
#define EB emplace_back
#define MOD 1000000007
#define PRIME 101
#define MAXN 1010101
#define MAXL 23
#define EPS 1e-9
#define endl '\n'
#define int ll
using namespace std;
using namespace __gnu_pbds;

#define ordered_set tree<os_type, null_type,less<os_type>, rb_tree_tag,tree_order_statistics_node_update>
typedef pair<pii, int> rng;




signed main() {
    //optimize;
    int n;
    cin >> n;
    vector<rng> rngs1;
    vector<rng> rngs2;
    vi ans(n);
    vi a;
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        a.PB(x);
        a.PB(y);
        rngs1.PB({{y, -x}, i});
        rngs2.PB({{-y, x}, i});
    }

    sort(ALL(rngs1));
    sort(ALL(rngs2));

    ordered_set cnt;
    unordered_map<int,int> freq;
    for(auto [x,id] : rngs1) {
        auto [r,l] = x;
        l = -l;
        ans[id] = cnt.order_of_key(10e9 + 10) - cnt.order_of_key(l) + freq[l];
        freq[l] ++;
        cnt.insert(l);
    }

    for(auto x : ans) cout << x << " ";
    cout << endl;

    cnt.clear();
    freq.clear();

    for(auto [x,id] : rngs2) {
        auto [r,l] = x;

        ans[id] = cnt.order_of_key(l) + freq[l];
        freq[l] ++;
        cnt.insert(l);
    }

    for(auto x : ans) cout << x << " ";
    cout << endl;

    return 0;
}