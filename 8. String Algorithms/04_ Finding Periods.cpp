#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()

typedef unsigned long long ull;
typedef long long ll;
typedef pair<ll, ll> pii;
typedef vector<ll> vi;

vi Z(string S) {
	vi z(sz(S));
	ll l = -1, r = -1;
	rep(i,1,sz(S)) {
		z[i] = i >= r ? 0 : min(r - i, z[i - l]);
		while (i + z[i] < sz(S) && S[i + z[i]] == S[z[i]])
			z[i]++;
		if (i + z[i] > r)
			l = i, r = i + z[i];
	}
	return z;
}

int main(){
    string s; cin>>s;
    auto pattern = Z(s);
    int min_period = s.size()-pattern.back();
    vector<int> ans;
    for(int i=1; i<s.size(); i++){
        if(pattern[i]+i == s.size())
            ans.push_back(i);
    }
    ans.push_back(s.size());

    for(int k : ans)
        cout<<k<<" ";
    return 0;
}
/*
aabaaabaaabaaabaaab

*/
