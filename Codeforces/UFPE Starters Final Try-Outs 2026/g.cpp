//
// Created by Luis on 06/09/2023.
//
// Template By eduardocesb
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define optimize                 \
    ios::sync_with_stdio(false); \
    cin.tie(NULL);               \
    cout.tie(NULL);
#define INF 1000000010
#define INFLL 1000000000000000010LL
#define ALL(x) x.begin(), x.end()
#define ll long long
#define pii pair<int, int>
#define vi vector<int>
#define vb vector<bool>
#define BT bitset<500>
#define vii vector<pii>
#define os_type int
#define PB push_back
#define EB emplace_back
#define MOD 1000000007
#define MAXN 20
#define int ll
#define dbg(x) cout << #x << " " << x << endl;
#define endl '\n'

using namespace std;
using namespace __gnu_pbds;

#define ordered_set tree<os_type, null_type, less<os_type>, rb_tree_tag, tree_order_statistics_node_update>


struct PT {
	ll x, y;
	PT(ll x=0, ll y=0) : x(x), y(y) {}

	PT operator+(const PT&a)const{return PT(x+a.x, y+a.y);}
	PT operator-(const PT&a)const{return PT(x-a.x, y-a.y);}
	ll operator*(const PT&a)const{return  (x*a.x + y*a.y);} //DOT
	ll operator%(const PT&a)const{return  (x*a.y - y*a.x);} //Cross
	PT operator*(ll c) const{ return PT(x*c, y*c); }
	PT operator/(ll c) const{ return PT(x/c, y/c); }
	bool operator==(const PT&a) const{ return x == a.x && y == a.y; }
	bool operator< (const PT&a) const{ return tie(x, y) < tie(a.x, a.y); }
	
	ll cross(const PT&a, const PT&b) const{ return (a-*this) % (b-*this); } // (a-p) % (b-p)
	int quad() { return (x<0)^3*(y<0); } //cartesian plane quadrant |0++|1-+|2--|3+-|
	bool ccw(PT q, PT r){ return (q-*this) % (r-q) > 0;}
};

bool onLine(PT s, PT e, PT p){ return p.cross(s, e) == 0;}

int dp[MAXN][1 << MAXN];
// tando nesse cara com esse conjunto de pontos ja atingidos
// se a mascara ficar toda 1, atingiu todos
int n;
vector<PT> pts;

unordered_set<int> trans[MAXN]; // mascara das retas desse cara

int calc(int i , int mask){

    if(i == n){
        return 0;
    }
    
    auto & at = dp[i][mask];
    if(~at) return at;
    if((1 << i) & mask){
        return calc(i + 1, mask);
    }
    int ans = INF;
    for(auto aux : trans[i]){

        ans = min(ans, 1 + calc(i + 1, mask | aux));
    }
    return at = ans;
}



void solve()
{
    memset(dp,-1,sizeof dp);
    cin >> n;
    for(int i = 0; i < n;i++){
        int x,y; cin >> x >> y;
        pts.EB(x,y);
    }

    for(int i = 0; i < n;i++){
        trans[i].insert(1 << i); // atira so nele
        for(int j = i + 1; j < n;j++){
            int aux_mask = 0;
            aux_mask |= (1 << i);
            aux_mask |= (1 << j);
            vi addpoints;
            addpoints.push_back(i);
            addpoints.push_back(j);
            for(int k = 0;k < n;k++){
                
                if(onLine(pts[i],pts[j],pts[k])){
                    aux_mask |= (1 << k);
                    addpoints.push_back(k);
                }
            }
            for(auto p : addpoints){
                trans[p].insert(aux_mask);
            }
        }
    }

    // for(int i = 0; i < n;i++){
    //     dbg(i);
    //     for(auto mask : trans[i]){
    //         cout << bitset<6>(mask) << " ";
    //     }
    //     cout << endl;
    // }


    cout << calc(0,0) << endl;
}

signed main()
{
    optimize;
    int t = 1;
    //   cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
