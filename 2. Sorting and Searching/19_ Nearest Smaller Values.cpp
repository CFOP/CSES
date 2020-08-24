#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n; cin>>n;

    map <int, int, greater<int>> next;
    for(int i=1; i<=n; i++){
        int x; cin>>x;
        auto p = next.upper_bound(x);

        if(p!=next.end())
            cout<<p->second<<" ";
        else cout<<0<<" ";

        while(next.size() && next.begin()->first >= x){
            next.erase(next.begin());
        }

        next[x] = i;
    }
}
