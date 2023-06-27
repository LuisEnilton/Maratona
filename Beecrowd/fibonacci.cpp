#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <string>
#include <algorithm>
#include <set>
#define optimize                 \
    ios::sync_with_stdio(false); \
    cin.tie(NULL);               \
    cout.tie(NULL)
#define INF 100000010
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
#define MAXN 101010
#define MAXL 23
#define endl '\n'

using namespace std;
using namespace __gnu_pbds;

#define ordered_set tree<os_type, null_type, less<os_type>, rb_tree_tag, tree_order_statistics_node_update>
using namespace std;

int q;

int dp [ MAXN ];
int dpCalls [ MAXN ];


    int fib(int n){
        if(n == 0) 
            return 0;
        
        if(n == 1) 
            return 1;
        
        if(dp[n] != -1)
            return dp[n];
        
        return dp[n] = fib(n-1) + fib(n-2);;
    
        
    }

    int fibCalls(int n){
        if(n == 0) 
            return 0;
        
        if(n == 1) 
            return 0;
        
        if(dpCalls[n] != -1)
            return dpCalls[n];
        
        dpCalls[n] = 2 + fibCalls(n-1) + fibCalls(n-2);
        return dpCalls[n];
        
    }
    
    int n;

int main()
{
    memset(dp, -1, sizeof dp);
    memset(dpCalls, -1, sizeof dpCalls);
    cin>>q;
    for (size_t i = 0; i < q; i++)
    {
        cin>>n;
        printf("fib(%d) = %d calls = %d\n", n, fibCalls(n), fib(n));
    }
}
