//
// Created by Luis on 19/02/2024.
//
//Template By eduardocesb
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <cmath>

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

vector<char> letter = {'A','T','G','C'};

int pos(char c){
    if(c == 'A') return 0;
    if(c == 'T') return 1;
    if(c == 'G') return 2;
    return 3;
}

void at(vector<vi>& ps,int i){
    if(i==0) return;
    for(int j = 0;j< 4;j++){
        ps[j][i] = ps[j][i-1];
    }
}

int main() {
    optimize;
    string s; cin >> s;
    int q; cin >> q;
    int n = s.size();
    vector<vi> ps(4,vi(n));
    for(int i = 0;i < n;i++){
        at(ps,i);
        int idx = pos(s[i]);
        ps[idx][i]++;
    }
    //GCTCT
    while(q--){
        int l,r; cin >> l >> r;
        l--,r--;
        int l2 = max(0,l-1);
        set<pii> aux;
        for(int i =0;i < 4;i++){
            int x = ps[i][r] - ps[i][l2];
            if(l == r)
                x = s[l] == letter[i];
            aux.insert({x,-i});
        }
        string ans;
        for(auto x : aux){
            int idx = -x.second;
            ans.push_back(letter[idx]);
        }
        reverse(ALL(ans));
        cout << ans << endl;
    }
    return 0;
}
/*
 AAAAAGTAAA
 3
1 10
6 10
6 6

 TATATGCTCT
1
1 1
 * */
