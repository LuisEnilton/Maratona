#include <bits/stdc++.h>

#define PB push_back
#define EB emplace_back
#define F first
#define S second
#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f
#define ALL(x) x.begin(), x.end()
using namespace std;
#define dbg(x) cout << #x << " " << x << endl;
using ll = long long;
#define int ll
using vi = vector<int>;
using vc = vector<char>;
using ii = pair<int, int>;
using vii = vector<ii>;

void print_mat(vector<vc> &a)
{
    int n = a.size();
    for (int i = 0; i < n; i++)
    {

        for (int j = 0; j < n; j++)
        {
            cout << a[i][j];
        }
        cout << endl;
    }
}

vector<vc> rotate(vector<vc> &a)
{

    int n = a.size();
    vector<vc> ans(n, vc(n));
    for (int i = 0; i < n; i++)
    {

        for (int j = 0; j < n; j++)
        {
            ans[j][n - i - 1] = a[i][j];
        }
    }
    return ans;
}

int n;
int solve(vector<vc> &grid)
{

    int l = 1, r = n / 2;

    auto create = [&](int sz)
    {
        vector<vc> sla(sz, vc(sz));

        for (int i = 0; i < sz;i++){
            for(int j = 0; j < sz;j++){
                sla[i][j] = grid[i][j];
            }
        }
        return sla;
    };

    auto check = [&](int sz){
        // dbg(sz);
        auto aux = create(sz);
        auto sup_dir = rotate(aux);
        auto  inf_dir = rotate(sup_dir);
        // print_mat(aux);
        // print_mat(sup_dir);
        // print_mat(inf_dir);

        for(int i = 0;i < sz;i++){
            for(int j = n -sz,aux_j = 0;j < n;j++,aux_j++){

                if(grid[i][j] !=  sup_dir[i][aux_j]) return false;
            }
        }

        for(int i = n - sz,aux_i = 0;i < n;i++,aux_i++){
            for(int j = n -sz,aux_j = 0;j < n;j++,aux_j++){
                if(grid[i][j] !=  inf_dir[aux_i][aux_j]) return false;
            }
        }
        return true;

    };

    int ans = 0;
    while (l <= r)
    {

        int m = (l + r) / 2;
    
        if(check(m)){
            ans = m;
            l = m + 1;
        }else{
            r = m - 1;
        }
    
    }
    return ans;
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    vector<vc> grid(n, vc(n));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> grid[i][j];
        }
    }

    auto op2 = rotate(grid);
    // print_mat(grid);
    // cout << endl;
    // print_mat(op2);
    auto op3 = rotate(op2);
    auto op4 = rotate(op3);

    int ans1 = solve(grid), ans2 = solve(op2) , ans3 = solve(op3), ans4  = solve(op4);


    cout << max({ans1,ans2,ans3,ans4}) << endl;


}