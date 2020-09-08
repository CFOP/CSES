#include <bits/stdc++.h>
using namespace std;
#define MAX 200100

vector<int> adj[MAX];
bool visited[MAX];

void dfs(int v, int &last, int &maxD, int d = 0){
    if(visited[v])
        return;
    visited[v] = true;

    if(d>maxD){
        maxD=d;
        last=v;
    }

    for(int u : adj[v]){
        dfs(u, last, maxD, d+1);
    }

}

int main(){
    int n; cin>>n;
    for(int i=1; i<n; i++){
        int a, b; cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    int v = 1, last = 1, maxD = 0;

    dfs(v, last, maxD);
    fill(visited, visited+MAX, false);
    dfs(last, v, maxD);

    cout<<maxD<<"\n";

    return 0;
}
