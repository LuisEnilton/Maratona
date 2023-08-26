//
// Created by Luis on 25/08/2023.
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

int n,m;
ll k;
int main(int argc, char** argv)
{
    optimize;
    cin >> n >> m >> k;
    priority_queue<ll,vector<ll>,greater<>> pq;
    priority_queue<ll,vector<ll>,greater<>> pq2;
    for(int i =0;i < n;i++){
        ll apl; cin >> apl;
        pq.push(apl);
    }

    for(int i = 0;i <m;i++){
        ll ap; cin >> ap;
        pq2.push(ap);
    }
    int ans =0;
    while(!pq.empty() && !pq2.empty()){
        ll pers = pq.top(), apt = pq2.top() ;
        if(abs(pers - apt) <=k){
            pq2.pop();
            pq.pop();
            ans++;
        }else{
            if(pers - apt > k){
                pq2.pop();
            }
            if(apt - pers > k){
                pq.pop();
            }
        }
    }
    cout << ans << endl;
    return 0;
}

