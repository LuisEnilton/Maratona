//
// Created by Luis on 06/09/2023.
//
// Template By eduardocesb
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define optimize                 \
    ios::sync_with_stdio(false); \
    cin.tie(NULL);
#define INF 1000000010
#define INFLL 1000000000000000010LL
#define ALL(x) x.begin(), x.end()
#define ll long long
#define pii pair<int, int>
#define vi vector<int>
#define vb vector<bool>
#define BT bitset<500>
#define vii vector<pii>
#define os_type int
#define PB push_back
#define EB emplace_back
#define MOD 1000000007
#define MAXN 1000010
#define int ll
#define dbg(x) cout << #x << " " << x << endl;
#define endl '\n'

using namespace std;
using namespace __gnu_pbds;

#define ordered_set tree<os_type, null_type, less<os_type>, rb_tree_tag, tree_order_statistics_node_update>

const int MAXV=  1e7 + 5;
int lp[MAXV]; // menor primo que divide
bool n_primo[MAXV];
void solve()
{

    for(int i = 2; i < MAXV;i++){
        if(n_primo[i]) continue;
        lp[i] = i;
        for(int j = i * i; j < MAXV;j += i){
            lp[j] = i;
            n_primo[j] = 1;
        }
    }


    int n; cin >> n;
    vi a(n);
    for(auto & x : a) cin >> x;

    map<int,int> sum; // pra cada primo a soma

    auto fatora = [&](int val){

        while(val > 1){
            sum[lp[val]] += lp[val];
            val = val/lp[val];
        }
        return;
    };

    for(auto x : a){
        fatora(x);
    }


    vi sla;
    for(auto [k,v] : sum){
        // dbg(k);
        // dbg(v);
        sla.push_back(v);
    }
    sort(ALL(sla));
    reverse(ALL(sla));
    int ans = 0;
    for(int i = 0 ; i < sla.size();i += 2){
        ans += sla[i];
    }
    cout << ans << endl;
}


signed main()
{
    optimize;

    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}