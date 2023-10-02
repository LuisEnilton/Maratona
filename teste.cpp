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
#define MAXN 1000
#define MAXL 23
#define endl '\n'

using namespace std;

template<class BidirectionalIterator>
bool my_next_permutation(BidirectionalIterator first, BidirectionalIterator last) {
    if (first == last) {
        // If the range is empty, there's no permutation.
        return false;
    }

    // Start from the rightmost element and find the first pair (i, i+1)
    // such that *i < *(i+1).
    BidirectionalIterator i = last;
    if (first == --i) {
        // If there's only one element in the range, it can't be permuted.
        return false;
    }

    while (true) {
        BidirectionalIterator i1 = i, i2;
        if (*--i < *i1) {
            // Found the first pair where *i < *i1.
            // Now find the rightmost element *i2 such that *i < *i2.
            i2 = last;
            while (!(*i < *--i2)) {}

            // Swap *i and *i2.
            std::iter_swap(i, i2);

            // Reverse the subsequence (i+1, last).
            std::reverse(i1, last);

            return true;
        }

        // If no such pair is found, continue checking further left.
        if (i == first) {
            std::reverse(first, last);
            return false;
        }
    }
}

int main(){
    vi nums = {1,1,2,3};
    string s = "abcd";
    int cnt = 0;
    do{

        for(auto x : s){
            cout << x << " ";
        }
        cout << endl;
        cnt++;
    }while(my_next_permutation(ALL(s)));
        cout << cnt << endl;
}