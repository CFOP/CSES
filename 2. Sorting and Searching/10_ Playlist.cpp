#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n; cin>>n;
    vector<int> k;
    for(int i=0; i<n; i++){
        int z; cin>>z;
        k.push_back(z);
    }

    set<int> list;
    list.insert(k[0]);
    int last = 0;
    int ans = 1;

    for(int i=1; i<k.size(); i++){

        if(list.find(k[i])!=list.end()){ //ya esta en la lista
            auto d = list.find(k[i]);
            while(k[last]!=k[i])
                list.erase(k[last++]);
            list.erase(k[last++]);
        }
        list.insert( k[i]);
        ans = max((int)list.size(), ans);

    }

    cout<<ans<<"\n";

    return 0;
}
