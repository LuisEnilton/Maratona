//
// Created by Luis on 07/08/2023.
//
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


int main(int argc, char** argv)
{
    optimize;
    int t;
    cin >> t;
    while(t--){

        int n;
        string s;
        cin >> s;
        n = s.size();
        int i;
        int ultimo = n;
        for( i =0;i < n;i++){
            if(s[i] - '0' >= 5){
                ultimo = i;
            }
        }
        if(ultimo == n){
            cout << s << endl;
            continue;
        }
        i = ultimo;
        string ans = "0";
        ans+=s;
        bool limpo = false;
        while(true){
            if(ans[i+1] - '0' < 5){
                i--;
                continue;
            }
            ans[i+1] = '0' ;
            int d = i;
            while(ans[d] == '9'){
                d--;
            }
            ans[d] = ans[d] + 1;
            ans[i] = ans[d];
            for(int j = i+1;j <=n && !limpo;j++){
                ans[j] = '0';

            }
            if( i == 1) break;
            limpo = true;
            i--;
        }
        if(ans[0] == '0')
            cout << ans.substr(1,n) << endl;
        else
            cout << ans << endl;
    }
    return 0;
}

