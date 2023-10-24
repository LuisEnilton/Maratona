//
// Created by Luis on 21/10/2023.
//
//Template By eduardocesb
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <iomanip>
#include <iostream>
#include <ranges>
#include <string_view>
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
#define MAXN 1010
#define MAXL 23
#define EPS 1e-9
#define endl '\n'

using namespace std;
using namespace __gnu_pbds;

#define ordered_set tree<os_type, null_type,less<os_type>, rb_tree_tag,tree_order_statistics_node_update>

int n;
ll grafo[MAXN][MAXN];
vector<int> grafo2[MAXN];
vector<int> pai(MAXN,-1);
ll a,b,x;

vector<ll> dijkstra(int origem){
    //fila.top () = (distancia, vertice)
    priority_queue<pair<ll,int>, vector<pair<ll,int>>, greater<pair<ll,int>>> fila;

    vector<ll> distancias(n+10,INF);

    distancias[origem] = 0;

    fila.push({0,origem});

    vector<bool> visitados(n+10,0);

    while(!fila.empty()){
        auto [dist,atual] = fila.top();

        fila.pop();

        if(visitados[atual]) continue;

        visitados[atual] = true;

        for(auto vizinho : grafo2[atual]){
            if(distancias[vizinho] > dist + grafo[atual][vizinho]){
                //O pai do vizinho é o atual
                pai[vizinho] = atual;
                distancias[vizinho] = dist + grafo[atual][vizinho];
                //o msm vertice pode ser inserido mais de uma vez na fila, mas como ele já foi visitado, não será processado novamente
                fila.push({distancias[vizinho],vizinho});
            }
        }
    }
    return distancias;

}
ll dp[MAXN][2];

ll solve(int currDad,bool carUsed){
    if(pai[currDad] == -1) return 0;

    int v = currDad;
    if(dp[v][carUsed] != -1) return dp[v][carUsed];
    int u = pai[currDad];
    ll car = a * grafo[u][v];
    ll train = b * grafo[u][v] + x;
    ll val2 = INFLL;
    if(!carUsed){
         val2 =  car +solve(u,false);
    }
    ll val1 = train + solve(u,true);
    return dp[v][carUsed] =  min(val1,val2);

}


int main()
{
    optimize;

    cin >> n >> a >> b >> x;
    for(int i = 1; i <= n;i++){
        for(int j = 1;j <= n;j++){
            int c;
            cin >> c;
            if(i == j) continue;
            grafo2[i].EB(j);
            grafo[i][j] = c;
        }
    }
    vector<ll> dist = dijkstra(1);
    memset(dp,-1,sizeof dp);
    int currDad = n;
    ll ans = 0;
    ans = solve(currDad,false);
    cout << ans << endl;
    return 0;
}

