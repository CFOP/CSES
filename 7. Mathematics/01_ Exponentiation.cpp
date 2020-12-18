#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007

typedef long long ull;

ull p(ull a, ull b){

    if(b==0)
        return 1;
    if(b==1)
        return a;

    ull ans = p(a,b/2);
    ans *= ans;
    ans %= MOD;

    if(b%2){
        ans *= a;
        ans %= MOD;
    }

    return ans;

}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n; cin>>n;

    while(n--){
        ull a, b;
        cin>>a>>b;

        cout<<p(a,b)<<"\n";
    }

    return 0;
}
