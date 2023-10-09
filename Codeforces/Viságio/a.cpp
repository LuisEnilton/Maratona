//
// Created by Luis on 07/10/2023.
//
#include <bits/stdc++.h>

#define optimize ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define INF 100000010
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
#define MAXN 101010
#define MAXL 23
#define endl '\n'

using namespace std;


int main() {
    int n;
    cin >> n;
    vector<pii > doadores(n); // first = quantidade de meses desde 2006 e  second = valor
    for (int i = 0; i < n; i++) {
        int a, m, val;
        cin >> a >> m >> val;
        doadores[i].first = (a - 2006) * 12 + m;
        doadores[i].second = val;
    }

    int a, m;
    cin >> a >> m;
    ll total = (a - 2006) * 12 + m;
    ll ans = 0;
    for(int i = 0; i < n;i++){
        if(doadores[i].first < total){
            ans+= (total - doadores[i].first + 1) * doadores[i].second;
        }

        if(doadores[i].first == total){
            ans+= doadores[i].second;
        }
    }
    cout << ans << endl;
    return 0;
}