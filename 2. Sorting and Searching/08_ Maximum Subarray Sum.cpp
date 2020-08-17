#include <bits/stdc++.h>
using namespace std;

typedef long long ull;

priority_queue <ull, vector<ull>, greater<ull>> last;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n; cin>>n;
    ull sum = 0;
    ull ans = LLONG_MIN;
    last.push(0);
    for(int i=0; i<n; i++){
        ull a; cin>>a;
        sum+=a;
        ans = max(ans, sum-last.top());
        last.push(sum);
    }

    cout<<ans<<"\n";

    return 0;
}
