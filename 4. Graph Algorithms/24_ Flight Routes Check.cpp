#include <bits/stdc++.h>
using namespace std;

#define MAX 100100

typedef vector<int> vi;
typedef long long ull;
typedef pair<ull, pair<int, int>> pii;

struct UF{
    vi e;
    UF(int n) : e(n, -1) {}
    bool sameSet(int a, int b) {return find(a) == find(b);}
    int size(int x) {return -e[find(x)];}
    int find(int x) {return e[x] < 0 ? x : e[x] = find(e[x]);}
    bool join(int a, int b){
        a = find(a), b = find(b);
        if(a==b) return false;
        if(e[a]>e[b]) swap(a, b);
        e[a]+=e[b]; e[b] = a;
        return true;
    }
};

UF uf(MAX);

vi adj[MAX];
int visited[MAX];

int dfs(int v, int p = 0){
    if(visited[v]){
        if(visited[v]==1)
            return v;
        if(visited[v] == 2) {
            cout<<"NO\n";
            cout<<v<<" "<<p<<"\n";
            exit(0);
        }
        return;
    }
    visited[v] = 1;

    int ans = 0;
    for(int u : adj[v]){
        dfs(u, v);
        uf.join(u, v);
    }

    visited[v] = 2;

    return r;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n, m;
    cin>>n>>m;

    for(int i=0; i<m; i++){
        int a, b; cin>>a>>b;
        adj[a].push_back(b);
    }

    dfs(1);

    for(int i=1; i<=n; i++)
        if(!visited[i]){
            cout<<"NO\n";
            cout<<1<<" "<<i<<"\n";
            return 0;
        }
        else if(!uf.sameSet(1, i)){
            cout<<"NO\n";
            cout<<i<<" "<<1<<"\n";
            return 0;
        }

    cout<<"YES\n";

    return 0;
}
