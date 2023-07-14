//
// Created by Luis on 13/07/2023.
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
    string s;
    cin >> s;
    unsigned ll n = s.size();
    ll sum = 0;
    for(char c : s){
        sum += (c -'0');
    }

    if((s[n-1] - '0') %2 == 0){
        cout << "S" << endl;
    }else{
        cout << "N" << endl;
    }

    if(sum % 3 == 0){
        cout <<"S" << endl;
    }else{
        cout << "N" << endl;
    }


    if((s[n-1] - '0') == 5 || (s[n-1] - '0') == 0){
        cout << "S" << endl;
    }else{
        cout << "N" << endl;
    }
}