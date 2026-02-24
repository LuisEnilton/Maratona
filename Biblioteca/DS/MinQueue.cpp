#include <bits/stdc++.h>

using namespace std;
// Funciona para operações não inversiveis
// Ex: Xor, min , gcd
struct Queue
{
    stack<pair<int, int>> in, out;
    int NEUTRO = 0;
    int join(int a, int b){
        return a | b;
    }
    void push(int x)
    {
        if(in.empty()) { in.emplace(x, x); }
        else { in.emplace(x, join(x , in.top().second));}
    }
 
    void pop()
    {
        if(out.empty())
        {
            while(!in.empty())
            {
                int x = in.top().first;
                in.pop();
                if(out.empty())
                    out.emplace(x, x);
                else
                    out.emplace(x, join(x , out.top().second));
            }
        }
        out.pop();
    }
 
    int OR()
    {
        int ans1 = in.size() ? in.top().second : NEUTRO;
        int ans2 = out.size() ? out.top().second : NEUTRO;
        return join(ans1 , ans2);
    }
};