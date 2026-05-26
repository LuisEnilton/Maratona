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
#define dbg(x) cout << #x << " " << x << endl;
#define endl '\n'

using namespace std;
using namespace __gnu_pbds;

#define ordered_set tree<os_type, null_type, less<os_type>, rb_tree_tag, tree_order_statistics_node_update>


struct SparseTable
{

    vector<vi> m;
    int n, maxl;
    SparseTable(vi &a)
    {
        n = a.size();
        maxl = log2(a.size()) + 1;
        m.resize(n, vi(maxl, 1));
        precalc(a);
    }

    void precalc(vi &a)
    {
        for (int i = 0; i < n; i++)
            m[i][0] = a[i];
        for (int k = 1; k < maxl; k++)
        {
            for (int i = 0; i + (1 << k) - 1 < n; i++)
            {
                m[i][k] = max(m[i][k - 1], m[i + (1 << (k - 1))][k - 1]);
            }
        }
    }
    int query(int l, int r)
    {
        // RODAR O PRECALC
        int j = __builtin_clz(1) - __builtin_clz(r - l + 1);

        return max(m[l][j], m[r - (1 << j) + 1][j]);
    }
};


void solve()
{
    int n,q; cin >> n >> q;
    string s; cin >> s;

    vi ps(n + 1);

    unordered_map<int,vi> pos; // posiçao que esse valor aparece
    pos.reserve(n);
    for(int i = 1; i <=n;i++){
        ps[i] = ps[i -1] + (s[i - 1] == '*' ? 1:-1);
        pos[ps[i]].push_back(i);
        // cout << ps[i] << " ";
    }
    // cout << endl;
    auto st = SparseTable(ps);

    while(q--){

        int l,r; cin >> l >> r;
        // procura a 1 posicao que fica negativo, o valor fica 0 e não da de arrumar mais nada
        int ans = 0;
        // dbg(val);
        auto & arr = pos[ps[l - 1] - 1];
        auto ponta = lower_bound(ALL(arr),l);
        int indice_ponta = (ponta == arr.end() ? INF:*ponta);
        // dbg(indice_ponta);
        if(indice_ponta <= r){
            ans++; // ficou 0
            r = indice_ponta;
        }
        int maxi = st.query(l - 1 ,r);
        // dbg(maxi);
        ans += (maxi - ps[l - 1] + 1);
        cout << ans << endl;
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
