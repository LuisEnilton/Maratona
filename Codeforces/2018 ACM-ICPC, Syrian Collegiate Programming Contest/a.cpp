//
// Created by Luis on 06/09/2023.
//
// Template By eduardocesb
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define optimize                 \
    ios::sync_with_stdio(false); \
    cin.tie(NULL);               \
    cout.tie(NULL);
#define INF 1000000010
#define INFLL 1000000000000000010LL
#define ALL(x) x.begin(), x.end()
#define ll long long
#define pii pair<int, int>
#define vi vector<int>
#define vb vector<bool>
#define vii vector<pii>
#define os_type int
#define PB push_back
#define EB emplace_back
#define MOD 1000000007
#define MAXN 300010
#define MAXL 20
#define int ll
#define EPS 1e-9
#define dbg(x) cout << #x << " " << x << endl;
#define endl '\n'
using namespace std;

string s; 

vector<vi> dp;



void solve()
{
    vi a(12);
    for(auto & x : a) cin >> x;
    bool ans = 1;
    for(int i = 1; i < 4;i++) if(a[i] < a[i - 1]) ans = 0;
    // dbg(ans);
    int mini = INF;
    for(int i = 4; i < 12;i++) mini = min(mini,a[i]);
    // dbg(mini);
    if(mini < a[3]) ans = 0;

    cout << (ans ? "yes":"no") << endl;
}

signed main()
{
    optimize;
    freopen("hello.in","r",stdin);
    // freeopen("hello.in","w");

    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
