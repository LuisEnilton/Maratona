        //
        // Created by luise on 22/09/2023.
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
        #define pli pair<ll,int>
        #define vi vector<int>
        #define vii vector<pii>
        #define os_type int
        #define PB push_back
        #define EB emplace_back
        #define MOD 1000000007
        #define PRIME 101
        #define MAXN 100010
        #define MAXL 23
        #define EPS 1e-9
        #define endl '\n'

        using namespace std;
        using namespace __gnu_pbds;

        #define ordered_set tree<os_type, null_type,less<os_type>, rb_tree_tag,tree_order_statistics_node_update>
        vector<pii> grafo[MAXN];
        int n,m;
        vi ancestral;

        vector<ll> dijkstra(int origem){

            priority_queue<pli,vector<pli>,greater<pli>> pq;

            vector<ll> dist(n + 1,INFLL);
            dist[origem] = 0;

            vector<bool> visitados(n + 1,false);
            pq.push({0,origem});

            while(!pq.empty()){
                auto [d,atual] = pq.top();
                pq.pop();
                if(visitados[atual]) continue;
                visitados[atual] = true;
                for(auto [custo,dest] : grafo[atual]){

                    if(d + custo < dist[dest]){
                        dist[dest] = d + custo;
                        pq.push({d+custo,dest});
                        ancestral[dest] = atual;
                    }
                }

            }
            return dist;
        }


        int main(int argc, char** argv)
        {
            optimize;
            cin >> n >> m;
            ancestral.resize(n+1);
            while(m--){
                int u,v,c;
                cin >> u >> v >> c;
                grafo[u].EB(c,v);
                grafo[v].EB(c,u);
            }
            vector<ll> dist = dijkstra(1);
            ancestral[1] = -1;
            if(dist[n] == INF){
                cout << -1  << endl;
                return 0;
            }
            int pai = n;
            stack<int> pilha;
            while(pai !=-1){
                pilha.push(pai);
                pai = ancestral[pai];
            }
            while(!pilha.empty()){
                int atual = pilha.top();
                cout << atual << " ";
                pilha.pop();
            }
            cout << endl;
            return 0;
        }

