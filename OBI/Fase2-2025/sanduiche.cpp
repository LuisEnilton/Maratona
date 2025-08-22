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
#define UNIQUE(c) (c).resize(unique(ALL(c)) - (c).begin())
#define ll long long
#define pii pair<int, int>
#define vi vector<int>
#define vs vector<string>
#define vb vector<bool>
#define BT bitset<500>
#define vii vector<pii>
#define os_type int
#define PB push_back
#define EB emplace_back
#define MOD 1000000007
#define MAXN 400010
#define int ll
#define endl '\n'

using namespace std;
using namespace __gnu_pbds;

#define ordered_set tree<os_type, null_type, less<os_type>, rb_tree_tag, tree_order_statistics_node_update>


vi restri;

int ans = 0;
int n;
void solve(int i,int mask){
    //bitset<10> bt(mask);
    
    //cout << i << " " << bt << endl;
    if(i == n + 1) {
        ans++;
        return;
    }
    if((restri[i] & mask) == 0) solve(i + 1, mask | (1 << i));
    solve(i + 1,mask);

}

signed main()
{
    optimize 
    int m; cin >> n >> m;
     restri = vi(n + 1); // mascara de restricoes para cada ingrediente

    while(m--){
        int x,y; cin >> x >> y;
        restri[x] |= (1 << y);
        restri[y] |= (1 << x);
    }

    solve(1,0);
    cout << ans - 1 << endl;
    return 0;
}