//
// Created by Luis on 06/09/2023.
//
// Template By eduardocesb
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define optimize                 \
    ios::sync_with_stdio(false); \
    cin.tie(NULL);               \
    cout.tie(NULL);
#define INF 1000000010
#define INFLL 1000000000000000010LL
#define ALL(x) x.begin(), x.end()
#define ll long long
#define pii pair<int, int>
#define vi vector<int>
#define vb vector<bool>
#define BT bitset<500>
#define vii vector<pii>
#define os_type int
#define PB push_back
#define EB emplace_back
#define MOD 1000000007
#define MAXN 1010101
#define int ll
#define dbg(x) cout << #x << " " << x << endl;
// #define endl '\n'

using namespace std;
using namespace __gnu_pbds;

#define ordered_set tree<os_type, null_type, less<os_type>, rb_tree_tag, tree_order_statistics_node_update>




vector<vii> sla;

pii trans(int  a, int  b){

    if(a > b) {
        swap(a,b);
        auto ans = sla[a][b - a];
        swap(ans.first,ans.second);
        return ans;
    }
    // dbg(a);
    // dbg(b);
    return sla[a][b - a];
}

int n;
vi a,b;

int dp[101][101][101];

bool can(int i, int x, int y){
    if(x < 0 || y < 0) return 0;
    if(i == n) return 1;
    auto & at = dp[i][x][y];
    if(~at) return at;
    at = 0;
    // dbg(i);
    // dbg(n);
    for(int val = 1 ; val < 10 && !at;val++){

        auto [apaga1,acende1] = trans(a[i],val);
        auto [apaga2,acende2] = trans(b[i],val);

        int tot_apaga = apaga1 + apaga2;
        int tot_acende = acende1 + acende2;
        at |= can(i + 1, x - tot_apaga, y - tot_acende);
    }
    return at;
}

void solve()
{
    int x,y; cin >> n >> x >> y;

    string s,t; cin >> s >> t;
    // dbg(t);

    for(int i = 0; i < n;i++){

        for(int j = 0; j <= x;j++){
            for(int z = 0; z <= y;z++){
                dp[i][j][z] = -1;
            }
        }
    }

    a.clear(),b.clear();
    for(auto c : s){
        a.push_back(c - '0');
    }
    for(auto c : t){
        b.push_back(c - '0');
    }
    // dbg(a.size());
    // dbg(b.size());

    auto ans = can(0,x,y);
    cout << (ans?"YES":"NO") << endl;
}

signed main()
{
    optimize;
    int t = 1;
    cin >> t;
    sla.resize(10);

    sla[0] = {{0,0},{4, 0}, {2, 1}, {2, 1}, {3, 1}, {2, 1}, {1, 1}, {3, 0}, {0, 1}, {1, 1}};
    sla[1] = {{0,0},{1, 4}, {0, 3}, {0, 2}, {1, 4}, {1, 5}, {0, 1}, {0, 5}, {0, 4}};
    sla[2] = {{0,0},{1, 1}, {3, 2}, {2, 2}, {1, 2}, {3, 1}, {0, 2}, {1, 2}};
    sla[3] = {{0,0},{2, 1}, {1, 1}, {1, 2}, {2, 0}, {0, 2}, {0, 1}};
    sla[4] = {{0,0},{1,2},{1,3},{2,1},{0,3},{0,2}};
    sla[5] = {{0,0},{0,1},{3,1},{0,2},{0,1}};
    sla[6] = {{0,0},{4,1},{0,1},{1,1}};
    sla[7] = {{0,0},{0,4},{0,3}};
    sla[8] = {{0,0},{1,0}};
    sla[9] = {{0,0}};
    while (t--)
    {
        solve();
    }
    return 0;
}
