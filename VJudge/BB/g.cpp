//
// Created by Luis on 06/09/2023.
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
string s;
int n;
vector<vi > ps;
bool check(int m){
    for(int i = 0 ; i < 26;i++){
        bool ok = true;
        //0abc
        for(int j = 1; j - 1<= n -m ;j++){
            int q = ps[i][j + m - 1] - ps[i][j - 1];
            if(q == 0){
                ok = false;
                break;
            }
        }
        if(ok) return true;
    }
    return false;
}

int main() {
    optimize;
    cin >> s;
    n = s.size();
    ps = vector<vi >(26, vi(n + 1));

    for (int i = 1; i <= n; i++) {
        int idx = s[i - 1] - 'a';
        ps[idx][i] = 1;
        for (int j = 0; j < 26; j++) {
            ps[j][i]+= ps[j][i - 1];
        }
    }
    int ans;
    int l = 1 , r = n;
    while(l<=r){
        int m = (l+r)/2;
        if(check(m)){
            ans = m;
            r = m-1;
        }else{
           l =  m + 1;
        }
    }
    cout << ans << endl;
    return 0;
}

