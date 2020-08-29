#include <bits/stdc++.h>
using namespace std;

#define MAX 5010
int dp[MAX][MAX];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    string a, b; cin>>a>>b;
    for(int i=0; i<=a.size(); i++)
        fill(dp[i], dp[i]+MAX, INT_MAX);

    dp[0][0] = 0;
    for(int i=0; i<=a.size(); i++){
        for(int j=0; j<=b.size(); j++){
            if(i<a.size() && j<b.size())
                dp[i+1][j+1] = min(dp[i+1][j+1], dp[i][j] + (int)(a[i] != b[j]));
            dp[i+1][j] = min(dp[i+1][j], dp[i][j]+1);
            dp[i][j+1] = min(dp[i][j+1], dp[i][j]+1);
        }
    }

    cout<<dp[a.size()][b.size()]<<"\n";

    return 0;
}
