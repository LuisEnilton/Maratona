//
// Created by Luis on 15/11/2023.
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

vector<string> split(const string& str, char delimiter) {
    vector<string> tokens;
    size_t start = 0;

    while (start != string::npos) {
        size_t end = str.find(delimiter, start);
        tokens.push_back(str.substr(start, end - start));
        start = (end == string::npos) ? end : end + 1;
    }

    return tokens;
}
const int maxn = 102;
vector<vi> grafo ;

vector<int> cut;
vector<int> pre,low;
int clk = 0;
void tarjan(int u, int p = -1){
    pre[u] = low[u] = clk++;

    bool any = false;
    int chd = 0;

    for(auto v : grafo[u]){
        if(v == p) continue;

        if(pre[v] == -1)
        {
            tarjan(v, u);

            low[u] = min(low[v], low[u]);

            if(low[v] >= pre[u]) any = true;

            chd++;
        }
        else
            low[u] = min(low[u], pre[v]);
    }

    if(p == -1 && chd >= 2) cut.push_back(u);
    if(p != -1 && any)      cut.push_back(u);
}


int main()
{
    optimize;
    int n;
    while(cin >> n && (n!=0)){
        int u;
        grafo.clear();
        grafo.resize(n+1);
        low.clear();
        low.resize(n+1);
        pre.clear();
        pre.resize(n+1);
        cut.clear();
        fill(ALL(pre),-1);
        while(cin >> u && (u!=0)){
            cin.ignore();
            string s;
            getline(cin,s);
            auto x = split(s,' ');
            for(auto num : x){
                int v = stoi(num);
                grafo[u].EB(v);
                grafo[v].EB(u);
            }
        }
        tarjan(1);
        cout << cut.size() << endl;
    }
    return 0;
}

