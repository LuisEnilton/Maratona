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
    int n;
    cin >> n;

    vi maxi(n), sla(n), menor(n);

    for (int i = 0; i < n; i++)
    {

        int a, b, c;
        cin >> a >> b >> c;
        vi aux = {a,b,c};
        sort(ALL(aux));
        maxi[i] = aux[2];
        sla[i] = aux[1];
        menor[i] = aux[0];
    }
    auto meio = sla;
    sort(ALL(sla));
    sort(ALL(menor));
    vi ans;
    for(int i = 0; i < n;i++){

        auto it = upper_bound(ALL(sla), maxi[i]);
        auto it2 = upper_bound(ALL(menor),meio[i]);
        if(it == sla.end() && it2 == menor.end()){
            ans.PB(i + 1);
        }
    }

    cout << ans.size() << endl;

    for(auto x : ans){
        cout << x << " ";
    }
    cout << endl;
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
