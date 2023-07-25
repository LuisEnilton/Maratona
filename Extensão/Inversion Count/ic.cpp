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

int n;

int ic(vi &v){

    int inv =0;

    if (v.size() == 1) return 0;

    vi u1,u2; // as duas metades do vetor
    for (int i = 0; i < v.size()/2; i++) {
        u1.push_back(v[i]);
    }
    for (int i = v.size()/2; i <v.size() ; i++) {
        u2.push_back(v[i]);
    }

    inv +=ic(u1);
    inv += ic(u2);

    u1.push_back(INT_MAX); // para assegurar q o ultimo ta sendo contado como inversão
    u2.push_back(INT_MAX);

    int ini1 =0 , ini2 =0;

    for (int i = 0; i <  v.size(); i++) {

        if(u1[ini1] <= u2[ini2]){
            v[i] = u1[ini1++];
        }else{
            v[i] = u2[ini2++];
            inv += u1.size() - ini1 - 1;
        }

    }
    return inv;

}


int main(int argc, char** argv)
{
    optimize;
    vi teste{3,1,2};
    cout << ic(teste) << endl;

    return 0;
}