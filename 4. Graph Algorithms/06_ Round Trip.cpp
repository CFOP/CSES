#include <bits/stdc++.h>
using namespace std;
#define MAX 100100

vector<int> adj[MAX];
vector<int> ans;
int visited[MAX];

int dfs(int v, int a, int b){ //en cual estoy, de donde vengo
    if(visited[v]==1 && v!=a){
        //cout<<v<<" "<<p<<"#\n";
        ans.push_back(v+1);
        return v+1;
    }
    //cout<<v+1<<" "<<a+1<<" "<<b+1<<"\n";

    if(visited[v]) return 0;

    visited[v] = 1;

    for(int u : adj[v]){
        //cout<<v+1<<": "<<u+1<<"\n";
        int c = dfs(u, b, v);
        if(c){
            //cout<<v+1<<" "<<c<<"\n";
            if(c==-1) return -1;
            ans.push_back(v+1);
            if(c==v+1)
                return -1;
            return c;
        }
    }

    visited[v] = 2;

    return 0;

}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n, m; cin>>n>>m;
    for(int i=0; i<m; i++){
        int a, b;
        cin>>a>>b;
        adj[a-1].push_back(b-1);
        adj[b-1].push_back(a-1);
    }

    for(int i=0; i<n; i++)
        if(!visited[i] && dfs(i, -1, -1))
            break;

    if(ans.size()){
        reverse(ans.begin(), ans.end());
        cout<<ans.size()<<"\n";
        for(int v : ans)
            cout<<v<<" ";
        cout<<"\n";
    }
    else cout<<"IMPOSSIBLE\n";

    return 0;
}
/*
5 6
1 3
1 2
5 3
1 5
2 4
4 5
*/
