#include <bits/stdc++.h>
using namespace std;

#define MAX 1005

int h[MAX];
int s[MAX];
int dp[MAX][100005];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, x; cin>>n>>x;
    for(int i=0; i<n; i++){
        cin>>h[i];
    }
    for(int i=0; i<n; i++){
        cin>>s[i];
    }

    int ans = 0;
    for(int i=0; i<n; i++){
        if(h[i]<=x){
            dp[i+1][h[i]] = max(s[i], dp[i][h[i]]);
            ans = max(ans, dp[i+1][h[i]]);
        }
        for(int j=0; j<=x; j++){
            if(dp[i][j]){
                dp[i+1][j] = max(dp[i+1][j], dp[i][j]);
                if(j+h[i]<=x){
                    dp[i+1][j+h[i]] = max(dp[i][j]+s[i],  dp[i+1][j+h[i]]);
                    ans = max( dp[i+1][j+h[i]], ans);
                }
            }
        }
    }
    cout<<ans<<"\n";

    return 0;
}
