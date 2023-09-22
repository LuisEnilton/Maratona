//
// Created by Luis on 21/09/2023.
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
#define f first
#define h      second

int main(int argc, char **argv) {
    optimize;
    int t;
    cin >> t;
    while (t--) {
        int n;
        ll k;
        cin >> n >> k;
        vector<pair<int, ll>> trees(n);
        for (int i = 0; i < n; i++) {
            cin >> trees[i].f;
        }
        for (int i = 0; i < n; i++) {
            cin >> trees[i].h;
        }

        int ans = 0;
        int l = 0;
        ll sum = 0;
        if(trees[0].f <=k) {
            sum = trees[0].f;
            ans = 1;
        }
        else trees[0].h = -1;
        for (int r = 1; r < n; r++) {

            bool ok = true;
            bool ok1 = true;
            if(trees[r].f > k) ok1 = false;

            if(!ok1){
                sum = 0;
                l = r+1;
                trees[r].second = -1;
                continue;
            }

            if (trees[r - 1].h % trees[r].h != 0 || trees[r - 1].h == -1) {
                ok = false;
            }
            if (!ok){
                sum = trees[r].f;
                l = r ;
                ans = max(ans,1);
            }else{
                if(trees[r].f + sum <=k){
                    sum+=trees[r].f;
                }else{
                    while(l < r && trees[r].f + sum >k ){
                        sum-=trees[l].f;
                        l++;
                    }
                    sum+= trees[r].f;
                }


                ans = max(r - l + 1,ans);


            }
        }
        cout << ans << endl;
    }
    return 0;
}