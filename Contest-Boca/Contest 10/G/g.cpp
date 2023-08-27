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
#define MAXN 101010
#define MAXL 23
#define endl '\n'

using namespace std;

int main(int argc, char** argv)
{
    optimize;
    string n;
    cin >> n;

    int totalDigitos = n.size();
    ll totalPlacas = 0;
    if(totalDigitos == 1){
        cout << n[0] - '0' + 1<< endl;
        return 0;
    }
    totalPlacas = (totalDigitos - 1) * 10;
    for(int i = 0; i < totalDigitos; i++){
        if(i == totalDigitos - 1){
            totalPlacas += n[i] - '0';
            break;
        }
        if(n[i] > n[i+1]){
            totalPlacas += n[i] - '0' - 1;
            break;
        }else if(n[i] < n[i+1]){
            totalPlacas += n[i] - '0';
            break;
        }else{
            continue;
        }
    }

    cout << totalPlacas << endl;

    return 0;
}