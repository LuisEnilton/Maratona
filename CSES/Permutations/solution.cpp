//
// Created by Luis on 11/08/2023.
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


int main(int argc, char **argv) {
    optimize;
    int n;
    cin >> n;
    if(n == 1){
        cout << 1 << endl;
        return 0;
    }
    if (n == 3 || n == 2) {
        cout << "NO SOLUTION" << endl;
        return 0;
    }
    int arr[n];
    for(int i = 1;i<=n;i++) arr [ i-1] = i;
    vi ans;
    int ini = n / 2;
    for (int i = 0,l = ini - 1,r = ini + 1; i < n; i++) {
        if(r == n){
            if(l == -1){
                ans.PB(arr[ini]);

            }else{
                ans.PB(arr[l]);
                ans.PB(arr[ini]);
            }
            break;
        }

        ans.PB(arr[l]);
        ans.PB(arr[r]);
        r++;
        l--;
    }
    for(auto x : ans) cout << x << " ";
    cout << endl;

    return 0;
}

