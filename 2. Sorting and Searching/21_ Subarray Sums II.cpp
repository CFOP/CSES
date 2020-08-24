#include <bits/stdc++.h>
using namespace std;

map<long long, int> last;
int main(){
    int n, x; cin>>n>>x;
    long long ans = 0;
    long long sum = 0;
    last[0]=1;
    for(int i=0; i<n; i++){
        int z; cin>>z;
        sum += z;
        ans += last[sum-x];
        last[sum]++;
    }

    cout<<ans<<"\n";
    return 0;
}

