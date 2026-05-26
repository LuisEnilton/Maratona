#include <bits/stdc++.h>
using namespace std;
#define op ios::sync_with_stdio(false); cin.tie(NULL);
#define INF 0x3f3f3f3f
#define pii pair<int,int>
#define ll long long
#define mkp make_pair
#define endl '\n'
#define f first
#define s second
#define int long long
#define dbg(x) cout << #x << " " << x << endl;
const int MAXN = 1e6+5;


signed main() { op
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        vector <int> sus(n+1);
        for(int i = 0; i < n; i++) {
            int k; cin >> k;
            for(int j = 0; j < k; j++) {
                int a; cin >> a;
                sus[a]++;
            }
        }
        int lim = n/2;
        lim++;
        vector <int> ans;
        for(int i = 1; i <= n; i++) {
            if(sus[i] >= lim) ans.emplace_back(i);
        }
        cout << ans.size() << endl;
        for(auto x : ans) {
            cout << x << " ";
        }
        cout << endl;
    }
}