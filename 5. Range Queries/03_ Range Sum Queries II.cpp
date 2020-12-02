#include <bits/stdc++.h>
using namespace std;

struct Tree {
	typedef long long T;
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

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n, q;
    cin>>n>>q;
    Tree st(n);
    for(int i=0; i<n; i++){
        int z; cin>>z;
        st.update(i, z);
    }

    while(q--){
        int t; cin>>t;
        int a, b; cin>>a>>b;
        if(t==1){
            st.update(a-1, b);
        }
        else {
            cout<<st.query(a-1, b)<<"\n";
        }
    }

}


