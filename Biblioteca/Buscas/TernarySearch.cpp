#include <bits/stdc++.h>
using namespace std;
#define LOG 100
#define INF 1000000010

//Definition
// We have a function f on [A, B] and we'd like to get the minimum position in this function. 
//More formally we'd like to find x (A ≤ x ≤ B) such that for every y (A ≤ y ≤ B), f(x) ≤ f(y).

// Real Numbers

int A = 0, B = INF;

double ternary_search()
{
    double ans;
    for (int i = 0; i < LOG; i++)
    {
        long double m1 = (A * 2 + B) / 3.0;
        long double m2 = (A + 2 * B) / 3.0;

        if (f(m1) > f(m2))
            A = m1;
        else
            B = m2;
    }

    ans = f(A);
}

// Integers
int ternary_search_int(){
   int ans;
    while(B - A > 4)
{
    int m1 = (A + B) / 2;
    int m2 = (A + B) / 2 + 1;

    if(f(m1) > f(m2))
       A = m1;
    else
       B = m2;
}

ans = INF;

for(int i = A; i <= B; i++)
    ans = min(ans , f(i));
}