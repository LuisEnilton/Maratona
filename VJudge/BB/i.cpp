//
// Created by Luis on 06/09/2023.
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


int main() {
    optimize;
    int n;
    cin >> n;
    map<ll,int> freq, q;
    ll sum = 0;
    freq[0] = 1;
    ll ans = 0;
    for (int i = 1; i <= n; i++) {
        ll x; cin >> x;
        sum+=x;
        ll mod;
        if(sum < 0){
            //((a%n)+n)%n
            mod = ((sum % n) + n) %n;
        }else{
            mod = sum % n;
        }
        ans+= freq[mod];
        freq[mod]++;
        q[sum]++;
    }
    cout << ans << endl;
    return 0;
}

/*
  5
  5 3 7 -3 -7
0 5 8 15 12 5

 5
 0 0 0 0 0
 6
 2 1 -3 2 -7 7
 * */