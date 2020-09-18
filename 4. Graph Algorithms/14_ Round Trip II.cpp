#include <bits/stdc++.h>
using namespace std;

#define MAX 100100

vector<int> adj[MAX];
vector<int> ans;

int visited[MAX];

int dfs(int v){

    if(visited[v]==1){
        ans.push_back(v);
        return v;
    }
    if(visited[v]) return 0;

    visited[v] = 1;

    for(int u : adj[v]){
        if(u==v) continue;

        int p = dfs(u);
        if(p){

            ans.push_back(v);
            if(p==v) return 0;
            return p;

        }

        if(ans.size()) return 0;
    }

    visited[v] = 2;

    return 0;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, m; cin>>n>>m;
    for(int i=0; i<m; i++){
        int a, b; cin>>a>>b;
        adj[a].push_back(b);
    }

    for(int i=1; i<=n; i++){
        dfs(i);
        if(ans.size()){
            reverse(ans.begin(), ans.end());

            cout<<ans.size()<<"\n";
            for(int ans : ::ans)
                cout<<ans<<" ";
            cout<<"\n";

            return 0;
        }
    }

    cout<<"IMPOSSIBLE\n";

    return 0;
}
