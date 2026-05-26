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
#define pii pair<int, int>
#define vi vector<int>
#define vb vector<bool>
#define BT bitset<500>
#define vii vector<pii>
#define os_type int
#define PB push_back
#define EB emplace_back
#define MOD 1000000007
#define MAXN 1000010
#define int ll
#define dbg(x) cout << #x << " " << x << endl;
#define endl '\n'

using namespace std;
using namespace __gnu_pbds;

#define ordered_set tree<os_type, null_type, less<os_type>, rb_tree_tag, tree_order_statistics_node_update>

void solve()
{
    int n,q; cin >> n >> q;
    
    // primeiro indice diferente da primeira letra
    auto find_p = [&](string & aux){

        for(int i = 0 ; i < aux.size() ;i++){
            if(aux[i] != aux[0]) return i;
        }
        return -1LL;
    };


    string s; cin >> s;
    auto idx = find_p(s);

    while(q--){
        string t; cin >> t;

        auto aux_idx = find_p(t);

        int ans = max(s.size(),t.size());

        if(t[0] == s[0]){

            if(idx != -1){
                int sz = (n - idx) + t.size();
                ans = max(ans,sz);
            }

            if(aux_idx != -1){
                int sz = (t.size() - aux_idx) + s.size();
                ans = max(ans,sz);
            }
        }else{
            ans = t.size() + s.size();
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
