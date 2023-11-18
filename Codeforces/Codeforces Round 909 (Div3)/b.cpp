//
// Created by Luis on 17/11/2023.
//
//
// Created by Luis on 17/11/2023.
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


void solve(){
    int n; cin >> n;
    vector<ll> ps(n);
    ll maior = 0,menor =INFLL;
    for(int i = 0; i < n;i++){
        ll val; cin >> val;
        maior = max(maior,val);
        menor = min(menor,val);
        if(i == 0){
            ps[0] = val;
            continue;
        }
        ps[i] = ps[i-1] + val;
    }
    ll ans = (maior - menor);
    for(int i = 2; i <=n/2;i++){
        if( n % i == 0){
            ll ma = 0,me = INFLL;
            for(int j = i - 1; j < n;j+=i){
                if(j == (i-1)){
                    ma = max(ma,ps[j]);
                    me = min(me,ps[j]);
                }else{
                    ma = max(ma,ps[j] - ps[j-i]);
                    me = min(me,ps[j] - ps[j-i]);
                }
            }
            ans = max(ans,ma - me);
        }
    }
    cout << ans << endl;
}

int main()
{
    optimize;
    int t; cin >> t;
    while(t--){
        solve();
    }
    return 0;
}

