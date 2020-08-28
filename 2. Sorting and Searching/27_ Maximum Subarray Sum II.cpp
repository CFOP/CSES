#include <bits/stdc++.h>
using namespace std;

typedef long long ull;

int main(){
    int n; cin>>n;
    int a, b; cin>>a>>b;
    priority_queue<pair<ull, int>, vector<pair<ull, int>>, greater<pair<ull, int>>> last; //sum, pos
    vector<ull> x;

    x.push_back(0); cin>>x[0];
    for(int i=1; i<n; i++){
        int z; cin>>z;
        x.push_back(z+x[i-1]);
    }

    last.push({0, -1});
    ull ans = LLONG_MIN;
    for(int i = a-1; i<n; i++){
        while(last.top().second < i-b)
            last.pop();
        ans = max(ans, x[i] - last.top().first);
        last.push( {x[i-a+1], i-a+1} );
    }

    cout<<ans<<"\n";

    return 0;
}
