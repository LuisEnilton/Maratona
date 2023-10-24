//
// Created by luise on 24/10/2023.
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


void solve(){
    int n;cin >> n;
    unordered_map<int, ll> ans;
    vector<ll> points(n);
    for(auto &p: points) cin >> p;
    vector<ll> aux = points;
    sort(ALL(aux));
    ll val = aux[0];
    ll sum = 0;
    for(int i = 0; i < n;i++){
        sum+=(aux[i] - val + 1);
    }
    ans[aux[0]] = sum;
    for(int i = 1;i < n;i++){
        ll dif = (aux[i] - aux[i - 1]);
        ll menor = i;
        ll maior = n-i;
        ans[aux[i]] = ans[aux[i-1]] + menor *dif - maior *dif;
    }
    for(auto x : points){
        cout << ans[x] << " ";
    }
    cout << endl;
}


int main()
{
    optimize;
    int t;cin >> t;
    while(t--){
        solve();
    }
    return 0;
}

