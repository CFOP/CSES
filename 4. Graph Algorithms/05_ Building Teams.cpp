#include <bits/stdc++.h>
using namespace std;
#define MAX 100100

vector<int> adj[MAX];
int team[MAX];
int n, m;

bool dfs(int v = 0, int t = 1){
    if(team[v])
        return team[v]==t;
    team[v] = t;

    for(int u : adj[v])
        if(!dfs(u, t==1?2:1))
            return false;
    return true;
}

bool setTeam(){
    for(int i=0; i<n; i++)
        if(!team[i] && !dfs(i))
            return false;
    return true;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin>>n>>m;
    while(m--){
        int a, b; cin>>a>>b;
        adj[a-1].push_back(b-1);
        adj[b-1].push_back(a-1);
    }

    if(setTeam()){
        for(int i=0; i<n; i++)
            cout<<team[i]<<" ";
        cout<<"\n";
    }
    else cout<<"IMPOSSIBLE\n";

    return 0;
}
