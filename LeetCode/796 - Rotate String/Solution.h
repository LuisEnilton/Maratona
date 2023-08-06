//
// Created by Luis on 05/08/2023.
//

#ifndef MARATONA_SOLUTION_H
#define MARATONA_SOLUTION_H
//
// Created by Luis on 04/08/2023.
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
//#define MOD 1000000007
#define PRIME 101
#define MAXN 1010101
#define MAXL 23
#define EPS 1e-9
#define endl '\n'

using namespace std;
using namespace __gnu_pbds;

#define ordered_set tree<os_type, null_type,less<os_type>, rb_tree_tag,tree_order_statistics_node_update>
const ll MOD=1e9+9;//big prime number
const ll mod=1e9+7;
const ll base=153;//random number larger than the size of the alphabet

const ll maxn=1e6+10;
ll expBase[maxn];
ll expBase2[maxn];

void precalc(){
    expBase[0]=1;
    expBase2[0]=1;
    for (ll i=1;i<maxn;i++){
        expBase[i]=(expBase[i-1]*base)%MOD;
        expBase2[i]=(expBase2[i-1]*base)%mod;
    }
}

struct StringHash{
    vector<pair<ll,ll>> hsh;
    //REMEMBER TO RUN PRECALC
    StringHash(string& _s){
        hsh=vector<pair<ll,ll>>(_s.length()+1,{0,0});
        for (ll i=0;i<_s.length();i++){
            hsh[i+1].first=((hsh[i].first*base)%MOD + _s[i])%MOD;
            hsh[i+1].second=((hsh[i].second*base)%mod + _s[i])%mod;
        }
    }

    //interval =  [a,b] closed
    pair<ll,ll> get_value(ll a,ll b){
        auto p1= (MOD + hsh[b+1].first - ((hsh[a].first)*expBase[b-a+1])%MOD)%MOD;
        auto p2= (mod + hsh[b+1].second - ((hsh[a].second)*expBase2[b-a+1])%mod)%mod;
        return {p1,p2};
    }

};






class Solution {
public:
    bool rotateString(string s, string goal) {
        precalc();
        int sz = s.size() ;
        s += s;
        //cout << s << endl;
        StringHash hsh(s);
        StringHash hsh2(goal);
        auto val =hsh2.get_value(0 ,sz-1);
        for(int i =0;i < sz;i++){
            if(val == hsh.get_value(i,i+sz-1)){
                cout << "ok: "<< s.substr(i,sz) << endl;
                return true;
            }
        }
        return false;
    }
};


#endif //MARATONA_SOLUTION_H
