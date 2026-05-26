//
// Created by Luis on 06/09/2023.
//
// Template By eduardocesb
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define optimize                 \
    ios::sync_with_stdio(false); \
    cin.tie(NULL);               \
    cout.tie(NULL);
#define INF 1000000010
#define INFLL 1000000000000000010LL
#define ALL(x) x.begin(), x.end()
#define ll long long
#define pii pair<int, int>
#define vi vector<int>
#define vb vector<bool>
#define vii vector<pii>
#define os_type int
#define PB push_back
#define EB emplace_back
#define MOD 1000000007
#define MAXN 300010
#define MAXL 20
#define int ll
#define EPS 1e-9
#define dbg(x) cout << #x << " " << x << endl;
#define endl '\n'
using namespace std;


void solve()
{
    int n; cin >> n;
    vi a(n);

    vii aux(n);
    for(auto & x : a) cin >> x;

    for(int i = 0; i < n;i++){
        aux[i] = {a[i],i};
    }

    vi l(n),r(n);
    vi cor(n + 1);
    cor[n] = INF;
    vi st;
    for(int i = 0; i <n;i++){

        while(st.size() && a[st.back()] <= a[i]) st.pop_back();


        l[i] = (st.size() ? st.back():n);
        st.push_back(i);
    }

    st.clear();
    for(int i = n - 1; i >=0 ;i--){

        while(st.size() && a[st.back()] <= a[i]) st.pop_back();
        r[i] = (st.size() ? st.back():n);
        st.push_back(i);
    }

    sort(ALL(aux));
    reverse(ALL(aux));
    int maxi = 1;
    for(auto [val,id] : aux){
        // dbg(id);
        int c1 = cor[l[id]];
        int c2 = cor[r[id]];
        // dbg(c1);
        // dbg(c2);
        set<int> sla;
        sla.insert(c1);
        sla.insert(c2);

        int mex = 1;
        while(sla.count(mex)) mex++;
        cor[id] = mex;
        maxi = max(maxi,mex);
    }
    cout << maxi << endl;   
    for(int i = 0; i < n;i++){
        cout << cor[i] << " ";
    }
    cout << endl;
}

signed main()
{
    optimize;
    freopen("tour.in","r",stdin);
    // freeopen("hello.in","w");

    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
