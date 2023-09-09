//
// Created by Luis on 09/09/2023.
//
//Template By eduardocesb
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

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
#define f first
#define s second

using namespace std;
using namespace __gnu_pbds;

#define ordered_set tree<os_type, null_type,less<os_type>, rb_tree_tag,tree_order_statistics_node_update>

int n;
ll x, y;
vector<pair<int, ll>> stop;
ll memo[841];
int calc(){
    int ans = 1;
    for(int i = 1;i <9;i++){
        ans = ans*i/gcd(ans,i);
    }
    return ans;
}


void precalc(){
    for(ll j = 0;j <= 840;j++){
        ll val = j;
        val+=x;
        for (int i = 0; i < n -1; i++) {
            if (val % stop[i].f == 0) {
                val += stop[i].s;
            } else {
                ll time = (val / stop[i].f) + 1;
                val = stop[i].f * time;
                val += stop[i].s;
            }
        }
        memo[j] = val - j + y;
    }
}

int main(int argc, char **argv) {
    optimize;
    cin >> n >> x >> y;
    stop.resize(n - 1);
    for (auto &p: stop) {
        cin >> p.f;
        cin >> p.s;
    }
    int q;
    cin >> q;
    int mmc = calc();
    //cerr << mmc << endl;
    precalc();
    while (q--) {
        ll val ;
        cin >> val;
        ll m = val % 840;
        cout << val+memo[m] << endl;
    }
    return 0;
}

