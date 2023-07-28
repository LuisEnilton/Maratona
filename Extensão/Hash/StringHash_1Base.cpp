
//This struct  was made by Malhe1ros
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
#define PRIME 101
#define MAXN 1010101
#define MAXL 23
#define EPS 1e-9
#define endl '\n'

using namespace std;
using namespace __gnu_pbds;

#define ordered_set tree<os_type, null_type,less<os_type>, rb_tree_tag,tree_order_statistics_node_update>



const ll MOD =1e9+9;//big prime number
const int base=153;//random number larger than the size of the alphabet

string s;
const int maxn=1e5+10;
int expBase[maxn];

void precalc(){
    expBase[0]=1;
    for (int i=1;i<maxn;i++){
        expBase[i]=(expBase[i-1]*base)%MOD;
    }
}

struct StringHash{
    vector<int> hsh;
    //REMEMBER TO RUN PRECALC
    StringHash(string& _s){
        hsh=vector<int>(_s.length()+1,0);
        for (int i=0;i<_s.length();i++){
            hsh[i+1]=((hsh[i]*base)%MOD + _s[i])%MOD;
        }
    }

    //interval =  [a,b] closed
    int get_value(int a,int b){ //0 indexado
//        cout << s.substr(a,b-a) << endl;
        return (MOD + hsh[b+1] - (hsh[a]*expBase[b-a+1])%MOD)%MOD;
    }


};


int main(){
    precalc();
     s="aaa";
    StringHash shs(s);
    int l = 1 , r = 1;
    while((cin >> l >> r) && (l != -1 || r != -1)){
        cout << shs.get_value(l,r) << endl;
        cout <<(shs.get_value(l,r) == shs.get_value(1,2)?"S":"N") << endl;
    }

}