#include <bits/stdc++.h>
using namespace std;

#define MAX 3000
typedef long long ull;

vector<int> adj[MAX];
vector<ull> cost[MAX];

vector<ull> d(MAX, 0);

vector<int> ans;

int from[MAX];
bool visited[MAX];

int main(){
    int n, m;
    cin>>n>>m;

    for(int i=0; i<m; i++){
        int a, b, c; cin>>a>>b>>c;
        adj[a].push_back(b);
        cost[a].push_back(c);
    }

    for(int i=0; i<n+5; i++){
        for(int v=1; v<=n; v++){
            for(int k = 0; k<adj[v].size(); k++){
                int u = adj[v][k];
                ull c = cost[v][k];

                if(d[v] + c < d[u])
                    from[u] = v;

                d[u] = min(d[v] + c, d[u]);

            }
        }
    }

    for(int v=1; v<=n; v++){
        for(int k = 0; k<adj[v].size(); k++){
            int u = adj[v][k];
            long long c = cost[v][k];

            if(d[v] + c <  d[u]){

                cout<<"YES\n";

                while(!visited[v]){
                    ans.push_back(v);
                    visited[v]=true;
                    v = from[v];
                }
                ans.push_back(v);

                reverse(ans.begin(), ans.end());

                for(int a : ans)
                    cout<<a<<" ";
                cout<<"\n";

                return 0;

            }

        }
    }

    cout<<"NO\n";

    return 0;
}

/*
4 5
1 2 1
2 4 1
3 1 1
4 1 -3
4 3 -2
*/
