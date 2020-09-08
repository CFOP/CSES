#include <bits/stdc++.h>
using namespace std;
#define MAX 200100

vector<int> adj[MAX];
vector<int> dis(MAX);
vector<bool> visited(MAX);

void dfs(int v, int &last, int &maxD, int d=0){
    if(visited[v])
        return;
    visited[v] = true;

    dis[v] = max(d, dis[v]);
    if(d>maxD){
        last = v;
        maxD = d;
    }

    for(int u : adj[v])
        dfs(u, last, maxD, d+1);

}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n; cin>>n;

    for(int i=1; i<n; i++){
        int a, b; cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    int last = 1, maxD=0, last2;
    dfs(1, last, maxD);
    fill(visited.begin(), visited.end(), false); maxD=0;
    last2 = last;
    dfs(last, last2, maxD);
    fill(visited.begin(), visited.end(), false); maxD=0;
    dfs(last2, last, maxD);

    for(int i=1; i<=n; i++)
        cout<<dis[i]<<" ";

    return 0;
}
