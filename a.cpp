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
#define MAXN 5010
#define MAXL 23
#define EPS 1e-9
#define endl '\n'

using namespace std;
using namespace __gnu_pbds;

#define ordered_set tree<os_type, null_type,less<os_type>, rb_tree_tag,tree_order_statistics_node_update>

struct Trie {
    vector<vi > to;
    vector<pair<int, char> > back;
    vector<pair<string, int> > ans;
    vector<vi> pos;// pos da string que tem essa substring
    vi end, pref;
    int sigma;
    char norm;

    Trie(int sigma_ = 26, char norm_ = 'a') : sigma(sigma_), norm(norm_) {
        to = {vi(sigma)};
        end = {0}, pref = {0};
        back = {{-1, '*'}};
        ans = {{"", -1}};
        pos = {{}};
    }

    void insert(string &s,int i) {
        int x = 0;
        for (auto c: s) {
            int &nxt = to[x][c - norm];
            if (!nxt) {
                nxt = to.size();
                back.EB(x, c);
                to.PB(vi(sigma));
                end.PB(0), pref.PB(0);
                pos.PB({});
            }
            x = nxt, pref[x]++, pos[x].PB(i);
        }

        end[x]++, pref[0]++;
    }


    void erase(string &s) {
        int x = 0;
        for (char c: s) {
            int &nxt = to[x][c - norm];
            x = nxt, pref[x]--;
            if (!pref[x]) nxt = 0;
        }
        end[x]--, pref[0]--;
    }

    int find(string &s) {
        int x = 0;
        for (auto c: s) {
            x = to[x][c - norm];
            if (!x) return -1;
        }
        return x;
    }

    int count_pref(string &s) {
        int id = find(s);
        return id >= 0 ? pref[id] : 0;
    }

    vi find_positions(string & t) {
        int id = find(t);
        return id >=0 ? pos[id] : vi();
    }

};

vector<vi> pos;
int n,m;
int dp[MAXN];
int solve(int i) {
    if(i == n) return 0;
    if(~dp[i]) return dp[i];

    int ans = INF;
    for(auto x : pos[i]) {
        ans = min(ans,1 + solve(i + x));
    }

    return dp[i] = ans;
}


int main() {
    optimize;
    memset(dp,-1,sizeof dp);
    cin >> n >> m;
    pos.resize(n);
    string s; cin >> s;
    auto tri = Trie();
    for(int i = 0; i < n-1;i++) {
        auto aux = s.substr(i, n-i);
        tri.insert(aux,i);
    }

    while(m--) {
        string t; cin >> t;
        int sz = t.size();
        auto p = tri.find_positions(t);
        for(auto x : p) {
            pos[x].PB(sz);
        }
    }

    /*for(int i = 0;i < n;i++) {
        cout << i << " :" << endl;
        for(auto x : pos[i]) {
            cout << x << " ";
        }
        cout << endl;
    }*/

    cout << solve(0) << endl;

    return 0;
}

