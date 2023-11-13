//
// Created by Luis on 04/11/2023.
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

struct Ticket {
    vector<int> ps;
    int sz;

    void init(string &s) {
        sz = s.size();
        ps[0] = s[0] - '0';
        for (int i = 1; i < s.size(); i++) {
            ps[i] = ps[i - 1] + (s[i] - '0');
        }
    }

    Ticket(string &s) {
        ps.resize(s.size());
        init(s);
    }


};

bool check(Ticket &a, Ticket &b) {
    int tot = a.sz + b.sz;
    if (tot & 1) return false; // se for impar o tamanho
    int d = tot / 2;

    int leftVal = 0, rightVal;
    if (a.sz > d) {
        leftVal = a.ps[d - 1];
        rightVal = a.ps[a.sz - 1 ] - leftVal;
        rightVal+= b.ps[b.sz - 1];
    }else if(a.sz < d){
        leftVal =  a.ps[a.sz - 1 ];
        leftVal+= b.ps [d - a.sz - 1];
        rightVal = b.ps[b.sz - 1 ] - b.ps [d - a.sz - 1] ;
    }else{
        leftVal = a.ps[a.sz - 1];
        rightVal = b.ps[b.sz - 1];
    }
    return leftVal == rightVal;
}


int main() {
    optimize;
    int n;
    cin >> n;
    vector<Ticket> arr;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        auto t = *new Ticket(s);
        arr.push_back(t);
    }

    ll ans = n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if(i == j) continue;
            if (check(arr[i], arr[j]))
                ans++;
        }
    }
    cout << ans << endl;
    bitset<10> bt;
    //bt._Find_first()
    return 0;
}

