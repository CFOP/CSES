#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007
#define MAX 130100

int dp[600][MAX];
int main(){
    int n; cin>>n;
    int sum = (n*(n+1))/2;
    for(int i = 1; i<=n; i++){
        dp[i+1][i] = 1;
        for(int j = 0; j<MAX; j++){
            if(dp[i][j]){
                dp[i+1][j] += dp[i][j];
                dp[i+1][j] %= MOD;

                dp[i+1][j+i] += dp[i][j];
                dp[i+1][j+i] %= MOD;
            }
        }
    }

    /*for(int i=1; i<=n+1; i++){
        for(int j = 0; j<30; j++)
            cout<<dp[i][j]<<" ";
        cout<<"\n";
    }*/

    long long ans = 0;
    for(int i=0; i<MAX; i++){
        if(i + i == sum){
            ans += dp[n+1][i];
            ans %= MOD;
        }
    }
    ans *= 500000004;
    ans %= MOD;

    cout<<ans<<"\n";
    return 0;
}
