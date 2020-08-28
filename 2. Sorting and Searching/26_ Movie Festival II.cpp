#include <bits/stdc++.h>
using namespace std;

int main(){
    int n; cin>>n;
    int k; cin>>k;

    vector<pair<int, int>> movie; // end, begin

    for(int i=0; i<n; i++){
        int a, b; cin>>a>>b;
        movie.push_back({b, a});
    }

    sort(movie.begin(), movie.end());

    multiset <int, greater<int>> time;
    int ans = 0;
    for(int i=0; i<k; i++)time.insert(0);

    for(auto p : movie){
        if(time.lower_bound(p.second)!=time.end()){
            time.erase(time.lower_bound(p.second));
            time.insert(p.first);
            ans++;
        }
    }

    cout<<ans<<"\n";
    return 0;
}
/*
5 2
1 5
8 10
3 6
2 5
6 9
*/
