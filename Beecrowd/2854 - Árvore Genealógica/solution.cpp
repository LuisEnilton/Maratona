//
// Created by luise on 07/07/2023.
//
//By eduardocesb
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

int N, M;

map<string, string> pai;
map<string, int> altura;


string find(string s) {
    if (pai[s] == s) return s;
    return  pai[s] = find(pai[s]);
}

string join(string u, string v) {
    u = find(u);
    v = find(v);

    if (altura[u] > altura[v])
        swap(u, v);

    pai[u] = v;

    if (altura[u] == altura[v])
        altura[v]++;
}

int main(int argc, char **argv) {
    optimize;
    cin >> M >> N;

    for (int i = 0; i < N; i++) {
        string u, r, v;
        cin >> u >> r >> v;
        cin.ignore();
        if (altura.count(u) == 0){
            altura[u] = 1;
            pai[u] = u;
        }

        if (altura.count(v) == 0){
            altura[v] = 1;
            pai[v] = v;
        }
        join(u,v);
        cout << u << " " << r << " " << v << endl;
    }

    set <string> pais;
    for (auto ele: pai) {
        string s = find(ele.first);
        pais.insert(s);
    }
    cout << pais.size() << endl;

    return 0;
}