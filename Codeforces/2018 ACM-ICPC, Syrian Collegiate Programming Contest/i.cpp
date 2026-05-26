#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ld long double
#define br '\n'
#define int ll

struct PT {
    ld x, y;
    PT(ld x=0, ld y=0) : x(x), y(y) {}
    PT operator+(const PT&a)const{return PT(x+a.x, y+a.y);}
    PT operator-(const PT&a)const{return PT(x-a.x, y-a.y);}
    
    ld operator%(const PT&a)const{return  (x*a.y - y*a.x);}
    PT operator/(ld c) const{ return PT(x/c, y/c); }
    
    ld operator*(const PT&a)const{return  (x*a.x + y*a.y);} //dot
    PT operator*(ld c) const{ return PT(x*c, y*c);}

    ld len() const { return hypot(x,y); } 
};

ld dist(PT p, PT q){ return sqrtl((p-q)*(p-q)); }
PT rotateCCW90(PT p) { return PT(-p.y, p.x); }



PT ccCenter(PT& A, PT& B, PT& C) {
	PT b = C-A, c = B-A;
	return A + rotateCCW90(b*(c*c) - c*(b*b)) / (b%c) / 2;
}

pair<PT, ld> minEnclose(vector<PT> ps) {
	shuffle(begin(ps), end(ps), mt19937(time(0)));
	PT o = ps[0];
	ld r=0, EPS = 1 + 1e-8;

	for(int i=0; i<ps.size(); i++) if(dist(o, ps[i]) > r*EPS){
    o = ps[i], r = 0;

		for(int j=0; j<i; j++) if(dist(o, ps[j]) > r*EPS){
      o = (ps[i] + ps[j]) / 2;
      r = dist(o, ps[i]);
      
      for(int k=0; k<j; k++) if(dist(o, ps[k]) > r*EPS){
        o = ccCenter(ps[i], ps[j], ps[k]);
        r = (o - ps[i]).len();
      }
    }
	}
	
  return {o, r};
}


void solve() {
    int n, R, r;
    cin >> n >> R >> r;
    vector<PT> pts;
    pts.push_back({0,0});

    int a, b;
    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        pts.push_back(pts.back() + PT(a,b));
    }

    auto ans = minEnclose(pts);
    cout << -ans.first.x << ' ' << -ans.first.y << br;


}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("robots.in", "r", stdin);
    cout << setprecision(10) << fixed;

    int tc = 1;
    cin >> tc;

    while (tc--)
    {
        solve();
    }

    return 0;    
}