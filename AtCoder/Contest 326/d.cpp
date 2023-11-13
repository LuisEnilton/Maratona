//
// Created by Luis on 28/10/2023.
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
    int n;
    cin >> n;
    vector<vector<char>> grid(n,vector<char>(n,'.'));
    vi freqRow(n);
    vi freqCol(n);
    vi freqR(3);
    vi freqC(3);
    string r,c;
    cin >> r >> c;
    for(auto ch: r){
        freqR[ch-'a']++;
    }
    for(auto ch: c){
        freqR[ch-'a']++;
    }
    int idx = 0;
    for(int i = 0 ; i < n;i++){
        if(r[i] == c[i]){
            grid[0][i] = r[i];
            break;
        }
        cout << "No" << endl;
        return 0;
    }


    return 0;
}

