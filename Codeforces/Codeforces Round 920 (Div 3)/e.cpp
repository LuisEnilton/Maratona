//
// Created by Luis on 15/01/2024.
//
//
// Created by Luis on 15/01/2024.
//
//
// Created by Luis on 15/01/2024.
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

int xa,ya,xb,yb;
int h,w;
int fuga(bool a){
    if(a){
        if(yb > ya) return w - yb;
        else return yb - 1;
    }else{
        if(ya > yb) return w -ya;
        else return ya - 1;
    }
}

void solve() {
     cin >> h >> w;
    cin >> xa >> ya >> xb >> yb;
    int x_dif = abs(xa - xb);
    int y_dif = abs(ya - yb);
    bool ans;
    if(xa >= xb){
         cout << "Draw" << endl;
         return;
    }
    if(x_dif & 1){
        auto d = min(fuga(true),x_dif/2);
        if(x_dif/2 + 1 >= y_dif + d) ans = true;
        else ans = false;
        cout << (ans?"Alice":"Draw") << endl;
    }else{
        auto d = min(fuga(false),x_dif/2);
        if(x_dif/2  >= y_dif + d) ans = true;
        else ans = false;
        cout << (ans?"Bob":"Draw") << endl;
    }

}


int main() {
    optimize;
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}

/*
 *
 5 5 1 4 5 2
 *
 * */