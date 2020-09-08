#include <bits/stdc++.h>
using namespace std;
#define MAX 200100

int n;
vector<int> adj[MAX];
int sub[MAX];

int dfs(int v){
    if(sub[v])
        return sub[v];
    for(int u : adj[v]){
        sub[v] += dfs(u) + 1;
    }
    return sub[v];
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin>>n;
    for(int i=1; i<n; i++){
        int z; cin>>z;
        adj[z-1].push_back(i);
    }

    for(int i=0; i<n; i++)
        cout<<dfs(i)<<" ";
    cout<<"\n";

    return 0;
}
