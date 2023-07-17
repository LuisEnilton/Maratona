#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <string>
#include <algorithm>
#include <set>

#define optimize                 \
    ios::sync_with_stdio(false); \
    cin.tie(NULL);               \
    cout.tie(NULL)
#define INF 100000010
#define ALL(x) x.begin(), x.end()
#define UNIQUE(c) (c).resize(unique(ALL(c)) - (c).begin())
#define REP(i, a, b) for (int i = (a); i <= (b); i++)
#define POS(n, x) (lower_bound(ALL(n), x) - (n).begin())
#define ll long long
#define ld long double
#define pii pair<char,int >
#define vi vector<int>
#define vii vector<pii>
#define os_type int
#define PB push_back
#define EB emplace_back
#define MOD 1000000007
#define PRIME 101
#define MAXN 101010
#define MAX_MOEDAS 1010
#define MAXL 23
#define endl '\n'

using namespace std;
using namespace __gnu_pbds;

#define ordered_set tree<os_type, null_type, less<os_type>, rb_tree_tag, tree_order_statistics_node_update>
using namespace std;

int N;
int K;
int ans=0;
map<int,map<char,int>> letras;

// 4 2
// 01   010
//      011
// 00   000
//      001   0011   0010
int solve(int l,int b,int ac){

    if(ac > K){
        if(l<N)
            ans += 2*(N-l);
        ans++;
        return 0;
    }

    if(l == N){
        return 1;
    }

    int vtroca;

    if(b == 0){
        vtroca = 1;
    }else{
        vtroca = 0;
    }

    int troca = solve(l+1,vtroca,0);
    int n_troca = solve(l+1,b,ac+1);


    return 0;
}



int main() {
    optimize;
    cin >>N>>K;
    solve(0,0,1);
    solve(0,1,1);
    cout<<ans<<endl;
    }

//
// Created by Luis on 24/06/2023.
//
