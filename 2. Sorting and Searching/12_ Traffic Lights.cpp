#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);

    int x, n; cin>>x>>n;

    set<pair<int, int>> segByPos; //lastPos, size
    set<pair<int, int>, greater<pair<int, int>> > segBySize; //size, lastPos

    segByPos.insert( {x, x} );
    segBySize.insert( {x, x} );

    while(n--){
        int p; cin>>p;
        auto next = *segByPos.upper_bound( {p, 0} );
        segByPos.erase(next);
        segBySize.erase( {next.second, next.first} );

        segByPos.insert( {next.first, next.first-p} );
        segByPos.insert( {p, next.second - (next.first-p) } );

        segBySize.insert( {next.first-p, next.first} );
        segBySize.insert( {next.second - (next.first-p), p} );

        cout<<(*segBySize.begin()).first<<" ";
    }
    cout<<"\n";

    return 0;
}
