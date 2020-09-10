#include <bits/stdc++.h>
using namespace std;

#define MAX 200100

set <pair<int, int>, greater<pair<int, int>>> level[MAX]; //time, id
vector<int> adj[MAX];
int d[MAX];
int T[MAX];

int t = 0;
void dfs(int v=1){

    T[v] = t;
    level[d[v]].insert({t++, v});

    for(int u : adj[v]){
        d[u] = d[v]+1;
        dfs(u);
    }

}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n, q;
    cin>>n>>q;

    for(int i=2; i<=n; i++){
        int a; cin>>a;
        adj[a].push_back(i);
    }

    dfs();

    while(q--){

        int x, k; cin>>x>>k;

        if(d[x]-k < 0)
            cout<<"-1\n";
        else {
           auto p = level[d[x]-k].lower_bound({T[x], INT_MAX});
           cout<<p->second<<"\n";
        }

    }

    return 0;
}
