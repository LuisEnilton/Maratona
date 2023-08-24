#include <bits/stdc++.h>

#define ll long long
#define pii pair<int,int>
#define optimize ios::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL)
#define ALL(x) x.begin(),x.end()
#define vi vector<int>
#define endl '\n'

using namespace std;
    int n ,q;

unordered_map<string,int> mapa;
int main(int argc, char const *argv[])
{
    optimize;
    cin >> n >> q;
    for(int i =0;i < n;i++){
        string s;
        cin >> s;
        mapa[s] = i;
    }
    while(q--){
        string s , t;
        cin >> s >> t;
        ll ans = abs(mapa[t] - mapa[s])-1 ;
        cout << ans << endl;
    }
    return 0;
}
