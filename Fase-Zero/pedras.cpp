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
#define MAXN 101010
#define MAXL 23
#define endl '\n'

using namespace std;
using namespace __gnu_pbds;

#define ordered_set tree<os_type, null_type, less<os_type>, rb_tree_tag, tree_order_statistics_node_update>

int *reduceArray(const int *arr, bool final, int size)
{
    int *copiedArray = new int[size - 1];
    if (final)
    {
        for (size_t i = 0; i < size - 1; i++)
        {
            copiedArray[i] = arr[i];
        }
    }
    else
    {
        for (size_t i = 1; i < size; i++)
        {
            copiedArray[i - 1] = arr[i];
        }
    }
    return copiedArray;
}



int teste(int result, int palp[], int desv[], bool final, int n)
{
    if (n == 0)
        return result;

    if (final)
    {
        if (palp[n - 1] - desv[n - 1] != result)
        {
            return -1;
        }
    }
    else
    {
        if (palp[0] + desv[n - 1] != result)
        {
            return -1;
        }
    }
    int valor =  teste(result,reduceArray(palp, final, n),reduceArray(desv, true, n),true,n-1 );
    if ( valor != -1) return valor;
    return teste(result,reduceArray(palp, final, n),reduceArray(desv, true, n),false,n-1 );
}

int main(int argc, char const *argv[])
{
    int n;
    set<int> answer;
    cin >> n;
    int palp[n];
    int desv[n];
    for (size_t i = 0; i < n; i++)
    {
        cin >> palp[i];
    }
    for (size_t i = 0; i < n; i++)
    {
        cin >> desv[i];
    }
    sort(palp, palp + n);
    sort(desv, desv + n);
    // teste1
    int result = palp[n - 1] - desv[n - 1];

    int a = teste(result, reduceArray(palp, true, n), reduceArray(desv, true, n), true, n-1);
    if (a>-1) answer.insert(a);
    a = teste(result,reduceArray(palp, true, n),reduceArray(desv, true, n),false,n-1);
    if (a>-1) answer.insert(a);

    // teste2
    result = palp[0] + desv[n - 1];
     a = teste(result, reduceArray(palp, false, n), reduceArray(desv, true, n), true, n-1);
    if (a>-1) answer.insert(a);
     a = teste(result, reduceArray(palp, false, n), reduceArray(desv, true, n), false, n-1);
    if (a>-1) answer.insert(a);
    
    for (const auto& element : answer) {
        cout << element << endl;
    }
    
    return 0;
}
