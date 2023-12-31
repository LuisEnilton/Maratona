//
// Created by Luis on 28/07/2023.
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

int n ,t;
int main(int argc, char** argv)
{
    optimize;
    cin >> n >> t;
    vii cartas(n+1);

    for(int i =1;i <=n;i++) {
        cin >> cartas[i].first;
    }

    for(int i =1;i <=n;i++) {
        cin >> cartas[i].second;
    }
    vi mudancas(n+2,0);

    while(t--){
        int l ,r;
        cin >> l >> r;
        mudancas[l]+= 1;
        mudancas[r + 1] -= 1;
    }

    int prefix_sum[n+1];
    prefix_sum[0] =0;

    for(int i =1;i <=n;i++){
        prefix_sum[i] = prefix_sum[i-1] + mudancas[i];
    }

    for(int i =1;i<=n;i++){
        if(prefix_sum[i] % 2 == 0){
            cout << cartas[i].first << " ";
        }else{
            cout << cartas[i].second << " ";
        }
    }
    cout << endl;

    return 0;
}