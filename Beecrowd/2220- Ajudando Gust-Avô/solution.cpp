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
#define debug cout<<"ate aqui ok\n"

string a, b;
int casos;

bool aparicoes(int n){

    int pos_a = 0;

    for(auto B : b){
        for(int qtd=0; qtd < n; qtd++){

            while( pos_a < a.size() && B != a[pos_a] )
                pos_a++;

            if( pos_a == a.size())
                return false;

            pos_a++;
        }
    }

    return true;
}


int main(){

    optimize;

    cin>>casos;

    while(casos--){

        cin>>a>>b;

        int esq = 0, dir = a.size() / b.size(), maiorValor;

        while( esq <= dir ){

            int meio = (esq + dir) / 2;

            if( aparicoes(meio) ){
                maiorValor = meio;
                esq = meio + 1;
            } else {
                dir = meio - 1;
            }

        }

        cout<<maiorValor<<endl;

    }

    return 0;
}