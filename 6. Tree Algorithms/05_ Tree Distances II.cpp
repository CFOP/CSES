#include <bits/stdc++.h>
using namespace std;
#define MAX 200100

vector<int> adj[MAX];
long long dp[MAX];
long long c[MAX];

void dfs(int v, int dad = -1, int d = 0){

    for(int u : adj[v]){
        if(u!=dad){
            dfs(u, v, d+1);
            c[v]+=c[u];
            dp[v] += c[u] + dp[u];
        }
    }

    //cout<<v<<" "<<ans<<" "<<dp[v]<<"\n";
    c[v]++;
}

void dfs2(int v, int dad = -1, int d = 0){

    for(int u : adj[v]){
        if(u!=dad){
            dp[u] += dp[v] - (dp[u]+c[u]) + (c[v]-c[u]);
            c[u] += (c[v] - c[u]);
            dfs2(u, v, d+1);
        }
    }

    //cout<<v<<" "<<ans<<" "<<dp[v]<<"\n";

}

int main(){
    int n; cin>>n;

    for(int i=1; i<n; i++){
        int a, b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    int init = 0;
    for(int i=1; i<=n; i++)
        if(adj[i].size() == 1) init = i;

    dfs(init);
    //c[init] = 0;
    dfs2(init);

    for(int i=1; i<=n; i++)
        cout<<dp[i]<<" ";
    cout<<"\n";

    return 0;
}
