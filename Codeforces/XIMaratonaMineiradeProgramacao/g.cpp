#include <bits/stdc++.h>

#define PB push_back
#define EB emplace_back
#define F first
#define S second
#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f
#define dbg(x) cout << #x << " " << x << endl;
using namespace std;

using ll = long long;
#define int ll
using vi = vector<int>;
using ii = pair<int, int>;
using vii = vector<ii>;


const int MAXN = 1e5 + 2;
const int MAXK = 101;
int dp[MAXN][MAXK];
vii adj[MAXN];
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    memset(dp,-1,sizeof dp);
    int n,m,k; cin >> n >> m >> k;


    for(int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;

        adj[u].PB({ v, w });
    }

    for(int i = 0; i <=k;i++) dp[1][i] = 0;

    queue<ii> q;
    q.emplace(1,0);

    while(q.size()){

        auto [u,val] = q.front();
        // dbg(u);
        // dbg(val);
        // dbg(dp[u][val]);
        q.pop();
        for(auto & [v,w] : adj[u]){
            int nw = val + w;
            if(nw > k || ~dp[v][nw]) continue; 
            dp[v][nw] = dp[u][val] + 1;
            q.emplace(v,nw);
        }
    }
    int ans = INF;
    for(int i = 0; i <=k;i++){
        // dbg(dp[n][i]);
        if(dp[n][i] != -1) ans = min(ans,dp[n][i]);
    }

    cout << (ans == INF ? -1:ans) << endl;
}