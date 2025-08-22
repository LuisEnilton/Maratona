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
#define UNIQUE(c) (c).resize(unique(ALL(c)) - (c).begin())
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
#define MAXN 400010
#define int ll
#define endl '\n'

using namespace std;
using namespace __gnu_pbds;

#define ordered_set tree<os_type, null_type, less<os_type>, rb_tree_tag, tree_order_statistics_node_update>



int calc(int x){
    int sum = 0;
    while(x > 0){
        sum += x % 10;
        x/=10;
    }

    return sum;

}



signed main()
{
    optimize;
    int s,a,b; cin >> s >> a >> b;
    int ans1,ans2;
    for(int i = a; i <= b;i++){
        if(calc(i) == s){
            ans1 = i;
            break;
        }
    }

     for(int i = b; i >= a;i--){
        if(calc(i) == s){
            ans2 = i;
            break;
        }
    }
    cout << ans1 << endl;
    cout << ans2 << endl;
    return 0;
}