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
    int ans = 0;
    int val = INF;
    for(int i = 1; i <=n;i++){
        if(grafo[i].size() < val){
            ans = i;
            val = grafo[i].size();
        }
    }
    resposta[ans] = 0;
    for(auto v : grafo[ans]){
        resposta[v] = 0;
    }
    for(int i = 1; i <=n;i++){
        cout << resposta[i] << " ";
    }
    cout << endl;
    return 0;
}

