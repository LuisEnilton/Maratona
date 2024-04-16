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
#define MAXN 200000
#define MAXL 23
#define EPS 1e-9
#define endl '\n'

using namespace std;
using namespace __gnu_pbds;

#define ordered_set tree<os_type, null_type,less<os_type>, rb_tree_tag,tree_order_statistics_node_update>

typedef pair<pii,int> cust;

struct CompareItems {
    bool operator()(const cust& a, const cust& b) const {
        if(a.first.first == b.first.first){
            return a.first.second < b.first.second;
        }
        return a.first.first > b.first.first;
    }
};

int main() {
    optimize;
    int n; cin >> n;
    priority_queue<cust,vector<cust>,CompareItems> pq;
    for(int i =0; i < n;i++){
        int a,b; cin >> a >> b;
        pq.push({{a,0},i});
        pq.push({{b,1},i});
    }
    int curr = 0;
    int ans = 0;
    bitset<MAXN> rooms;
    rooms.flip();
    unordered_map<int,int> w;
    while(!pq.empty()){
        auto [x,id] = pq.top();
        auto [t,op] = x;
        t = -t;
        pq.pop();
        if(op == 1){
            int r = w[id];
            rooms.set(r);
        }else{
           int r =  rooms._Find_first();
           cout << id << " -> " << r << endl;
           w[id] = r + 1;
           rooms.reset(r);
        }
        int a = MAXN - rooms.count();
        ans = max(ans, a );
    }
    cout << ans <<endl;
    for(int i = 0; i < n;i++){
        cout << w[i] << " ";
    }
    cout << endl;
    return 0;
}

