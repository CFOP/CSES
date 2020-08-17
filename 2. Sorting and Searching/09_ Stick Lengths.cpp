#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n; cin>>n;
    vector <int> p;
    p.resize(n);

    ull sum = 0;
    for(int i =0; i<n; i++){
        cin>>p[i];
        sum += p[i];
    }

    sort(p.begin(), p.end());

    ull ans = ULLONG_MAX;
    ull sum2 = 0;
    for(int i =0; i<n; i++){
        //cout<<p[i]<<" ";
        ull d = p[i];
        ans = min(ans, (sum - d*(n-i)) + ( d*i- sum2) );
        sum-=d;
        sum2+=d;
        //cout<<sum<<" "<<sum2<<"\n";
    }

    cout<<ans<<"\n";

    return 0;
}
