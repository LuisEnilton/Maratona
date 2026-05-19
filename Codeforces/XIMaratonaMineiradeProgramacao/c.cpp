#include <bits/stdc++.h>

#define PB push_back
#define EB emplace_back
#define F first
#define S second
#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f
#define ALL(x) x.begin(),x.end()
using namespace std;

using ll = long long;
#define int ll
using vi = vector<int>;
using ii = pair<int, int>;
using vii = vector<ii>;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m; cin >> n >> m;
    vector<int> val(n+1);
    vector<int> ind(m+1);
    map <int, string> pal;
    queue <int> fila;
    int cont = 0;
    for(int i = 1; i <= n; i++) {
        int a; cin >> a;
        fila.emplace(i);
        val[i] = a;
        cont += (a == m);
    }
    for(int i = 1; i <= m; i++) {
        int a; string str; cin >> a >> str;
        ind[a] = i;
        pal[a] = str;
    }
    int i = 1;
    if(cont > 1) {
        cout << -1 << endl;
    } else { 
        while(fila.size() > 1) {
            int atual = fila.front();
            fila.pop();
            int v = val[atual];
            int id = ind[i];
            if(id > m - v) {
                // cout << atual << endl;
                // cout << id << endl;
                // cout << endl;
                fila.emplace(atual);
            }
            i++;
            if(i == m+1) {
                i = 1;
            }
        }
         cout << fila.front() << endl;
        if(i == 1) {
            i = m;
        } else {
            i--;
        }
        cout << pal[i] << endl;
    }
}