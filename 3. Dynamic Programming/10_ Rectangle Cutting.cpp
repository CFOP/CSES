#include <bits/stdc++.h>
using namespace std;
#define MAX 500

int dp[MAX+1000][MAX+1000];
int main(){
    for(int i=0; i<=MAX; i++)
        fill(dp[i], dp[i]+MAX+10, INT_MAX-1000);

    for(int i = 0; i<=MAX; i++)
        dp[i][i] = 0;

    for(int i = 1; i<=MAX; i++){
        for(int j=1; j<=MAX; j++){
            for(int k=1; k<=MAX; k++){
                dp[i+k][j] = min(dp[i+k][j], dp[i][j] + dp[k][j] + 1);
                dp[i][j+k] = min(dp[i][j+k], dp[i][j] + dp[i][k] + 1);
            }
        }
    }

    int a, b;
    cin>>a>>b;

    cout<<dp[a][b]<<"\n";


}
