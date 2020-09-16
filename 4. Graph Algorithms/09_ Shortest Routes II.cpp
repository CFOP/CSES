#include <bits/stdc++.h>
using namespace std;

#define MAX 600

vector<vector<long long>> dp(MAX, vector<long long>(MAX, LLONG_MAX));

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n, m, q;
    cin>>n>>m>>q;

    for(int i=0; i<m; i++){
        long long a, b, c; cin>>a>>b>>c;
        dp[b][a] = dp[a][b] = min(dp[a][b], c);
    }
    for(int i=0; i<=n; i++)dp[i][i]=0;

    for(int k=1; k<=n; k++)
        for(int j=1; j<=n; j++)
            for(int i=1; i<=n; i++){
                if(dp[i][k]==LLONG_MAX || dp[k][j]==LLONG_MAX) continue;
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
                dp[i][j] = dp[j][i] = min(dp[i][j], dp[j][i]);
            }


    while(q--){
        int a, b;
        cin>>a>>b;
        if(dp[a][b]!=LLONG_MAX)
            cout<<dp[a][b]<<"\n";
        else cout<<"-1\n";
    }

    return 0;
}
