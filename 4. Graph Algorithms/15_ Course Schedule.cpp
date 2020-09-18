#include <bits/stdc++.h>
using namespace std;

#define MAX 100100

vector<int> adj[MAX];
int visited[MAX];

vector<int> ans;

void dfs(int v){
    if(visited[v] == 1){
        cout<<"IMPOSSIBLE\n";
        exit(0);
    }

    if(visited[v]) return;
    visited[v] = 1;

    for(int u : adj[v])
        dfs(u);

    ans.push_back(v);
    visited[v] = 2;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, m;
    cin>>n>>m;

    for(int i=0; i<m; i++){
        int a, b;
        cin>>a>>b;
        adj[b].push_back(a);
    }

    for(int i=1; i<=n; i++)
        dfs(i);

    for(int ans : ::ans)
        cout<<ans<<" ";
    cout<<"\n";

    return 0;
}
