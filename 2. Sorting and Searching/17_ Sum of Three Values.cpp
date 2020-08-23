#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> a;

int main(){
    int n; cin>>n;
    int x; cin>>x;
    for(int i=0; i<n; i++){
        int z; cin>>z;
        a.push_back({z, i+1});
    }
    sort(a.begin(), a.end());
    for(int i=0; i<n; i++){
        int j = i+1; int k = n-1;
        while(j<k){
            if(a[i].first+a[j].first+a[k].first == x){
                cout<<a[i].second<<" "<<a[j].second<<" "<<a[k].second<<"\n";
                return 0;
            }
            if(a[i].first+a[j].first+a[k].first > x) k--;
            else j++;
        }
    }


    cout<<"IMPOSSIBLE\n";
}
