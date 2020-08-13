#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> seg;

int main(){
    int n; cin>>n;
    while(n--){
        int a, b;
        cin>>a>>b;
        seg.push_back( {b, a} );
    }

    sort(seg.begin(), seg.end());

    int ans = 1;
    int last = seg[0].first;

    for(pair<int, int> p : seg){
        if(p.second >= last){
            last = p.first;
            ans++;
        }
    }

    cout<<ans<<"\n";
    return 0;
}
