#include <bits/stdc++.h>
using namespace std;

#define MAX 200100

vector<int> adj[MAX];
vector<int> to[MAX];

set<int> actual;
set<int> last;

int ans[MAX];

int dfs(int v, int p = 0){

    int ans = 0;
    //::ans[v] = ::ans[p];

    if(actual.find(v)!=actual.end()){
        actual.erase(v);
        last.insert(v);
    }

    for(int u : to[v]){
        if(last.find(u)==last.end()){
            actual.insert(u);
        }
    }

    for(int u : adj[v]){
        if(u != p){
            ans += dfs(u, v);
        }
    }

    for(int u : to[v]){
        if(last.find(u)==last.end()){
            ans++;
        }
    }

    ::ans[v] += ans;

    return ans;

}

int d[MAX];
set <pair<int, int>, greater<pair<int, int>>> level[MAX]; //time, id
int t[MAX];

int T = 0;
void dfs2(int v, int p=-1){

    t[v] = T;
    level[d[v]].insert( {T++, v} );

    for(int u : adj[v]){
        if(u!=p){
            d[u] = d[v] + 1;
            dfs2(u, v);
        }
    }
}


//si LCA(a, b)!=a && LCA(a, b)!=b entonces ans[LCA(a, b)]--;
bool common(int a, int b, int m){
    if(m >= min(d[a], d[b]))
        return false;

    auto A = level[m].lower_bound({a, INT_MAX});
    auto B = level[m].lower_bound({b, INT_MAX});

    return A==B;
}

//111111111100000000000000
int LCA(int a, int b, int l, int r){ //[l, r)

    if(l+1>=r){
        //cout<<l<<"#\n";
        return level[l].lower_bound({a, INT_MAX})->second;
    }

    int m = (l+r)/2;
    if(common(a, b, m))
        return LCA(a, b, m, r);
    return LCA(a, b, l, m);
}

vector<pair<int, int>> query;
int main(){
    int n, m;
    cin>>n>>m;

    for(int i=1; i<n; i++){
        int a, b; cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    while(m--){
        int a, b; cin>>a>>b;
        to[a].push_back(b);
        to[b].push_back(a);
        query.push_back({a, b});
    }

    dfs(1);
    dfs2(1);

    for(auto q : query){
        int a = q.first, b = q.second;
        if(a==b) continue;
        int lca = LCA(a, b, 0, min(d[a], d[b])+1);
        //cout<<a<<" "<<b<<" "<<lca<<"\n";
        if(a!=lca && b != lca)
            ans[lca]--;
    }

    for(int i=1; i<=n; i++)
        cout<<ans[i]<<" ";
    cout<<"\n";

    return 0;
}

/*
5 3
1 2
1 3
3 4
3 5
1 3
2 5
1 4
*/
