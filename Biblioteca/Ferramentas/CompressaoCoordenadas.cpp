//
// Created by Luis on 15/01/2024.
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

// 0 até n-1
unordered_map<int,ll> mapa;
void compressor(vector<int>& a){
    int n = a.size();
    vector<pair<int, int>> pairs(n);
    for(int i = 0; i < n; ++i) {
        pairs[i] = {a[i], i};
    }
    sort(pairs.begin(), pairs.end());
    int nxt = 0; // MUDAR PRA 1 pra ficar 1-Indexado
    for(int i = 0; i < n; ++i) {
        if(i > 0 && pairs[i-1].first != pairs[i].first) nxt++;
        a[pairs[i].second] = nxt;
        mapa[nxt] = pairs[i].first;
    }
}


int main() {
    optimize;
    vi a = {1,5,3,7,2};
    compressor(a);
    for(auto x : a) cout << x << " ";
    return 0;
}

