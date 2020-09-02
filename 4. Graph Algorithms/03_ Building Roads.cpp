#include <bits/stdc++.h>
using namespace std;

#define MAX 100100

vector<int> adj[MAX];
bool visited[MAX];

void dfs(int v){
    if(visited[v])
        return;
    visited[v]=true;

    for(int u : adj[v])
        dfs(u);

}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n, m; cin>>n>>m;
    for(int i=0; i<m; i++){
        int a, b;cin>>a>>b;
        adj[a-1].push_back(b-1);
        adj[b-1].push_back(a-1);
    }

    vector<int> ans;
    for(int i=0; i<n; i++){
        if(!visited[i]){
            dfs(i);
            ans.push_back(i+1);
        }
    }

    cout<<ans.size()-1<<"\n";
    if(ans.size()){
        for(int i=1; i<ans.size(); i++){
            cout<<ans[i-1]<<" "<<ans[i]<<"\n";
        }
    }

    return 0;
}
