#include <bits/stdc++.h>
using namespace std;

#define MAX 1005
#define MOD 1000000007

int dp[MAX][MAX];
char grid[MAX][MAX];

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n; cin>>n;

    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            cin>>grid[i][j];

    dp[0][0] = grid[0][0]=='.';

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(grid[i][j]=='.'){
                if(i>0)
                    dp[i][j]+=dp[i-1][j];
                dp[i][j]%=MOD;
                if(j>0)
                    dp[i][j]+=dp[i][j-1];
                dp[i][j]%=MOD;

            }
            //cout<<dp[i][j]<<" ";
        }
        //cout<<"\n";
    }

    cout<<dp[n-1][n-1]<<"\n";

    return 0;
}
