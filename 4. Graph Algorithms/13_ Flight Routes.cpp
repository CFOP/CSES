#include <bits/stdc++.h>
using namespace std;

#define MAX 200100
typedef long long ull;
typedef pair<ull, int> pii;

vector<int> adj[MAX];
vector<ull> cost[MAX];

int visited[MAX];
vector<ull> ans;

int main(){
    int n, m, k;
    cin>>n>>m>>k;

    for(int i=0; i<m; i++){
        int a, b;
        ull c;
        cin>>a>>b>>c;
        adj[a].push_back(b);
        cost[a].push_back(c);
    }

    priority_queue<pii, vector<pii>, greater<pii>> nxt; //cost, v
    nxt.push({0, 1});

    while(nxt.size() && ans.size()<k){
        int v = nxt.top().second;
        ull c = nxt.top().first;
        nxt.pop();

        if(visited[v]++>=k) continue;

        if(v==n){
            ans.push_back(c);
        }

        for(int i=0; i<adj[v].size(); i++){
            int u = adj[v][i]; ull C = cost[v][i];
            nxt.push({C+c, u});
        }
    }

    for(ull ans : ::ans)
        cout<<ans<<" ";
    cout<<"\n";

    return 0;
}

/*
4 6 3
1 2 1
1 3 3
2 3 2
2 4 6
3 2 8
3 4 1

2 20 10
1 2 20
1 2 10
1 2 11
1 2 12
1 2 13
1 2 14
1 2 15
1 2 16
1 2 17
1 2 18
1 2 19
1 2 1
1 2 2
1 2 3
1 2 4
1 2 5
1 2 6
1 2 7
1 2 8
1 2 9

4 4 2
1 2 100
1 3 8
2 3 3
3 4 1
*/
