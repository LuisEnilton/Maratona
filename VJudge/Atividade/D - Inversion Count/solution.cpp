//
// Created by Luis on 24/07/2023.
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


int inversion_count(vector<ll> &v) {

    int inv = 0;

    if (v.size() == 1) return 0;

    vector<ll> u1, u2;
    for (int i = 0; i < v.size() / 2; i++) {
        u1.PB(v[i]);
    }

    for (int i = v.size() / 2; i < v.size(); i++) {
        u2.PB(v[i]);
    }

    inv += inversion_count(u1);
    inv += inversion_count(u2);

    u1.PB(INT_MAX);
    u2.PB(INT_MAX);

    int inicio1 = 0, inicio2 = 0;

    for (int i = 0; i < v.size(); i++) {

        if (u1[inicio1] <= u2[inicio2]) {
            v[i] = u1[inicio1++];
        }else{
            v[i] = u2[inicio2++];
            inv += u1.size() - inicio1 - 1;
        }

    }

    return inv;

}

vector<ll> nums;
int main(int argc, char **argv) {
    optimize;
    int n,q;
    cin >> q;
    while(q--){
    cin.ignore();
    cin >> n;
    nums.clear();
    nums.resize(n);
    for(auto &x : nums) cin >> x;
    cout << inversion_count(nums) << endl;
    }
    return 0;
}