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
#define MAXN 1010101
#define int ll
#define dbg(x) cout << #x << " " << x << endl;
#define endl '\n'

using namespace std;
using namespace __gnu_pbds;

#define ordered_set tree<os_type, null_type, less<os_type>, rb_tree_tag, tree_order_statistics_node_update>



void solve()
{
   
    string s,t; cin >> s >> t;
    int n = s.size();
    unordered_map<char,char> to;
    unordered_map<char,int> cnt;
    bool ans = 1;
    for(int i = 0; i < n && ans;i++){

        if(to.count(s[i]) && t[i] != to[s[i]]) ans = 0;

        if(to.count(s[i]) && to[s[i]] == t[i]) continue;

        to[s[i]] = t[i];
        cnt[t[i]]++;
        if(cnt[t[i]] > 1) ans = 0; 
    }

    cout << (ans ? "YES": "NO") << endl;
    
    // int sla = 0;
    // for(int i = 0; i < n && ans;i++){

    //     char aux = to[s[i]];
    //     dbg(s[i]);
    //     dbg(to[s[i]]);
    //     dbg(to[aux]);
    //     while(aux != s[i]){
    //         dbg(aux);
    //         if(!to.count(aux)){
    //             break;
    //         }
    //         to[s[i]] = to[aux];
    //         to[aux] = aux;
    //         aux = to[s[i]];
    //     }
    // }
    // ans &= (s == t);
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
