//
// Created by luise on 23/10/2023.
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
#define MAXN 1010101
#define MAXL 23
#define EPS 1e-9
#define endl '\n'

using namespace std;
using namespace __gnu_pbds;

#define ordered_set tree<os_type, null_type,less<os_type>, rb_tree_tag,tree_order_statistics_node_update>




int main()
{
    optimize;
    int n,m; cin >> n >> m;
    vector<ll> carros(n);
    for(auto &x : carros) cin >> x;
    sort(ALL(carros));
    priority_queue<pair<ll,ll>> pq;
    for(int i = 0; i < m;i++){
        int mec; cin >> mec;
        pq.push({0,mec});
    }
    ll ans = 0;
    for(int i = 0; i < n;i++){
        auto atual = pq.top();
        pq.pop();
        ll valor = -atual.first;
        ll tempo = -atual.first + (atual.second * carros[i]);
        pq.push({-tempo,atual.second});
        ans+=valor;
    }
    cout << ans << endl;
    return 0;
}

