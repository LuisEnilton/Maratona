//
// Created by Luis on 30/08/2023.
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

using namespace std;
using namespace __gnu_pbds;

#define ordered_set tree<os_type, null_type,less<os_type>, rb_tree_tag,tree_order_statistics_node_update>
const int maxn = 11;
vii grafo[maxn];
int n,m;

int memo[2050][maxn];


int solve(bitset<11> mask,int atual){
    if(mask.count() == n){
        return 0;
    }
    int ans = INF;
    mask.set(atual);
    //cout << mask.to_ullong() << endl;
    if(memo[mask.to_ullong()][atual] != -1){
        return memo[mask.to_ulong()][atual];
    }
    for(auto [dest,custo] : grafo[atual]){
        if(mask.test(dest)) continue;
        bitset<11> auxMask = mask;
        auxMask.set(dest);
        ans = min(ans,custo + solve(auxMask,dest));
    }
    return memo[mask.to_ullong()][atual] = ans;
}


int main(int argc, char** argv)
{
   // optimize;
    cin >> n >> m;
    for(int i =0;i < m;i++){
        int u ,v ,c;
        cin >> u >> v >> c;
        grafo[u].EB(v,c);
        grafo[v].EB(u,c);
    }

    int ans = INF;
    memset(memo,-1,  sizeof memo);
    for(int i = 1;i <=n;i++){
        bitset<11> mask;
        //cout << mask.to_ullong() << endl;
        ans = min(ans,solve(mask,i)) ;
    }
    cout << ans << endl;
    return 0;
}

