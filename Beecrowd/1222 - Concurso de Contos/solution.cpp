//
// Created by Luis on 08/08/2023.
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

int n, l, c;
int qc = 0;
int ql = 0;
int ans = 0;

void criarPagina(){
    ans++;
    ql = 1;
}
void criarLinha(){
    if(ql + 1 > l){
        criarPagina();
    }
    ql++;

}


int main(int argc, char **argv) {
    optimize;
    cin >> n >> l >> c;
    string palavras[n];
    int tamanhos[n];
    for (int i = 0; i < n; i++) {
        string s;
        cin >> palavras[i];
        tamanhos[i] = palavras[i].size();
    }

    for (int i = 0; i < n; i++) {
        if (tamanhos[i] + qc > c) {
            criarLinha();
            qc = tamanhos[i];
            if(qc + 1 > c){
                criarLinha();
                qc = 1;
            }else{
                qc+=1;
            }
        } else {
            qc += tamanhos[i];
            if(qc + 1 > c){
                criarLinha();
                qc = 1 ;
            }else{
                qc+=1;
            }
        }
    }
    cout << ans << endl;
    return 0;
}

