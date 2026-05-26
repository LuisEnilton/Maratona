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
#define int ll
#define pii pair<int, int>
#define vi vector<int>
#define vb vector<bool>
#define BT bitset<500>
#define vii vector<pii>
#define os_type int
#define PB push_back
#define EB emplace_back
#define MOD 1000000007
#define MAXN 1010101
#define dbg(x) cout << #x << " " << x << endl;
#define endl '\n'

using namespace std;
using namespace __gnu_pbds;

#define ordered_set tree<os_type, null_type, less<os_type>, rb_tree_tag, tree_order_statistics_node_update>


void solve()
{
    int x; cin >> x;

    if(x == 1){
        cout << -1 << endl;
        return;
    }

    // auto div = [&](int x){
    //     vi divi;
    //     for(int i = 2; i * i <=x;i++){
    //         if(x % i == 0) {
    //             divi.push_back(i);
    //             divi.push_back(x/i);
    //         }
    //     }
    //     return divi;
    // };


    if(x & 1){
        cout << x/2 << " " << x/2 + 1 << endl;
    }else{
        
        int sum = 1;
        bool ok = 0;
        for(int n = 2;sum <=x;n++){
            sum += n;
            if(sum == x){
                cout << 1 << " " << n << endl;
                ok = 1;
                break;
            }

            if((x - sum) % n != 0) continue;

            int k = (x - sum) / n;
            cout << 1 + k << " " << k + n << endl;
            ok = 1;
            break;
        }
        if(!ok) cout << -1 << endl;
    }
    

}

signed main()
{
    optimize;
    int t = 1;
      cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
