//Template By eduardocesb
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define optimize ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define INF 1000000010
#define INFLL 1000000000000000010LL
#define ALL(x) x.begin(), x.end()
#define UNIQUE(c) (c).resize(unique(ALL(c)) - (c).begin())
#define REP(i, a, b) for(int i = (a); i <= (b); i++)
#define POS(n, x) (lower_bound(ALL(n), x) - (n).begin())
#define ll long long
#define ld long double
#define pii pair<int,int>
#define vi vector<int>
#define vii vector<pii>
#define os_type int
#define PB push_back
#define EB emplace_back
#define MOD 1000000007
#define PRIME 101
#define MAXN 1010101
#define MAXL 23
#define EPS 1e-9
#define endl '\n'

using namespace std;
using namespace __gnu_pbds;

#define ordered_set tree<os_type, null_type,less<os_type>, rb_tree_tag,tree_order_statistics_node_update>

vi Zfunction(string &s) {
    int n = s.size();
    vi z(n);

    for (int i = 1, l = 0, r = 0; i < n; i++) {
        if (i <= r) z[i] = min(z[i - l], r - i + 1);

        while (z[i] + i < n && s[z[i]] == s[i + z[i]]) z[i]++;

        if (r < i + z[i] - 1) l = i, r = i + z[i] - 1;
    }

    return z;
}

int main(int argc, char** argv)
{
    optimize;
    string s,t;
    while(getline(cin,s),getline(cin,t) ){
        int sz1= s.size(),sz2 = t.size();
        int ans = 0;
        for(int i =0;i < sz2;i++){
            string copia = t.substr(i,sz2-i);
            copia+=s;
           // cerr << copia << endl;
            vi prefs = Zfunction(copia);
          //  for(auto x : prefs) cerr << x <<" ";
           // cerr << endl;
            for(int j = sz2 - i; j < sz1 + sz2 - i;j++) {
                int val = min(sz2-i,prefs[j]);
                ans = max(ans,val);

            }
        }
        cout << min(ans,sz2) << endl;
    }
    return 0;
}


