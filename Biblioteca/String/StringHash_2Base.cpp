
//This struct  was made by Malhe1ros
#include <bits/stdc++.h>
#define optimize ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ll long long
#define ld long double
#define pii pair<int,int>
#define vi vector<int>
#define endl '\n'
#define int ll
using namespace std;



 
const int MAXN = 1e6 + 5;
 
const ll MOD1 = 131'807'699;
const ll MOD2 = 1e9 + 9;
const ll base = 157;
 
ll expb1[MAXN], expb2[MAXN];
 
#warning "Call precalc() before use StringHash"
void precalc(){ 
    expb1[0] = expb2[0] = 1;
    
	for(int i=1;i<MAXN;i++)
        expb1[i] = expb1[i-1]*base % MOD1,
        expb2[i] = expb2[i-1]*base % MOD2;
}
 
struct StringHash{
    vector<pair<ll,ll>> hsh;
    string s; // comment S if you dont need it
 
    StringHash(string& s) : s(s){ 
        hsh.assign(s.size()+1, {0,0});
 
        for (int i=0;i<s.size();i++)
            hsh[i+1].first  = ( hsh[i].first *base % MOD1 + s[i] ) % MOD1,
            hsh[i+1].second = ( hsh[i].second*base % MOD2 + s[i] ) % MOD2;
    }
 
    ll get_value(int a,int b){
        ll h1 = (MOD1+ hsh[b+1].first  - hsh[a].first *expb1[b-a+1] % MOD1) % MOD1;
        ll h2 = (MOD2+ hsh[b+1].second - hsh[a].second*expb2[b-a+1] % MOD2) % MOD2;
        return (h1<<32) | h2;
    }
};


signed main(){
    precalc();
    string s ="abcabc";
    StringHash shs(s);
    int l = 1 , r = 1;
    while((cin >> l >> r) && (l != -1 || r != -1)){
        cout << shs.get_value(l,r) << endl;
        cout <<(shs.get_value(l,r) == shs.get_value(1,2)?"S":"N") << endl;
    }

}