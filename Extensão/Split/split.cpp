//
// Created by luise on 11/10/2023.
//
//Template By eduardocesb
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <iomanip>
#include <iostream>
#include <ranges>
#include <string_view>
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

vector<string> split(const string& str, char delimiter) {
    vector<string> tokens;
    size_t start = 0;

    while (start != string::npos) {
        size_t end = str.find(delimiter, start);
        tokens.push_back(str.substr(start, end - start));
        start = (end == string::npos) ? end : end + 1;
    }

    return tokens;
}

vector<string> split(const string& str) {
    vector<string> words;
    stringstream stream(str);
    string word;

    while(stream >> word) {
        words.push_back(word);
    }
    return words;
}


int main()
{
    string s;
    getline(cin,s);
    auto words = split(s,' ');
    for(auto x : words){
        cout << x << endl;

    }
    return 0;
}


