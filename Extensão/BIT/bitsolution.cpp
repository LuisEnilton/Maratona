//
// Created by Luis on 20/07/2023.
//
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MAXN = 2e5 + 5;

ll bit[MAXN];
ll arr[MAXN];

void upd(int x, ll v){
    while(x < MAXN){
        bit[x] += v;
        x += (x & -x);
    }
}

ll qry(int x){
    ll ret = 0;

    while(x > 0){
        ret += bit[x];
        x -= (x & -x);
    }
    return ret;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, q;
    cin >> n >> q;

    for(int i = 0;i<n;i++){
        ll v;
        cin >> v;
        arr[i] = v;
        upd(i+1, v);
    }

    while(q--){
        int tp;
        cin >> tp;

        if(tp == 1){
            int x;
            ll v;
            cin >> x >> v;

            upd(x, -arr[x-1]);
            upd(x, v);

            arr[x-1] = v;
        }
        else{
            int l, r;
            cin >> l >> r;

            ll ret = qry(r) - qry(l-1);

            cout << ret << endl;
        }
    }
}