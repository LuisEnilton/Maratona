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



void solve(){
  int n,m,x; cin >> n >> m >> x;
  set<int> curr;
  curr.insert(x - 1);
  while(m--){
      int r; cin >> r;
      char c; cin >> c;
      if(c == '1'){
          set<int> aux;
          for(auto it = curr.begin();it!=curr.end();it++){
              int num = *it;
              int next = (num - r + n) % n ;
              aux.insert(next);
          }
          curr = aux;
      }
      if(c == '0'){
          set<int> aux;
          for(auto it = curr.begin();it!=curr.end();it++){
              int num = *it;
              int next = (num + r) % n ;
              aux.insert(next);
          }
          curr = aux;
      }
      if(c == '?'){
          set<int> aux;
          for(auto it = curr.begin();it!=curr.end();it++){
              int num = *it;
              int next = (num + r) % n ;
              int next2 = (num - r + n) % n;
              aux.insert(next);
              aux.insert(next2);
          }
          curr = aux;
      }
  }
  cout << curr.size() << endl;
  for(auto num : curr) cout << num + 1 << " ";
  cout << endl;
}


int main() {
    optimize;
    int t; cin >> t;
    while(t--){
        solve();
    }
    return 0;
}

