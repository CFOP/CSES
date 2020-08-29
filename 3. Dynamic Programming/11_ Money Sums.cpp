#include <bits/stdc++.h>
using namespace std;
#define MAX 100010

vector<int> x;
bool dp[110][MAX];
int main(){
    int n; cin>>n;
    for(int i=0; i<n; i++){
        int z; cin>>z;
        x.push_back(z);
    }

    for(int i=0; i<n; i++){
        dp[i+1][x[i]]=true;
        for(int j = 0; j<MAX; j++){
            if(dp[i][j]){
                dp[i+1][j] = true;
                dp[i+1][j+x[i]]=true;
            }
        }
    }
    vector<int> ans;
    for(int i=0; i<MAX; i++){
        if(dp[n][i]){
            ans.push_back(i);
        }
    }

    cout<<ans.size()<<"\n";
    for(int k : ans){
        cout<<k<<" ";
    }
    cout<<"\n";

    return 0;
}
