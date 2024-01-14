
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


int main() {
    optimize;
    int a1, a2, k1, k2, n;
    cin >> a1 >> a2 >> k1 >> k2 >> n;

    if (a1 * k1 < a2 * k2) {
        swap(a1, a2);
        swap(k1, k2);
    }
    // Minimo
    int aux = n;
    int ans;
    aux -= ((k1 - 1) * a1);
    if(aux <=0) ans = 0;
    else{
        aux-= ((k2 - 1) * a2);
        if(aux<=0) ans = 0;
        else ans = aux;
    }
    cout << ans << " ";
    // Máximo
    if(k1 > k2){
        swap(k1,k2);
        swap(a1,a2);
    }
    priority_queue<int> pq;
    while(a1--){
        pq.push(-k1);
    }
    while(a2--){
        pq.push(-k2);
    }
    aux = n;
    ans = 0;
    while(aux > 0 && !pq.empty()){
        auto t = -pq.top(); pq.pop();
        if(t > aux) break;
        aux-=t;
        ans += 1;
    }
    cout << ans << endl;
    return 0;
}

