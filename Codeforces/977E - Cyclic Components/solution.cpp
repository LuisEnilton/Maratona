//
// Created by Luis on 14/09/2023.
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
const int maxn = 2*10e5 + 5;
vector<bool> visited(maxn,false);
int n,m;
vi grafo[maxn];
int cnt = 0;
bool ok1 = false;
bool ok2 = false;
void dfs(int u,int p = -1){

    stack<pii> pilha;
    pilha.emplace(u,-1);
    while(!pilha.empty()){
        auto [atual,pai] = pilha.top();
        if(grafo[atual].size() !=2) {
            //cerr << "opa " << atual <<  endl;
            ok1 = false;
        }
        pilha.pop();
        if(visited[atual]) {
            if(atual == u){
                //cout << "eita " << pai << " " << atual << endl;
                ok2 = true;
            }
            continue;
        }
        visited[atual] = true;
        for(auto v : grafo[atual]){
            if(v == pai) continue;
             pilha.emplace(v,atual);
        }
    }

}

void solve(){
    for(int i = 1; i <= n;i++){
        ok1 = true;
        ok2 = false;
        if(visited[i]) continue;
        dfs(i);
        if(ok1 && ok2) cnt++;
    }
}



int main(int argc, char** argv)
{
    optimize;
    cin >> n >> m;
    for(int i =0; i < m;i++){
        int u,v; cin >> u >> v;
        grafo[u].EB(v);
        grafo[v].EB(u);
    }
    solve();
    cout << cnt << endl;
    return 0;
}

