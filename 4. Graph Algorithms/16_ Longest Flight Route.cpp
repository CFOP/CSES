#include <bits/stdc++.h>
using namespace std;

#define MAX 100100
typedef pair<int, int> pii;

vector<int> adj[MAX];
vector<int> p[MAX];

int nb[MAX];
int dp[MAX];

bool visited[MAX];

int main(){ ios_base::sync_with_stdio(0); cin.tie(0);
    int n, m;
    cin>>n>>m;

    for(int i = 0; i<m; i++){
        int a, b; cin>>a>>b;
        adj[a].push_back(b);
        p[b].push_back(a);
        nb[b]++;
    }

    priority_queue <pii, vector<pii>, greater<pii>> nxt; //nb, v
    nxt.push({0, 1}); dp[1] = 1;
    for(int i=2; i<=n; i++)
        nxt.push({nb[i], i});

    while(nxt.size()){
        int v = nxt.top().second; nxt.pop();

        if(!dp[v]) continue;

        if(visited[v]) continue;
        visited[v]=true;

        for(int u : adj[v]){
            if(visited[u]) continue; //que procd??
            dp[u] = max(dp[v]+1, dp[u]);
            nxt.push({--nb[u], u});
        }
    }

    if(!dp[n])
        cout<<"IMPOSSIBLE\n";
    else {
        cout<<dp[n]<<"\n";
        vector<int> ans;
        int v = n;
        while(v!=1){
            ans.push_back(v);
            int s;
            for(int u : p[v]){
                if(dp[u]+1 == dp[v])
                    s = u;
            }
            v = s;
        }
        ans.push_back(1);
        reverse(ans.begin(), ans.end());

        for(int a : ans)
            cout<<a<<" ";
        cout<<"\n";
    }

    return 0;
}
