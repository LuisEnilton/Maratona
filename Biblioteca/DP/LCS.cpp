//
// Created by Luis on 06/09/2023.
//
//Template By eduardocesb
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define optimize ios::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL);
#define INF 1000000010
#define ALL(x) x.begin(), x.end()
#define ll long long
#define pii pair<int,int>
#define vi vector<int>
#define PB push_back
#define MAXN 3001
#define int ll
#define endl '\n'

using namespace std;
using namespace __gnu_pbds;



pair<int,string> find_lcs(string & s, string & t){
    int n = s.size();
    int m = t.size();

    vector<vi> dp(n + 1,vi(m + 1));

    for(int i = 1; i <=n;i++){
        for(int j = 1; j <=m;j++){
            if(s[i - 1] == t[j - 1]){
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }else{
                dp[i][j] = max(dp[i - 1][j],dp[i][j - 1]);
            }

        }
    }

    int i = n ,j = m;
    string ans;
    while(i > 0 && j > 0){
        if(s[i - 1] == t[j - 1]){
            ans.PB(s[i - 1]);
            i--;
            j--;
        }else if( dp[i - 1][j] >= dp[i][j - 1]){
            i--;
        }else{
            j--;
        }
    }
    reverse(ALL(ans));
    return {dp[n][m],ans};
}


signed main() {
    optimize;
    string s,t;
    cin >> s >> t;
    
    auto [val,ans] = find_lcs(s,t);
    cout << ans << endl;

    return 0;
}

