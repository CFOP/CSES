#include <bits/stdc++.h>
using namespace std;
#define MAX 200010

vector <int> a;
int dp[MAX];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n; cin>>n;
    for(int i=0; i<n; i++){
        int z; cin>>z;
        a.push_back(z);
    }

    map <int, int, greater<int>> last; //size, number
    for(int i = 0; i<n; i++){
        auto p = last.upper_bound(a[i]);
        if(p==last.end()){
            if(last.size()){
                if(last.rbegin()->first > a[i]){
                    auto d = last.end();
                    d--;
                    last.erase(d);
                    last[a[i]]=1;
                }
            }
            else last[a[i]]=1;
        }
        else {
            if(p->second+1>last[a[i]]){
                last[a[i]] = p->second+1;
                auto k = last.find(a[i]);
                if(k==last.begin())continue;
                k--;
                while(k != last.begin() && k->second<=last[a[i]]){
                    auto del = k--;
                    last.erase(del);
                }
                if(last.begin()->second == last[a[i]] && last.begin()->first > a[i]) last.erase(last.begin());
            }
        }


        /*for(auto k = last.begin(); k!=last.end(); k++){
            cout<<k->first<<","<<k->second<<" ";
        }cout<<"\n";*/
    }

    cout<<last.begin()->second;
    return 0;
}
