#include<bits/stdc++.h>
using namespace std;

const int N = 1e6 + 9, mod = 1e9 + 7;

int f[N], inv[N], finv[N];



// Calculo dos coeficientes O(n)
/**
 * @brief Precomputes factorials, modular inverses, and factorial inverses.
 * 
 * This function initializes three arrays:
 * - `f`: stores factorials modulo `mod`.
 * - `inv`: stores modular inverses of integers modulo `mod`.
 * - `finv`: stores factorial inverses modulo `mod`.
 * 
 * The arrays are computed as follows:
 * - `f[i]` is the factorial of `i` modulo `mod`.
 * - `inv[i]` is the modular inverse of `i` modulo `mod`.
 * - `finv[i]` is the factorial inverse of `i` modulo `mod`.
 * 
 * The function assumes that the arrays `f`, `inv`, and `finv` are of size `N` and that `mod` is a prime number.
 */
void precalc() {
  f[0] = 1;
  for (int i = 1; i < N; i++) f[i] = 1LL * i * f[i - 1] % mod;
  inv[1] = 1;
  for (int i = 2; i < N; i++ ) {
    inv[i] = (-(1LL * mod / i) * inv[mod % i] ) % mod;
    inv[i] = (inv[i] + mod) % mod;
  }
  finv[0] = 1;
  for (int i = 1; i < N; i++) finv[i] = 1LL * inv[i] * finv[i - 1] % mod;
}


// Calcula o numero de combinações de 'n' em grupos de 'r' O(1)
int ncr(int n, int r) {
  if (n < r || n < 0 || r < 0) return 0;
  return 1LL * f[n] * finv[n - r] % mod * finv[r] % mod;
}

// Calcula permutação com repetição
int perm_with_repetitions(int x, vector<int> rep)
{
    // RODAR O PRECALC!!
    int resp = f[x];
    for (int r : rep)
    {
        resp = 1LL * resp * finv[r] % mod;
    }
    return resp;
}


// void brute() {
//  for (int i = 0; i < N; i++) {
//    C[i][0] = 1;
//  }
//  for (int i = 1; i < N; i++) {
//    for (int j = 1; j <= i; j++) {
//      C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % mod;
//    }
//  }
// }
// https://cses.fi/problemset/task/1079/
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  
  precalc();
  int q; cin >> q;
  while (q--) {
    int n, r; cin >> n >> r;
    cout << ncr(n, r) << '\n';
  }
  return 0;
}
