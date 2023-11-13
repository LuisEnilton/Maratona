//
// Created by Luis on 09/11/2023.
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


int quantDig(int num){
    return floor(log(num)) + 1;
}

int main()
{
    optimize;
    int n; cin >> n;
    vector<int> dp(n + 1,INF);
    dp[0] = 0;
    for(int i = 1; i <=9;i++){
        if(n == i) {
            cout << 1 << endl;
            return 0;
        }
        dp[i] = 1;
    }

    for(int i = 10; i <=n;i++){
        int aux = i;
        for(int j = 0; j < quantDig(i);j++){
            int dig = aux% 10;
            dp[i] = min(dp[i - dig] + 1,dp[i]);
            aux/=10;
        }
    }
    cout << dp[n] << endl;
    return 0;
}

