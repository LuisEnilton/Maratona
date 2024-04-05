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

using namespace std;
using namespace __gnu_pbds;

#define ordered_set tree<os_type, null_type,less<os_type>, rb_tree_tag,tree_order_statistics_node_update>

vi Zfunction(string &s)
{
    int n = s.size();
    vi z (n, 0);

    for(int i=1, l=0, r=0; i<n;  i++)
    {
        if(i <= r) z[i] = min(z[i-l], r-i+1);

        while(z[i] + i < n && s[z[i]] == s[i+z[i]]) z[i]++;

        if(r < i+z[i]-1) l = i, r = i+z[i]-1;
    }

    return z;
}

void solve(){
    int n; cin >> n;
    string s; cin >> s;
    string aux = "pie" + s;
    auto z = Zfunction(aux);
    int ans = 0;
    for(int i = 3; i < n + 3; i++){
        if(z[i] >= 3) ans++;
    }
    aux = "map" + s;
    z = Zfunction(aux);
    for(int i = 3; i < n + 3; i++){
        if(z[i] >= 3) ans++;
    }
    aux = "mapie" + s;
    z = Zfunction(aux);
    for(int i = 5; i < n + 5; i++){
        if(z[i] >= 5) ans--;
    }
    cout << ans << endl;
}


int main() {
    optimize;
    int t; cin >> t;
    while(t--){
        solve();
    }
    return 0;
}

