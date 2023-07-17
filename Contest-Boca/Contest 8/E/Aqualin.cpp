#include <bits/stdc++.h>
#define optimize ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define INF 100000010
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
#define MAXN 26
#define MAXL 23
#define endl '\n'

using namespace std;

string matrizL[MAXN][MAXN];
int matrizN[MAXN][MAXN];

bool visL[MAXN][MAXN];
bool visN[MAXN][MAXN];

map<string, int> valoresLetras;
map<int, int> valoresCores;

int dx[] = {0, 1, 0, -1};
int dy[] = {-1, 0, 1, 0};

int n;

bool check(int x, int y) {
    if (x < 0 || x >= n || y < 0 || y >= n) {
        return false;
    }
    return true;
}

void dfsTimeB(int linha, int col){
    int cont = 0;
    int pont = 0;
    queue<int> fila;
    queue<pair<int, int>> pos;

    fila.push(matrizN[linha][col]);
    pos.push({linha, col});
    int def = fila.front();
    while (!fila.empty()) {
        int atual = fila.front();
        int xAtual = pos.front().first;
        int yAtual = pos.front().second;
        visN[xAtual][yAtual] = true;
        fila.pop();
        pos.pop();
        
        cont += pont;
        
        for (int i = 0; i < 4; i++) {
            int xx = dx[i];
            int yy = dy[i];
            if (check(xAtual + xx, yAtual + yy)) {
                if(matrizN[xAtual + xx][yAtual + yy] == def && !visN[xAtual + xx][yAtual + yy]){
                    visN[xAtual + xx][yAtual + yy] = true;
                    fila.push(matrizN[xAtual + xx][yAtual + yy]);
                    pos.push({xAtual+xx, yAtual+yy});
                }
            }
        }
        pont++;
    }
    
    if(valoresCores.count(def) > 0){
        valoresCores[def] = max(valoresCores[def], cont);
    }else{
        valoresCores[def] = cont;
    }
}

void dfsTimeA(int linha, int col){
    int cont = 0;
    int pont = 0;
    queue<string> fila;
    queue<pair<int, int>> pos;
    int xAtual = linha;
    int yAtual = col;

    fila.push(matrizL[linha][col]);
    pos.push({linha, col});
    string def = fila.front();
    while (!fila.empty()) {
        string atual = fila.front();
        int xAtual = pos.front().first;
        int yAtual = pos.front().second;
        visL[xAtual][yAtual] = true;
        fila.pop();
        pos.pop();
        
        cont += pont;
        
        for (int i = 0; i < 4; i++) {
            int xx = dx[i];
            int yy = dy[i];
            if (check(xAtual + xx, yAtual + yy)) {
                if(matrizL[xAtual + xx][yAtual + yy] == def && !visL[xAtual + xx][yAtual + yy]){
                    visL[xAtual + xx][yAtual + yy] = true;
                    fila.push(matrizL[xAtual + xx][yAtual + yy]);
                    pos.push({xAtual+xx, yAtual+yy});
                }
            }
        }
        pont++;
    }
    
    if(valoresLetras.count(def) > 0){
        valoresLetras[def] = max(valoresLetras[def], cont);
    }else{
        valoresLetras[def] = cont;
    }
}

void solveTimes(){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(!visL[i][j]) dfsTimeA(i,j);
            if(!visN[i][j]) dfsTimeB(i,j);
        }
    }
}

int main() {
    optimize;
    
    cin >> n;
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            int cor;
            string letra;
            cin >> letra >> cor;
            matrizL[i][j] = letra;
            matrizN[i][j] = cor;
        }
    }
    
    solveTimes();
    
    int somaA = 0;
    int somaB = 0;
    
    map<string, int>::iterator it;
    for(it=valoresLetras.begin(); it!=valoresLetras.end(); ++it){
        somaA += it->second;
    }
    
    map<int, int>::iterator it2;
    for(it2=valoresCores.begin(); it2!=valoresCores.end(); ++it2){
        somaB += it2->second;
    }
    
    cout << somaA << " " << somaB << endl;

    return 0;
}