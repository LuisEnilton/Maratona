//
// Created by Luis on 15/09/2023.
//
// Template By eduardocesb
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define optimize                 \
    ios::sync_with_stdio(false); \
    cin.tie(NULL);               \
    cout.tie(NULL)
#define INF 1000000010
#define INFLL 1000000000000000010LL
#define ALL(x) x.begin(), x.end()
#define UNIQUE(c) (c).resize(unique(ALL(c)) - (c).begin())
#define REP(i, a, b) for (int i = (a); i <= (b); i++)
#define POS(n, x) (lower_bound(ALL(n), x) - (n).begin())
#define ll long long
#define ld long double
#define pii pair<int, int>
#define vi vector<int>
#define vii vector<pii>
#define os_type int
#define PB push_back
#define EB emplace_back
#define MOD 1000000007
#define PRIME 101
#define MAXN 100010
#define MAXL 23
#define EPS 1e-9
#define endl '\n'
#define int ll
using namespace std;
using namespace __gnu_pbds;
#define ordered_set tree<os_type, null_type, less<os_type>, rb_tree_tag, tree_order_statistics_node_update>


vi v,w;
int n, maxW;
// O(N * W)
// Qual o valor maximo carregando conjunto de itens com peso até W
vi knapsack(){
    vi dp(maxW + 1);

    for(int peso = 0;peso <= maxW;peso++){
        dp[peso] = (peso >= w[0] ? v[0]: 0);
    }

    for(int i = 1; i < n;i++){
        vi ndp = dp;
        for(int peso = 0; peso <=maxW;peso++){

            if(peso >= w[i]) ndp[peso] = max(ndp[peso],v[i] + dp[peso - w[i]]);
        }
        dp = ndp;
    }
    return dp;
}


// O(N & sum(vi))
// Calcula pra cada valor V, qual o peso minimo com o qual ele pode ser formado
// no ultimo nivel na dp procuramos o valor maximo que tenha peso <= maxW
vi knapsack_2(int sum){
    vi dp(sum + 1, INFLL);

    dp[0] = 0;
    dp[v[0]] = w[0];

    for (int i = 1; i < n; i++)
    {
        vi new_dp = dp;
        for (int val = v[i]; val <= sum; val++)
        {

            new_dp[val] = min(new_dp[val], dp[val - v[i]] + w[i]);
        }
        dp = new_dp;
    }
    
}



signed main()
{
    optimize;
    
    cin >> n >> maxW;
    v = w = vi(n);
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> w[i] >> v[i];
        sum += v[i];
    }

    auto dp = knapsack_2(sum);
    int ans = 0;
    for (int val = sum; val >= 0; val--)
    {
        if (dp[val] <= maxW)
        {
            ans = val;
            break;
        }
    }

    cout << ans << endl;

    return 0;
}