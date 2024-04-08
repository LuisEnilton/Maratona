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
#define MAXN 501010
#define MAXL 23
#define EPS 1e-9
#define endl '\n'
#define int long long
using namespace std;
using namespace __gnu_pbds;
 
#define ordered_set tree<os_type, null_type,less<os_type>, rb_tree_tag,tree_order_statistics_node_update>
 
int pai[MAXN], sz[MAXN],vida[MAXN];
 
 
inline int find(int u){ 
	return ( pai[u] == u  ?  u  :  pai[u] = find(pai[u]) ); 
}
 
 
inline void join(int u, int v){
	u = find(u);
	v = find(v);
 
	if(u == v) return;
	if(sz[v] > sz[u]) swap(u, v);
 
	pai[v] = u;
	sz[u] += sz[v];
    vida[u] += vida[v];
}
 
 
inline void resetDSU(){
	for(int i=0; i<MAXN; i++) 
		sz[i] = 1, pai[i] = i,vida[i] = 3;
}
 
signed main() {
    optimize;
    resetDSU();
    int n,a,j; cin >> n >> a >> j;
    int ans = 0;
    while(a--){
        int op; cin >> op;
        int x,y; cin >> x >> y;
        x = find(x),y = find(y);
        if(vida[x] > vida[y]) swap(x,y);
        if(x == y || vida[x] == 0) continue;
        if(op == 1){
            x = find(x),y = find(y);
            if(vida[x] > vida[y]) swap(x,y);
            if(vida[x] == 0) continue;
            if(vida[x] == vida[y]){
                vida[x]--;
                vida[y]--;
            }else{
                join(y,x);
            }
        }else{
            x = find(x),y = find(y);
            if(vida[x] > vida[y]) swap(x,y);
            assert(vida[x] >= 0);
            if(x == y || vida[x] == vida[y] || vida[x] <= 0) continue;
            vida[x] = 0;
            if(find(j) == y) ans++;
        }
        
    }
    cout << ans << endl;
    return 0;
}