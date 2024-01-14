//
// Created by Luis on 13/01/2024.
//
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

void solve(){
    int n; cin >> n;
    vi dif;
    int ma = 0, me = INF;
    while(n--){
        int op; cin >> op;
        int num; cin >> num;
        if(op == 1){
            ma = max(ma,num);
        }
        if(op == 2){
            me = min(me,num);
        }
        if(op == 3){
            dif.PB(num);
        }
    }
    int cnt = 0;
    if(ma > me){
        cout << 0 << endl;
        return;
    }
    sort(ALL(dif));
    if(ma > me){
        cout << 0 << endl;
        return;
    }
    auto it = lower_bound(ALL(dif),ma);
    auto it2 = upper_bound(ALL(dif),me);
    it2--;
    int q = (it2 - it) + 1;
    int total = (me - ma + 1) - q;
    cout << total << endl;
}

int main() {
    optimize;
    int t; cin >> t;
    while(t--){
        solve();
    }
    return 0;
}

