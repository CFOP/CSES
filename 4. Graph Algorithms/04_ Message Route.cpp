#include <bits/stdc++.h>
using namespace std;

#define MAX 100100

vector<int> adj[MAX];
int last[MAX];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n, m; cin>>n>>m;
    while(m--){
        int a, b; cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    queue<int> nexT;
    last[1]=-1;
    nexT.push(1);
    while(nexT.size()){

        int v = nexT.front(); nexT.pop();
        for(int u : adj[v]){
            if(!last[u]){
                last[u] = v;
                nexT.push(u);
            }
        }

    }

    if(!last[n]){
        cout<<"IMPOSSIBLE\n";
        return 0;
    }

    vector<int> ans;
    for(int v = n; v>=1; v=last[v])
        ans.push_back(v);
    reverse(ans.begin(), ans.end());

    cout<<ans.size()<<"\n";
    for(int v : ans)
        cout<<v<<" ";
    cout<<"\n";

    return 0;
}
