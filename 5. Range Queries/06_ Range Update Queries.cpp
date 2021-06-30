#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ll;
typedef vector<ll> vi;

const ll inf = 0; //unit value
struct Node {

    static ll operation(ll a, ll b){
        return a+b;
    }

	Node *l = 0, *r = 0;
	ll lo, hi, mset = inf, madd = 0, val = -inf;
	ll lo, hi, mset = inf, madd = 0, val = -inf;
	Node(int lo,int hi):lo(lo),hi(hi){} // Large interval of -inf
	Node(vi& v, int lo, int hi) : lo(lo), hi(hi) {
		if (lo + 1 < hi) {
			int mid = lo + (hi - lo)/2;
			l = new Node(v, lo, mid); r = new Node(v, mid, hi);
			val = operation(l->val, r->val);
		}
		else val = v[lo];
	}
	ll query(int L, int R) {
		if (R <= lo || hi <= L) return 0;
		if (L <= lo && hi <= R) return val;
		push();
		return operation(l->query(L, R), r->query(L, R));
	}
	void set(int L, int R, ll x) {
		if (R <= lo || hi <= L) return;
		if (L <= lo && hi <= R) mset = val = x, madd = 0;
		else {
			push(), l->set(L, R, x), r->set(L, R, x);
			val = operation(l->val, r->val);
		}
	}
	void add(int L, int R, ll x) {
		if (R <= lo || hi <= L) return;
		if (L <= lo && hi <= R) {
			if (mset != inf) mset += x;
			else madd += x;
			val += x;
		}
		else {
			push(), l->add(L, R, x), r->add(L, R, x);
			val = operation(l->val, r->val);
		}
	}
	void push() {
		if (!l) {
			int mid = lo + (hi - lo)/2;
			l = new Node(lo, mid); r = new Node(mid, hi);
		}
		if (mset != inf)
			l->set(lo,hi,mset), r->set(lo,hi,mset), mset = inf;
		else if (madd)
			l->add(lo,hi,madd), r->add(lo,hi,madd), madd = 0;
	}
};


int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n, q;
    cin>>n>>q;
    vector<ll> x;
    for(int i=0; i<n; i++){
        ll z; cin>>z;
        x.push_back(z);
    }
    Node *st = new Node(x, 0, x.size());

    while(q--){
        int t; cin>>t;

        if(t==1){
            ll a, b, u; cin>>a>>b>>u;
            st->add(a-1, b, u);
        }
        else{
            ll a; cin>>a;
            cout<<st->query(a-1, a)<<"\n";
        }

    }
}
