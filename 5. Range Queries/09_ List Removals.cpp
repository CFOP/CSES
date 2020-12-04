#include <bits/stdc++.h>
using namespace std;

struct Tree {
	typedef int T;
	static constexpr T unit = 0;
	T f(T a, T b) { return a+b; } // (any associative fn)
	vector<T> s; int n;
	Tree(int n = 0, T def = unit) : s(2*n, def), n(n) {}
	void update(int pos, T val) {
		for (s[pos += n] = val; pos /= 2;)
			s[pos] = f(s[pos * 2], s[pos * 2 + 1]);
	}
	T query(int b, int e) { // query [b, e)
		T ra = unit, rb = unit;
		for (b += n, e += n; b < e; b /= 2, e /= 2) {
			if (b % 2) ra = f(ra, s[b++]);
			if (e % 2) rb = f(s[--e], rb);
		}
		return f(ra, rb);
	}
};

int n, m;

int bS(Tree &st, int p, int l, int r){
    if(l+1>=r)
        return l;

    //cout<<l<<" "<<r<<" "<<st.query(l, r)<<"\n";

    int m = (l+r)/2;

    if(st.query(0, m)<p)
        return bS(st, p, m, r);
    return bS(st, p, l, m);

}

int main(){ ios_base::sync_with_stdio(0); cin.tie(0);

    cin>>n; m=n;

    vector<int> x;
    Tree st(n);
    for(int i=0; i<n; i++){
        int z; cin>>z;
        x.push_back(z);
        st.update(i, 1);
    }

    while(m--){
        int p; cin>>p;
        p = bS(st, p, 0, n);
        st.update(p, 0);

        cout<<x[p]<<" ";//<<p<<" "<<st.query(0, n)<<"#\n";
    }
    cout<<"\n";

}

