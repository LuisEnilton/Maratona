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
#define MAXN 1010101
#define int ll
#define dbg(x) cout << #x << " " << x << endl;
#define endl '\n'
#define upper(v, x) (upper_bound(begin(v), end(v), x) - begin(v)) 
using namespace std;

struct BIT2D {
	vector<ll> ord;
	vector<vector<ll>> bit, coord;

	BIT2D(vector<pii> pts){
		sort(begin(pts), end(pts));
		
		for(auto [x, y] : pts)
			if(ord.empty() || x != ord.back())
				ord.push_back(x);

		bit.resize(ord.size() + 1);
		coord.resize(ord.size() + 1);

		sort(begin(pts), end(pts), [&](pii &a, pii &b){ return a.second < b.second; });

		for(auto [x, y] : pts)
			for(int i=upper(ord, x); i < bit.size(); i += i&-i)
				if(coord[i].empty() || coord[i].back() != y)
					coord[i].push_back(y);

		for(int i=0; i<bit.size(); i++) bit[i].assign(coord[i].size()+1, 0);
	}

	void update(ll X, ll Y, ll v){
		for(int i = upper(ord, X); i<bit.size(); i += i&-i)
			for(int j = upper(coord[i], Y); j < bit[i].size(); j += j&-j)
				bit[i][j] += v;
	}

	ll query(ll X, ll Y){
		ll sum = 0;
		for(int i = upper(ord, X); i > 0; i -= i&-i)
			for(int j = upper(coord[i], Y); j > 0; j -= j&-j)
				sum += bit[i][j];
		return sum;
	}

	ll queryArea(ll xi, ll yi, ll xf, ll yf){
		return query(xf, yf) - query(xf, yi-1) - query(xi-1, yf) + query(xi-1, yi-1);
	}

	void updateArea(ll xi, ll yi, ll xf, ll yf, ll val){ // OPTIONAL
		update(xi,   yi,    val);  // DOESN'T UPDATE AN AREA!!!
		update(xf+1, yi,   -val);  // It is like: bit1d.update(l-1, -v), bit1d.update(r, +v)
		update(xi,   yf+1, -val);  // so you can do like bit1d.query(i) to see the value "at" i
		update(xf+1, yf+1,  val);  // in this case, call bit2d.query(X, Y)
	}
};

struct BIT {
	int N;
	vector<int> bit;

	BIT(){}
	BIT(int n) : N(n+1), bit(n+1){}

	void update(int pos, int val){
		for(; pos < N; pos += pos&(-pos))
			bit[pos] += val;
	}

	int query(int pos){
		int sum = 0;
		for(; pos > 0; pos -= pos&(-pos))
			sum += bit[pos];
		return sum;
	}
    // valor do sufixo a partir de x
	int suf(int x){
        return query(this->N - 1) - query(x);
    }

};



void solve()
{
    int n; cin >> n;
    vi ord(n);
    for(int i = 0; i <n;i++) ord[i] = i;
    vi a(n),b(n),c(n);
    vii pts;
    for(int i = 0; i <n;i++){
        cin >> a[i] >> b[i] >> c[i];
        pts.emplace_back(b[i],c[i]);
    } 

    auto bt2 = BIT2D(pts);
    auto btb = BIT(n),btc = BIT(n);
    sort(ALL(ord),[&](int & i , int & j){
        return a[i] < a[j];
    });
    int ans = 0;
    for(int i = 0; i < n;i++){
        // dbg(i);
        int idx = ord[i];

        int q1 = btb.suf(b[idx]);
        int q2 = btc.suf(c[idx]);

        int q3 = bt2.queryArea(b[idx],c[idx],n,n);
        // dbg(q1);
        // dbg(q2);
        // dbg(q3);
        int curr = q1 + q2 - q3;
        ans += curr;

        btb.update(b[idx],1);
        btc.update(c[idx],1);
        bt2.update(b[idx],c[idx],1);
    }

    cout << ans << endl;

}

signed main()
{
    optimize;
    int t = 1;
    //  cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
