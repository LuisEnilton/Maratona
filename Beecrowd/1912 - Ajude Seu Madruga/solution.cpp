#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <string>
#include <algorithm>
#include <set>

#define optimize                 \
    ios::sync_with_stdio(false); \
    cin.tie(NULL);               \
    cout.tie(NULL)
#define INF 100000010
#define ALL(x) x.begin(), x.end()
#define UNIQUE(c) (c).resize(unique(ALL(c)) - (c).begin())
#define REP(i, a, b) for (int i = (a); i <= (b); i++)
#define POS(n, x) (lower_bound(ALL(n), x) - (n).begin())
#define ll long long
#define ld long double
#define pii pair<int, int>
#define vi vector<int>
#define vii vector<pii>
#define os_type int
#define PB push_back
#define EB emplace_back
#define MOD 1000000007
#define PRIME 101
#define MAXN 1010010
#define MAXL 23
#define endl '\n'

using namespace std;
using namespace __gnu_pbds;

#define ordered_set tree<os_type, null_type, less<os_type>, rb_tree_tag, tree_order_statistics_node_update>
using namespace std;

int N = 1, A = 1;
vi tiras;


int main() {
    optimize;
    while (N != 0 && A != 0) {
        cin >> N >> A;
        tiras.resize(N);
        int soma = 0;
        for (auto &tira: tiras) {
            cin >> tira;
            soma += tira;
        }
        if (soma == A) {
            cout << ":D" << endl;
            continue;
        }
        sort(ALL(tiras));

        int left = 0;
        int right = tiras[N - 1];
        int area = 0;
        while (left <= right) {
            int mid = left + (right - left) / 2;

            area = 0;
            for (auto &tira: tiras) {
                if (tira > mid)
                    area += tira-mid;
            }
            if (area == A) {
                cout << fixed << setprecision(4) << static_cast<double>(mid) << endl;
                break;
            } else if (area > A) {
                left = mid + 1; // Continue searching in the right half
            } else {
                right = mid - 1; // Continue searching in the left half
            }
        }
        if(area!=A){
            cout<<"-.-"<<endl;
        }
    }

}



//
// Created by Luis on 24/06/2023.
//
