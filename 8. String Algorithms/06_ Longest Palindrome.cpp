#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()

typedef unsigned long long ull;
typedef long long ll;
typedef pair<ll, ll> pii;
typedef vector<ll> vi;

array<vi, 2> manacher(const string& s) {
	int n = sz(s);
	array<vi,2> p = {vi(n+1), vi(n)};
	rep(z,0,2) for (ll i=0,l=0,r=0; i < n; i++) {
		ll t = r-i+!z;
		if (i<r) p[z][i] = min(t, p[z][l+t]);
		ll L = i-p[z][i], R = i+p[z][i]-!z;
		while (L>=1 && R+1<n && s[L-1] == s[R+1])
			p[z][i]++, L--, R++;
		if (R>r) l=L, r=R;
	}
	return p;
}

int main(){
    string s; cin>>s;
    auto man = manacher(s);
    /*for(auto k : man[0])
        cout<<k<<" ";
    cout<<"\n";
    for(auto k : man[1])
        cout<<k<<" ";
    cout<<"\n";*/
    int pos = 0;
    int sz = 0;
    for(int i=0; i<s.size(); i++){
        if(man[0][i]*2 > sz){
            sz = man[0][i]*2;
            pos = i-man[0][i];
        }
    }
    for(int i=0; i<s.size(); i++){
        if(man[1][i]*2+1 > sz){
            sz = man[1][i]*2+1;
            pos = i-man[1][i];
        }
    }
    string ans = s.substr(pos, sz);
    cout<<ans<<"\n";
    return 0;
}
