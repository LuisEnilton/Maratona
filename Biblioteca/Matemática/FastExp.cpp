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

#define ll long long
#define int ll
#define MOD 1000000007
#define PRIME 101
#define endl '\n'

using namespace std;
using namespace __gnu_pbds;

#define ordered_set tree<os_type, null_type,less<os_type>, rb_tree_tag,tree_order_statistics_node_update>

int fastExp(int base, int exp){
    int ret = 1LL;

    while(exp){
        if((exp&(1LL))) ret = (ret * base)%MOD;
        base = (base * base)%MOD;
        exp >>= 1;
    }

    return ret;
}


signed main()
{
    optimize;
    int n;
    cin >> n;
    cout << fastExp(2,n) << endl;
    return 0;
}

