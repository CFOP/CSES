#include <bits/stdc++.h>
using namespace std;
#define MAX 3000

vector<int> adj[MAX];
vector<long long> cost[MAX];

vector<long long> d(MAX, LLONG_MIN);
bool inf[MAX];

int main(){
    int n, m;
    cin>>n>>m;
    while(m--){
        int a, b, c; cin>>a>>b>>c;
        adj[a].push_back(b);
        cost[a].push_back(c);
    }

    d[1] = 0;
    for(int i=1; i<n; i++)
        for(int v=1; v<=n; v++){
            if(d[v]==LLONG_MIN) continue;
            for(int j=0; j<adj[v].size(); j++){
                int u = adj[v][j]; long long c = cost[v][j];
                d[u] = max(d[u], d[v]+c);
            }
        }

    for(int i=0; i<n; i++)
        for(int v=1; v<=n; v++){
            if(d[v]==LLONG_MIN) continue;
            for(int j=0; j<adj[v].size(); j++){
                int u = adj[v][j]; long long c = cost[v][j];
                if(d[v]+c > d[u] || inf[v])inf[u] = true;
            }
        }

    if(inf[n]) cout<<"-1\n";
    else cout<<d[n]<<"\n";

    return 0;
}
