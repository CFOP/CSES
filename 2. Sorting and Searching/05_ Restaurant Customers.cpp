#include <bits/stdc++.h>
using namespace std;
#define MAX 200100

vector<pair<int, int>> seg; //arrival, leaving
vector<int> leaving;
vector<int> arrival;

int main(){
    int n; cin>>n;
    while(n--){
        int a, b; cin>>a>>b;
        seg.push_back(make_pair(a, b));
        leaving.push_back(b);
        arrival.push_back(a);

    }

    //sort(seg.begin(), seg.end());
    sort(arrival.begin(), arrival.end());
    sort(leaving.begin(), leaving.end());

    int ans = 1;
    for(int i=0; i<seg.size(); i++){
        int endBefore = lower_bound(leaving.begin(), leaving.end(), seg[i].first) - leaving.begin();
        int beginAfter = lower_bound(arrival.begin(), arrival.end(), seg[i].first) - arrival.begin();
        beginAfter = seg.size() - beginAfter;
        ans = max(ans, (int)seg.size() - beginAfter - endBefore+1);

        //cout<<seg[i].first<<" "<<endBefore<<"\n";
    }

    cout<<ans<<"\n";
    return 0;
}
