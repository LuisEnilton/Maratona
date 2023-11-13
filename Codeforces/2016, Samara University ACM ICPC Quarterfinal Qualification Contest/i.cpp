//
// Created by luise on 13/11/2023.
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


int n,m;
const int maxn = 10e5 + 2;
vi grafo[maxn];
struct Component{
    bool ciclo;
    vi vertices;
    Component(){
        this->ciclo = true;
        this->vertices = vi();
    }
};

vector<bool> visited(maxn + 2,false);
void dfs(int u, int pai,Component &cp){
    if(visited[u]) return;
    cp.vertices.push_back(u);
    if(grafo[u].size()!=2)cp.ciclo = false;
    for(auto v : grafo[u]){
        if(v == pai) continue;
        dfs(v,u,cp);
    }
}

int main()
{
    optimize;
    cin >> n >> m;
    vi resposta(n+1,1);
    while(m--){
        int u,v; cin >> u >> v;
        grafo[u].EB(v);
        grafo[v].EB(u);
    }
    //dfs
    vector<Component> components;
    for(int i = 1 ; i <=n;i++){
        if(visited[i])continue;
        auto cp = *new Component();
        dfs(i,-1,cp);
        components.EB(cp);
    }
    Component ans;
    for(auto cp : components){
        if(cp.ciclo < ans.ciclo){
            if(cp.vertices.size() < ans.vertices.size() || ans.vertices.size() == 0){
                ans = cp;
            }
        }else{
            if(cp.vertices.size() < ans.vertices.size() || ans.vertices.size() == 0){
                ans = cp;
            }
        }
    }
    int cnt;
    if(ans.ciclo){
        cnt = 3;
        for(auto x : ans.vertices){
            if(cnt == 0) break;
            resposta[x] = 0;
            cnt--;
        }
    }else{
        cnt = min((int) ans.vertices.size(),2);
        for(auto x : ans.vertices){
            if(grafo[x].size() <= 1){
                for(int v : grafo[x]){
                    resposta[v] = 0;
                }
                break;
            }
        }
    }
    for(int i = 1; i <=n;i++){
        cout << resposta[i] << " ";
    }
    cout << endl;
    return 0;
}

