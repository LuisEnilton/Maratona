//
// Created by Luis on 14/01/2024.
//
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


int solve(int a){
    if(a < 1) return 0;
    if(a == 1) return 1;
    return a + solve(a-1);
}

int m1[3][3] = {{1,2,3},{1,2,3},{1,2,3}};
int m2[3][3] = {{1,2,3},{1,2,3},{1,2,3}};

int main() {
    optimize;
    int x,z;
    for(x = 0; x <3;x++){
        for(z = 0; z <3;z++){
            m1[x][z] = x + 2 * z;
        }
    }

     for(x = 0; x <3;x++){
        for(z = 0; z <3;z++){
            m2[x][z] = m1[z][x];
        }
     }
    for(int i = 0; i < 3;i++){
        for(int j = 0; j < 3;j++){
            cout << m1[i][j] << " ";
        }
        cout << endl;
    }

    for(int i = 0; i < 3;i++){
        for(int j = 0; j < 3;j++){
            cout << m2[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}

