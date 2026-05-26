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

vi find_dig(int x){
    vi resp;
    while(x > 0){
        resp.PB(x % 10);
        x/=10;
    }
    reverse(ALL(resp));
    return resp;
}

int digProb;
int calc(int x){
    if(x == 0) return digProb == 0;
    // dbg(x);
    auto dig = find_dig(x);

    int q = dig.size();
    for(int i = 0; i < q;i++){
        if(dig[i] == digProb){
            int val = q - i;

            // int b10 = pow(10,val); // se eu tiver nos digitos de 100, eu quero o resto da div por 1000
            int b102 = pow(10,val - 1);
            
            int resto = x % b102;
            int curr = (x + (b102 - resto));
            
            return (b102 - resto) + calc(curr);
        }
    }
    return 0;

}


void solve()
{
    int n; cin >> n >> digProb;

    auto ans = calc(n);

    cout << ans << endl;
    // eu resolvo primeiro pro digito mais significativo


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
