#include <bits/stdc++.h>
using namespace std;

#define MAX 200100

typedef long long ull;

vector<int> adj[MAX];
vector<int> to[MAX];

int in[MAX];
int out[MAX];
ull ans[MAX];
ull up[MAX];

ull dfs(int v, int p = 0){

    for(int u : adj[v]){
        if(u != p){
            ::ans[v]+=dfs(u, v);
        }
    }

    //cout<<v<<" "<<p<<"#\n";
    return ans[v]+up[v];
}

int d[MAX];
set <pair<int, int>, greater<pair<int, int>>> level[MAX]; //time, id

int t = 0;
void dfs2(int v, int p=-1){

    in[v] = t;
    //d[v] = t;
    level[d[v]].insert( {t++, v} );

    for(int u : adj[v]){
        if(u!=p){
            d[u] = d[v] + 1;
            dfs2(u, v);
        }
    }

    out[v] = t++;
}


//si LCA(a, b)!=a && LCA(a, b)!=b entonces ans[LCA(a, b)]--;
bool common(int a, int b, int m){
    if(m > min(d[a], d[b]))
        return false;

    auto A = level[m].lower_bound({in[a], INT_MAX});
    auto B = level[m].lower_bound({in[b], INT_MAX});

    return A==B;
}

//111111111100000000000000
int LCA(int a, int b, int l, int r){ //[l, r)

    if(l+1>=r){
        //cout<<l<<"#\n";
        return level[l].lower_bound({in[a], INT_MAX})->second;
    }

    int m = (l+r)/2;
    if(common(a, b, m))
        return LCA(a, b, m, r);
    return LCA(a, b, l, m);
}

vector<pair<int, int>> query;
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

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

    dfs2(1);
    //dfs(1);

    //cout<<"###\n";
    for(auto q : query){
        int a = q.first, b = q.second;

        int lca = LCA(a, b, 0, min(d[a], d[b])+1);

        //cout<<a<<" "<<b<<" "<<lca<<"$\n";

        ans[lca]--;
        up[lca]--;
        ans[a]++;
        ans[b]++;
    }

    dfs(1);

    for(int i=1; i<=n; i++)
        cout<<ans[i]<<" ";
    cout<<"\n";
    //cout<<ans[4]<<"\n";

    return 0;
}

/*
10 10
8 2
9 8
5 3
2 10
3 6
1 6
7 4
5 4
4 2

8 9
6 4
3 2
10 5
5 3
3 10
2 5
3 2
2 3
4 4

*/
