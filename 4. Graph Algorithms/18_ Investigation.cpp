#include <bits/stdc++.h>
using namespace std;
#define MAX 100100
#define MOD 1000000007

typedef long long ull;
typedef pair<long long, int> pii; //cost, v

ull minPrice[MAX];
int routes[MAX];
int minF[MAX];
int maxF[MAX];

vector<int> adj[MAX];
vector<ull> cost[MAX];

bool visited[MAX];

int main(){
    int n, m; cin>>n>>m;

    for(int i=0; i<m; i++){
        int a, b, c;
        cin>>a>>b>>c;
        adj[a].push_back(b);
        cost[a].push_back(c);
    }

    fill(minPrice, minPrice+n+5, LLONG_MAX);
    fill(minF, minF+n+5, INT_MAX);

    minPrice[1] = minF[1] = maxF[1] = 0;
    routes[1] = 1;

    priority_queue<pii, vector<pii>, greater<pii>> nxt; //cost, v
    nxt.push({0, 1});

    while(nxt.size()){
        ull cost = nxt.top().first;
        int v = nxt.top().second;
        nxt.pop();

        if(visited[v]) continue;
        visited[v] = true;

        for(int i = 0; i<adj[v].size(); i++){
            int u = adj[v][i];
            ull c = cost + ::cost[v][i];

            if(minPrice[u] == c){
                routes[u] += routes[v];
                routes[u] %= MOD;
                maxF[u] = max(maxF[v]+1, maxF[u]);
                minF[u] = min(minF[v]+1, minF[u]);
            }
            else if(minPrice[u] > c){
                minPrice[u] = c;
                routes[u] = routes[v];
                maxF[u] = maxF[v]+1;
                minF[u] = minF[v]+1;
                nxt.push({c, u});
            }

        }

    }

    cout<<minPrice[n]<<" "<<routes[n]<<" "<<minF[n]<<" "<<maxF[n]<<"\n";
}
