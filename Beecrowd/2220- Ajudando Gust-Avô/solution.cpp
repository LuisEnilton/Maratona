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


bool check(int qtd){
    int n = a.size();
    int m = b.size();
    int j =0;
    int cnt = 0;
    for(int i =0; i < n; i++){
        if(a[i] == b[j]){
            cnt++;
        }

        if(cnt == qtd){ // se a quantidade praquela letra deu certo , eu vou pra próxima
            j++;
            cnt = 0;
        }

        if(j == m){ // se eu consegui colocar todas as letras nessa quantidade
            return true;
        }

    }
    return false;
}


int main(){

    optimize;

    cin >> casos;
    while(casos--) {
        cin >> a >> b;
        int l =0, r = a.size()/b.size(); // o max possivel é encaixar a string b na string a
        int ans = 0;
        while(l<=r){
            int mid = (l+r)/2;
            if(check(mid)){
                ans = mid;
                l = mid+1;
            }else{
                r = mid - 1;
            }
        }
        cout << ans << endl;
    }
    return 0;
}