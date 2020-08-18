#include <bits/stdc++.h>
using namespace std;

int main(){
    int n; cin>>n;

    multiset<int, less<int>>last;
    for(int i=0; i<n; i++){
        int k; cin>>k;
        auto next = last.upper_bound(k);
        if(next != last.end()){
            last.erase(next);
        }
        last.insert(k);
    }

    cout<<last.size()<<"\n";

    return 0;
}
