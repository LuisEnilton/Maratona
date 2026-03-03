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
    int n; cin >> n;


    unordered_map<string,int> freq;
    freq.reserve(n);
    for(int i = 0; i < n;i++){
        string  s; cin >> s;

        int curr = 0;
        vi to(26,-1);
        for(auto & c : s){

            if(to[c - 'a'] == -1) to[c - 'a'] = curr++;


            c = char('a' + to[c - 'a']);
        }
        freq[s]++;
    }
    int ans = 0;
    for(auto &[k,v] : freq){

        int val = ((v) * (v - 1))/2;
        ans += val;
    }

    cout << ans << endl;




}

signed main()
{
    optimize;
    int t = 1;
    //  cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
