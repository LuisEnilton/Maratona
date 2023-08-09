//
// Created by luise on 09/08/2023.
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
    int q;
    cin >> q;
    while(q--){
        string s;
        cin >> s;
        int n = s.size();
        string ans ="";
        if(n == 1){
            cout <<s << s << endl;
            continue;
        }
        if(s[0]!= s[1]){
            ans+=s[0];
            ans+=s[0];
        }else{
            ans+=s[0];
        }
        for(int i = 1 ; i < n-1;i++){
            if(s[i] != s[i-1] && s[i]!=s[i+1]){
                ans+=s[i];
                ans+=s[i];
            }else{
                ans+=s[i];
            }
        }
        if(s[n-1]!=s[n-2]){
            ans+=s[n-1];
            ans+=s[n-1];
        }else{
            ans+=s[n-1];
        }
    cout << ans << endl;
    }
    return 0;
}


