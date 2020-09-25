#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

#define MAX 100100

vi adj[MAX];
vi inv[MAX];

vi order;

bool visited[MAX];
int kingdom[MAX];

void topSort(int v){
    if(visited[v]) return;
    visited[v] = true;

    for(int u : inv[v])
        topSort(u);

    order.push_back(v);
}

void dfs(int v, int k){
    if(kingdom[v])
        return;
    kingdom[v] = k;

    for(int u : adj[v])
        dfs(u, k);

}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n, m; cin>>n>>m;

    for(int i=0; i<m; i++){
        int a, b;
        cin>>a>>b;
        adj[a].push_back(b);
        inv[b].push_back(a);
    }

    for(int v=1; v<=n; v++) topSort(v);

    int k = 0; reverse(order.begin(), order.end());
    for(int v : order)
        if(!kingdom[v])
            dfs(v, ++k);

    cout<<k<<"\n";
    for(int i=1; i<=n; i++)
        cout<<kingdom[i]<<" ";
    cout<<"\n";

    return 0;
}
