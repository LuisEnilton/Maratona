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
#define ll long long
#define pii pair<int, int>
#define vi vector<int>
#define vb vector<bool>
#define vii vector<pii>
#define os_type int
#define PB push_back
#define EB emplace_back
#define MOD 1000000007
#define MAXN 1010101
#define int ll
#define dbg(x) cout << #x << " " << x << endl;
// #define endl '\n'
#define print_arr(a)      \
    for (auto x : a)      \
        cout << x << " "; \
    cout << endl;
using namespace std;
using namespace __gnu_pbds;

#define ordered_set tree<os_type, null_type, less<os_type>, rb_tree_tag, tree_order_statistics_node_update>

void solve()
{
    int n; cin >> n;
  
    int def = 10;

    vi b10 = {1,10,100};

    while(n--){
        string s; cin >> s;
        int ans = 0;
        if(s == "/"){
            ans = def;
        }else{
            int curr = 0;
            // dbg(s);
            for(int i = 0; i < s.size();i++){
                curr += (s[i] - '0') * b10[s.size() - i - 1];
            }
            
            int arredonda_cima = curr + 10;
            arredonda_cima -= (arredonda_cima % 10);
            def = max(def,arredonda_cima);
            ans = curr;
        }
        cout << ans << endl;
    }



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
