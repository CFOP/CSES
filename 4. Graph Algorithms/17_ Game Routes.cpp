#include <bits/stdc++.h>
using namespace std;

#define MAX 100100
#define MOD 1000000007
typedef pair<int, int> pii;

vector<int> adj[MAX];

int dp[MAX];
int nb[MAX];

bool visited[MAX];

void dfs(int v){
    if(visited[v] || nb[v])
        return;
    visited[v] = true;

    for(int u : adj[v]){
        nb[u]--;
        dp[u] += dp[v];
        dp[u] %= MOD;
        dfs(u);
    }

}

int main(){ ios_base::sync_with_stdio(0); cin.tie(0);
    int n, m;
    cin>>n>>m;

    for(int i = 0; i<m; i++){
        int a, b; cin>>a>>b;
        adj[a].push_back(b);
        nb[b]++;
    }

    dp[1]=1;
    nb[1]=0;
    for(int i=1; i<=n; i++)
        dfs(i);

    cout<<dp[n]<<"\n";

    return 0;
}
