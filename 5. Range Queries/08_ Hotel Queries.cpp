#include <bits/stdc++.h>
using namespace std;

typedef long long ull;

struct Tree {
	typedef ull T;
	static constexpr T unit = 0;
	T f(T a, T b) { return max(a, b); } // (any associative fn)
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

int bS(Tree &st, ull k, int l, int r){
    if(l+1>=r)
        return l;
    int m = (l+r)/2;

    if(st.query(l, m)>=k)
        return bS(st, k, l, m);
    return bS(st, k, m, r);
}

int main(){ ios_base::sync_with_stdio(0); cin.tie(0);

    int n, m; cin>>n>>m;

    Tree st(n+1);
    for(int i=1; i<=n; i++){
        ull z; cin>>z;
        st.update(i, z);
    }

    while(m--){
        ull r; cin>>r;
        if(st.query(0, n+1)<r)
            cout<<"0 ";
        else {
            int pos = bS(st, r, 1, n+1);
            st.update(pos, st.query(pos, pos+1)-r);
            cout<<pos<<" ";
        }
    }
    cout<<"\n";
}
