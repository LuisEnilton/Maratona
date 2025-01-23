    #include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

#define rep(i, a, b) for (ll i = a; i <= b; i++)
#define per(i, a, b) for (ll i = a; i >= b; i--)

const ll N = 2e5;
const ll mod = 1e9 + 7;

ll fat[N];
ll taf[N];

ll add(ll a, ll b) {
    return ((a % mod) + (b % mod)) % mod;
}

ll sub(ll a, ll b) {
    return (((a - b) % mod) + mod) % mod;
}

ll mul(ll a, ll b) {
    return (((a % mod) * (b % mod))) % mod;
}

ll exp(ll a, ll n) {
    if (n == 0ll) return 1ll;
    ll b = exp(a, n >> 1ll);
    b = (b * b) % mod;
    if (n & 1ll) b = (a * b) % mod;
    return b % mod;
}

ll inv(ll x){
    return exp(x, mod-2);
}

ll comb(ll a, ll b){
    ll c = (taf[b] * taf[a - b]) % mod;
    return (fat[a] * c) % mod;
}

void mkfat(){
    fat[0]=1;
    taf[0]=inv(fat[0]);
    for(ll i = 1; i < N; i++){
        fat[i]= (i * fat[i - 1]) % mod;
        taf[i]=inv(fat[i]);
    }
}

inline void solve() {
    ll n; cin >> n;

    ll s = 0;
    ll t = fat[n];

    rep(k, 0, n) {
        if (k & 1) {
            s = sub(s, mul(comb(n, k), fat[n - k]));
        }
        else {
            s = add(s, mul(comb(n, k), fat[n - k]));
        }

        // cout << s << " " << comb(n, k) << " " << fat[n - k] << "\n";
    }

    s = sub(t, s);

    ll r = mul(s, inv(t));

    //cout << s << "\n";
    //cout << inv(t) << "\n";
    cout << r << "\n";
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    mkfat();

    int t=1;
    // cin>>t;
    while(t--){
        solve();
    }
}