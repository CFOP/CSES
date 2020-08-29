#include <bits/stdc++.h>
using namespace std;

#define MAX 5050
typedef long long ull;

vector<ull> x;

ull dp[MAX][MAX];

ull findMax(int left, int right, bool first = true){
    if(!first){
        if(left==right)
            return 0;
        return min(findMax(left+1, right, true), findMax(left, right-1, true));
    }

    if(left==right)
        return x[left];
    if(dp[left][right])
        return dp[left][right];

    dp[left][right] = max(findMax(left+1, right, false)+x[left], findMax(left, right-1, false)+x[right]);
    return dp[left][right];
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n; cin>>n;
    for(int i=0; i<n; i++){
        int z; cin>>z;
        x.push_back(z);
    }

    cout<<findMax(0, n-1)<<"\n";

    return 0;
}
