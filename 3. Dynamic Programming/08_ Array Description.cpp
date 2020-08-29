#include <iostream>
#include <vector>
using namespace std;

#define MAX 100010
#define MOD 1000000007

int dp[MAX][110];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n, m;
    cin>>n>>m;

    int x; cin>>x;

    if(x){
        dp[1][x] = 1;
    }
    else {
        for(int i=1; i<=m; i++)
            dp[1][i] = 1;
    }

    for(int i=2; i<=n; i++){
        cin>>x;
        if(x){
            dp[i][x] = dp[i-1][x] + (dp[i-1][x+1] + dp[i-1][x-1])%MOD;
            dp[i][x] %= MOD;
        }
        else {
            for(int j=1; j<=m; j++){
                dp[i][j] = dp[i-1][j-1] + (dp[i-1][j] + dp[i-1][j+1])%MOD;
                dp[i][j] %= MOD;
            }
        }
    }

    /*for(int i =0; i<=n; i++){
        for(int j =0; j<=m; j++)
            cout<<dp[i][j]<<" ";
        cout<<"\n";
    }*/

    int ans = 0;
    for(int i=1; i<=m; i++){
        ans += dp[n][i];
        ans %= MOD;
    }

    cout<<ans<<"\n";

    return 0;
}
