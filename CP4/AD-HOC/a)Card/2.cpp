//
// Created by Luis on 09/04/2024.
//
//Template By eduardocesb
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <cmath>

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
#define vb vector<bool>
#define vii vector<pii>
#define os_type int
#define PB push_back
#define EB emplace_back
#define MOD 1000000007
#define PRIME 101
#define MAXN 1010101
#define MAXL 23
#define EPS 1e-9
#define endl '\n'

using namespace std;
using namespace __gnu_pbds;

#define ordered_set tree<os_type, null_type,less<os_type>, rb_tree_tag,tree_order_statistics_node_update>


int main() {
    optimize;
    int t; cin >> t;
    while(t--){
        string s;
        deque<char> ja[2],jo[2];
        int cnt = 0;
        cin >> s;
        for(auto x : s) ja[0].push_back(x);
        cin >> s;
        for(auto x : s) jo[0].push_back(x);
        while((ja[0].size() + ja[1].size())!=0 && (jo[0].size() + jo[1].size()) != 0){
            auto curr = ja[0].front(),curr2 = jo[0].front();
            ja[0].pop_front();jo[0].pop_front();
            ja[1].push_back(curr);
            jo[1].push_back(curr2);
            cnt++;
            if(cnt > 1000) break;
            if(curr == curr2){
                //if jane
                if(rand()/141%2 == 0){
                    for(int i = jo[1].size();i>=0;i--){
                        ja[1].push_front(jo[1][i]);
                        ja[i].pop_back();
                    }
                    cout << "Snap! for Jane: ";
                    for(auto x : ja[1]) cout << x;
                    cout << endl;
                }else{
                    for(int i = ja[1].size();i>=0;i--){
                        jo[1].push_front(ja[1][i]);
                        jo[i].pop_back();
                    }
                    cout << "Snap! for John: ";
                    for(auto x : ja[1]) cout << x;
                    cout << endl;
                }

            }

        }
        if(cnt > 1000){
            cout << "Keeps going and going ..." << endl;
        }else{
            if(ja[0].size() + ja[1].size() == 0){
                cout << "John wins." << endl;
            }else{
                cout << "Jane wins." << endl;
            }
        }
        cout << endl;
    }
    return 0;
}

