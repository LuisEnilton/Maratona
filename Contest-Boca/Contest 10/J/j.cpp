//
// Created by Luis on 26/08/2023.
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


int main(int argc, char **argv) {
    //optimize;
    ll n, k;
    cin >> n >> k;
    //cout << n << endl;
    if (k == 1) {
        cout << 1 << endl;
        return 0;
    }
    // dado um n , queremos um numero <= a k que o resta seja o maior possivel ou seja igual a 0

    if(n % k == 0){
        cout << k << endl;
        return 0;
    }
    if(k > n){
        cout << n << endl;
        return 0;
    }

    ll ans = 0;
    if(n & 1){
        if(k >= n/2+1){
            ans = n/2 ;
            cout << ans << endl;
            return 0;
        }
    }else{
        if(k >= n/2){
            ans = n/2;
            cout << ans << endl;
            return 0;
        }
    }

    for(ll i = k ; i >=k/2;i--){
        ll op2;
        if(n % i == 0) {
            op2 = i;
        }else
            op2 = n % i;
        ans = max(ans,op2);
    }

    cout << ans  << endl;

    return 0;
}

