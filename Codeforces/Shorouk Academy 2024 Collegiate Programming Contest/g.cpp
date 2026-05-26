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
   string p; cin >> p;

    vector<string> names(n);
    for(auto & x : names) cin >> x;
    vi val(n); // qtd em cada estudante
    

    int q; cin >> q;
    set<pii> score; // (valor,id)
    while(q--){
        string op; cin >> op;

        if(op == "bonus"){
            int id,s; cin >> id >> s;
            id--;
            string pass; cin >> pass;
            // dbg(id);
            // dbg(s);
            if(pass != p){
                cout << "Wrong password please try again" << endl;
                cout << "---" << endl;
                continue;
            }

            int v = val[id];
            if(v == 0){
                score.emplace(-s,id);
                val[id] = s;
            }else{
                pii fnd = {-v,id};
                score.erase(fnd);
                score.emplace(-(v + s),id);
                val[id] = v + s;
            }
            cout << "Updated successfully" << endl;
        }else{
            int rnk = 1;
            // for(auto [v , id] : score){
            //     cout << v << " " << id << endl;
            // }
            for(auto it = score.begin();it != score.end();){
                auto [v,id] = *it;
                
                while(it != score.end() && (*it).first == v) {
                    auto [v2,id2] = *it;
                    cout << rnk << " " << id2 + 1 << " " << names[id2] << " " << -v << endl; 
                    it++;
                }
                rnk++;
            }

        }
        cout << "---" << endl;
    }


}

signed main()
{
    optimize;
    int t = 1;
    //   cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
