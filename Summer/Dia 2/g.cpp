

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

/*
  Modelar como stars and bars
  Contar a quantidade de cadeiras vazias entre os caras
  Restrições
  x1 + x2 + x3 = n - k
  x2 >=1
  x1,x3>=0
 Problema equivalente
  x1 + x2' + x2 = n - k - 1
  xi >= 0
  Comb( M + N -1, M)
  Depois multiplica por K! para contar as permutações entre as pessoas

   Problema com ciclo
    Seleciona apenas uma cadeira
    temos 2 casos
    Primeiro se tem uma pessoa na cadeira , o subproblema é tirando a cadeira e as adjacentes
     Se não tem é um subproblema apenas sem essa cadeira , resolve o stars and bars
     depois multiplica por k! pra contar as permutações de pessoas
 */

inline void solve() {
 ll n, k; cin >> k >> n;

 ll s = 0;
 ll t = fat[n];

 // caso 1
 ll c1 = comb()




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