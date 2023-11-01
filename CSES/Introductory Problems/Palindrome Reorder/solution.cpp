//
// Created by luise on 30/10/2023.
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




int main()
{
    optimize;
    string s;
    vector<int> freq(26);
    cin >> s;
    for(auto c : s)
        freq[c - 'A']++;

    int cntImpar = 0;
    char centerLetter;
    int i = 0;
    char lt;
    for(auto x : freq){
        if(x & 1){
            cntImpar++;
            lt = 'A' + i;
        }else
        i++;
    }
    if(cntImpar > 1){
        cout << "NO SOLUTION" <<endl;
        return 0;
    }
    string ans = "";
    for(int j = 0; j < freq[lt -'A'] ; j++ ){
        ans+= lt;
    }
    for(int j = 0; j < 26;j++){
        if(freq[j] % 2 == 0 && freq[j] > 0){
            char lett = 'A' + j;
            for(int k = 0; k < freq[j]/2;k++){
                ans = lett + ans + lett;
            }
        }
    }
    cout << ans << endl;

    return 0;
}

