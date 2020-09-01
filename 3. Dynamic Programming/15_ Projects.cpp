#include <bits/stdc++.h>
using namespace std;
#define MAX 200010

typedef long long ull;

vector<tuple<int, int, ull>> project; //end, start, reward
ull dp[MAX];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n; cin>>n;

    for(int i=0; i<n; i++){
        long long a, b, p;
        cin>>a>>b>>p;
        project.push_back(make_tuple(b, a, p));
    }
    sort(project.begin(), project.end());

    dp[0] = get<2>(project[0]);
    for(int i=1; i<n; i++){
        ull s = get<1>(project[i]), r = get<2>(project[i]);
        int last = lower_bound(project.begin(), project.end(), make_tuple(s, 0, 0)) - project.begin() - 1;
        dp[i] = max(dp[i-1], r);
        if(last>=0)
            dp[i] = max(dp[last] + r, dp[i]);
    }

    cout<<dp[n-1]<<"\n";

    return 0;
}
