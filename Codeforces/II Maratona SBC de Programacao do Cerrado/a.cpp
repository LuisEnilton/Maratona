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
const int MAXN = 1e5+5;

int pre[MAXN];
int atu[MAXN];
int ans[MAXN];

signed main() { op
    int n, c; cin >> n >> c;
    for(int i = 1; i <= n; i++) {
        cin >> pre[i];
    }
    int acres = 0;
    for(int i = 1; i <= c; i++) {
        int a; cin >> a;
        cin >> atu[a];
        acres+= atu[a];
    }
    for(int i = 1; i <= n; i++) {
        pre[i] += acres;
        acres -= atu[i];
    }
    vector<int> st;
    for(int i = 1; i <= n; i++) {
        
        ans[i] = st.size();
        while(st.size() && st.back() <= pre[i]) st.pop_back();
        
        st.push_back(pre[i]);
    }
    for(int i = 2; i <= n; i++) {
        cout << ans[i] << endl;
    }
}