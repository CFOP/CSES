#include <bits/stdc++.h>
using namespace std;

#define MAX 200100

set< pair<int, int>, greater<pair<int, int>> > level[MAX]; //time, id
vector<int> adj[MAX];

int d[MAX];
int t[MAX];

int actualT = 0;
void dfs(int v){

    t[v] = actualT;
    level[d[v]].insert( {actualT++, v} );

    for(int u : adj[v]){
        d[u] = d[v]+1;
        dfs(u);
    }

}

bool posible(int a, int b, int m){
    if(m > min(d[a], d[b]))
        return false;

    auto A = level[m].lower_bound({t[a], INT_MAX});
    auto B = level[m].lower_bound({t[b], INT_MAX});

    return A==B;
}

//11111111111000000000000
int bs(int a, int b, int l, int r){ //[l, r)

    if(l+1 >= r)
        return level[l].lower_bound({t[a], INT_MAX})->second;

    int m = (l+r)/2;

    if(posible(a, b, m))
        return bs(a, b, m, r);
    return bs(a, b, l, m);
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n, q; cin>>n>>q;

    for(int i=2; i<=n; i++){
        int x; cin>>x;
        adj[x].push_back(i);
    }

    dfs(1);

    while(q--){
        int a, b; cin>>a>>b;
        if(a == b){
            cout<<a<<"\n";
            continue;
        }
        cout<<bs(a, b, 0, min(d[a], d[b])+1)<<"\n";
    }

    return 0;
}
