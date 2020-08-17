#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007

int main(){
    int n; cin>>n;
    int ans = 1;
    while(n--){
        ans *= 2;
        ans %= MOD;
    }
    cout<<ans<<"\n";
    return 0;
}
