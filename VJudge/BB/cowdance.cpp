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
#define vb vector<bool>
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

int n,t;
vi cows;

bool check(int k){
    int i = 0;
    priority_queue<int> pq;
    while(pq.size() < k){
        pq.push(-cows[i]);
        i++;
    }
    int time = 0;
    while(i < n){
        auto c = -pq.top();
        pq.pop();
        time = c;
        pq.push(-(time + cows[i]));
        i++;
    }

    while(!pq.empty()){
        auto c = -pq.top();
        pq.pop();
        time = c;
    }
    return time<=t;
}

int main() {
    optimize;
    freopen("cowdance.in", "r", stdin);
    freopen("cowdance.out", "w", stdout);
    cin >> n >> t;
    cows.resize(n);
    for(auto & x : cows) cin >> x;
    int l = 0, r = n;
    int ans;
    while(l <=r){
        int m = (l + r)/2;
        if(check(m)){
            ans = m;
            r = m-1;
        }else{
            l = m+1;
        }
    }
    cout << ans << endl;
    return 0;
}

