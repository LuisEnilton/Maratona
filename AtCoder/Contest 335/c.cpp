//
// Created by Luis on 06/01/2024.
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


int main() {
    optimize;
    int n, q;
    cin >> n >> q;
    unordered_map<int, pii > head;
    for (int i = 2; i <= n; i++) {
        head[-i + 1] = {0, i};
    }
    head[0] = {0,1};
    int t = 1;
    while (q--) {
        int op; cin >> op;
        if(op == 1){
            char c; cin >> c;
            auto [y,x] = head[t - 1];
            if(c == 'U'){
                head[t] = {y + 1,x};
            }
            if(c == 'D'){
                head[t] = {y - 1,x};
            }
            if(c == 'L'){
                head[t] = {y ,x - 1};
            }
            if(c == 'R'){
                head[t] = {y,x + 1};
            }
            t++;
        }else{
            int p; cin >> p;
            auto ans = head[t - p];
            cout << ans.second << " " << ans.first << endl;
        }
    }
    return 0;
}

