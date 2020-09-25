#include <bits/stdc++.h>
using namespace std;

#define MAX 100100

typedef vector<int> vi;
typedef long long ull;
typedef pair<ull, pair<int, int>> pii;

vi adj[MAX];
vi inv[MAX];
int visited[MAX];

void dfs(vi *adj, int s, int v, int p = 0){
    if(visited[v]>=s)
        return;
    visited[v]+=s;

    int ans = 0;
    for(int u : adj[v])
        dfs(adj, s, u, v);

}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n, m;
    cin>>n>>m;

    for(int i=0; i<m; i++){
        int a, b; cin>>a>>b;
        adj[a].push_back(b);
        inv[b].push_back(a);
    }

    dfs(adj, 1, 1);
    dfs(inv, 2, 1);

    for(int i=1; i<=n; i++)
        if(!visited[i] || visited[i]==2){
            cout<<"NO\n";
            cout<<1<<" "<<i<<"\n";
            return 0;
        }
        else if(visited[i]==1){
            cout<<"NO\n";
            cout<<i<<" "<<1<<"\n";
            return 0;
        }

    cout<<"YES\n";

    return 0;
}
