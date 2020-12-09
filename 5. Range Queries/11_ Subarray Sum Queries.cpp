#include <bits/stdc++.h>
using namespace std;

typedef long long ull;

struct Range{

    ull min_sum;
    ull max_sum;
    ull sum;
    ull max_range;

    Range() : min_sum(0), max_sum(0), sum(0), max_range(0) {}
    Range(ull value) : sum(value), min_sum(min((ull)0, value)), max_sum(max((ull)0, value)), max_range(max(value, (ull)0)){}
    Range(ull sum, ull min_sum, ull max_sum, ull max_range) : sum(sum), min_sum(min_sum), max_sum(max_sum), max_range(max_range){}
};

inline Range join_range(Range a, Range b){
    return Range(a.sum + b.sum, min(a.min_sum, b.min_sum+a.sum), min(a.max_sum, b.max_sum+a.sum), max( {a.max_range, b.max_range, b.max_sum + a.sum - a.min_sum} ) );
}

struct Tree {
	typedef Range T;
	T f(T a, T b) { return join_range(a, b); } // (any associative fn)
	vector<T> s; int n;

	Tree(int n = 0) : s(2*n, T()), n(n) {}

	void update(int pos, T val) {
		for (s[pos += n] = val; pos /= 2;)
			s[pos] = f(s[pos * 2], s[pos * 2 + 1]);
	}
	T query(int b, int e) { // query [b, e)
		T ra = T(), rb = T();
		for (b += n, e += n; b < e; b /= 2, e /= 2) {
			if (b % 2) ra = f(ra, s[b++]);
			if (e % 2) rb = f(s[--e], rb);
		}
		return f(ra, rb);
	}
};

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n, m;
    cin>>n>>m;

    Tree st(n+1);

    for(int i=1; i<=n; i++){
        ull x; cin>>x;
        st.update(i, Range(x));
    }

    for(int i=1; i+1<=n; i++)
        cout<<st.query(i, i+2).max_sum<<" ";
    cout<<"#\n";

    while(m--){
        ull k, x; cin>>k>>x;
        st.update(k, Range(x));

        cout<<st.query(1, n+1).max_range<<"\n";
    }

    return 0;
}
