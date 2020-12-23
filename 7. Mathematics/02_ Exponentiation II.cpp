#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007

typedef long long ull;

ull p(ull a, ull b, ull mod){

    if(b==0)
        return 1;
    if(b==1)
        return a;

    ull ans = p(a,b/2, mod);
    ans *= ans;
    ans %= mod;

    if(b%2){
        ans *= a;
        ans %= mod;
    }

    return ans;

}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n; cin>>n;

    while(n--){
        ull a, b, c;
        cin>>a>>b>>c;

        cout<<p(a,p(b, c, MOD-1), MOD)<<"\n";
    }

    return 0;
}

