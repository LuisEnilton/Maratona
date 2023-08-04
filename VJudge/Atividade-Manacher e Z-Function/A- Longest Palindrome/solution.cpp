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
#define MOD 1000000007
#define PRIME 101
#define MAXN 1010101
#define MAXL 23
#define EPS 1e-9
#define endl '\n'

using namespace std;
using namespace __gnu_pbds;

#define ordered_set tree<os_type, null_type,less<os_type>, rb_tree_tag,tree_order_statistics_node_update>


vi manacher(string &st) {
    string s = "$_";
    for (auto c: st) {
        s += c;
        s += "_";
    }
    s += "#";
    int n = s.size() - 2; //elimina o '$' e o '#'
    vi p(n + 2);
    int l = 1, r = 1;// r marca o palindromo que chegou mais longe
    for (int i = 1; i <= n; i++) {
        p[i] = max(0, min(r - i, p[l + r - i]));

        while (s[i - p[i]] == s[i + p[i]])//tenta crescer pros 2 lados
            p[i]++;

        if (i + p[i] > r) {
            l = i - p[i];
            r = i + p[i];
        }
    }

    for (auto &x: p) x--;
    return p;
}

int main(int argc, char **argv) {
    optimize;
    string s;
    cin >> s;

    int n = s.size();
    vi p = manacher(s);



    int max = 0;
    int indice;

    for (int i = 1; i <= 2*n; i++) {
        if (p[i] > max) {
            max = p[i];
            indice = i - 1;
        }
    }


    cout << s.substr((indice/2)   - (max/2) , max ) << endl;
    // indice/2 acha o meio na string original , agr é necessário diminuir max/2 pra voltar ao inicio da string
    return 0;
}

/*

 *aba -> palindromo impar
  $ _ a _ b _ a _  #
 -1 0 1 0 3 0 1 0 -1
 letras unicas tem o palindromo de pelo menos 1 (a propria)

 *abccba -> palindromo par
  $ _ a _ b _ c _ c _ b _ a _  #
 -1 0 1 0 1 0 1 6 1 0 1 0 1 0 -1

 & _ a _ y _ b _ a _ b _ t _ u
 */

