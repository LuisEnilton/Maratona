//
// Created by Luis on 27/08/2023.
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


int main(int argc, char** argv)
{
    optimize;
    int n; cin >> n;
    vi nums1;
    vi nums2;
    if(n <=2){
        cout << "NO" << endl;
        return 0;
    }
    if(n & 1){
        if((n-3) % 4 != 0){
            cout << "NO" << endl;
            return 0;
        }else{
            nums1.PB(1),nums1.PB(2);
            nums2.PB(3);
            int l = 4,r =n;
            while(l <r){
                nums1.PB(l);
                nums1.PB(r);
                l++,r--;
                nums2.PB(l);
                nums2.PB(r);
                l++,r--;
            }
        }
    }else{
        if(n % 4 != 0){
            cout << "NO" << endl;
            return 0;
        }else{
            int l = 1,r =n;
            while(l  < r){
                nums1.PB(l);
                nums1.PB(r);
                l++,r--;
                nums2.PB(l);
                nums2.PB(r);
                l++,r--;
            }
        }
    }
    sort(ALL(nums1));
    sort(ALL(nums2));
    cout << "YES" << endl;
    cout << nums1.size() << endl;
    for(auto x : nums1) cout << x << " ";
    cout << endl;
    cout << nums2.size() << endl;
    for(auto x : nums2) cout << x << " ";
    cout << endl;
    return 0;
}

