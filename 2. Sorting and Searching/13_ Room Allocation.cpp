#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n; cin>>n;

    int k = 1;
    vector<int> ans;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> seg; //end, room

    seg.push( {0, 1} );

    vector<pair<int, int>> costumersRealOrder; //begin, end
    vector<pair<int, int>> costumers; //begin, ID
    ans.resize(n);
    for(int i=0; i<n; i++){
        int a, b; cin>>a>>b;
        costumers.push_back({a, i});
        costumersRealOrder.push_back({a, b});
    }
    sort(costumers.begin(), costumers.end());

    for(auto costumer : costumers){

        int a = costumer.first; int b = costumersRealOrder[costumer.second].second;

        if(seg.top().first>=a){
            ans[costumer.second] = ++k;
            seg.push({b, k});
        }
        else {
            ans[costumer.second] = seg.top().second;
            seg.pop();
            seg.push( {b, ans[costumer.second]} );
        }

    }

    cout<<k<<"\n";
    for(int room : ans)
        cout<<room<<" ";
    cout<<"\n";

    return 0;
}
