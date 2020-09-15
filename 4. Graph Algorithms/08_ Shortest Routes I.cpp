#include <bits/stdc++.h>
using namespace std;

#define MAX 200100

vector<pair<long long, int>> adj[MAX]; //cost, u
long long d[MAX];

int main(){

    int n, m; cin>>n>>m;
    for(int i=0; i<m; i++){
        int a, b, w;
        cin>>a>>b>>w;
        adj[a].push_back({w, b});
    }


    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> nxt; //distance, v
    fill(d, d+MAX, LLONG_MAX); d[0] = 0;
    nxt.push({0, 1});

    while(nxt.size()){
        int v = nxt.top().second;
        long long w = nxt.top().first;
        nxt.pop();

        if(d[v] != LLONG_MAX) continue;
        d[v] = w;

        for(auto p : adj[v])
            nxt.push({w + p.first, p.second});
    }

    for(int i=1; i<=n; i++)
        cout<<d[i]<<" ";
    cout<<"\n";

    return 0;
}
/*
3 4
1 2 6
1 3 2
3 2 3
1 3 4
*/
