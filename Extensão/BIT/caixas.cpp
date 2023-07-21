//
// Created by Luis on 20/07/2023.
//
//Template By eduardocesb
#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
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
//#define MAXN 1010101
#define MAXL 23
#define EPS 1e-9
#define endl '\n'

using namespace std;

//#define ordered_set tree<os_type, null_type,less<os_type>, rb_tree_tag,tree_order_statistics_node_update>


const int MAXN = 2e5 + 100;




    ll tree[4 * MAXN];
    int arr[MAXN];

    void update(int pos, int i, int j, int x, ll val){
        // pos é a posição de inicio 1 pq é 1-indexado
        // i e j é o tamanho da arvore 0 até n-1
        // x é qual nó vai ser somado e val é o valor a ser somado
        int esq = 2*pos;
        int dir = 2*pos + 1;
        int mid = (i+j)/2; // mid é usado pra comparar com x e decidir pra onde vai

        tree[pos] += val; // a implementação faz incrementando primeiro a raiz

        if(i == j) return; // se for folha retorna
        if(x <= mid) update(esq, i, mid, x, val);
        else update(dir, mid+1, j, x, val);
    }

    ll query(int pos, int i, int j, int l, int r){
        // pos é a posição de inicio 1 pq é 1-indexado
        // i e j é o tamanho da arvore 0 até n-1
        // l e r definem o range da query
        int esq = 2*pos;
        int dir = 2*pos + 1;
        int mid = (i+j)/2;

        if(i > r || j < l) return 0; // se o nó ta totalmente fora volta
        if(i >= l && j <= r) return tree[pos]; // se ele ta no mei entra na soma
        else return query(esq, i, mid, l, r) + query(dir, mid+1, j, l, r);
    }

    int main(){
        ios::sync_with_stdio(0);
        cin.tie(0);

        int n, q;
        cin >> n >> q;

        for(int i=0;i<n;i++){
            ll v;
            cin >> v;
            update(1, 0, n-1, i, v);
            arr[i] = v;
        }

        while(q--){
            int tp;
            cin >> tp;

            if(tp == 1){
                int x;
                ll v;
                cin >> x >> v;
                x--;

                update(1, 0, n-1, x, -arr[x]);
                update(1, 0, n-1, x, v);

                arr[x] = v;
            }
            else{
                int l, r;
                cin >> l >> r;
                l--, r--;

                cout << query(1, 0, n-1, l, r) << endl;
            }
        }
    return 0;
    }
