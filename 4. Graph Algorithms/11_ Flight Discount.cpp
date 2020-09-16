#include <bits/stdc++.h>
using namespace std;

#define MAX 200100

vector<pair<long long, int>> adj[MAX]; //cost, u
long long d[MAX];
long long d2[MAX];

int main(){

    int n, m; cin>>n>>m;
    for(int i=0; i<m; i++){
        int a, b, w;
        cin>>a>>b>>w;
        adj[a].push_back({w, b});
    }


    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> nxt; //distance, v
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> nxt2; //distance, v
    fill(d, d+MAX, LLONG_MAX); d[0] = 0;
    fill(d2, d2+MAX, LLONG_MAX); d2[0] = 0;
    nxt.push({0, 1});

    while(nxt.size()){
        int v = nxt.top().second;
        long long w = nxt.top().first;
        nxt.pop();

        if(d[v] != LLONG_MAX) continue;
        d[v] = w;

        for(auto p : adj[v]){
            nxt.push({w + p.first, p.second});
            nxt2.push({w + p.first/2, p.second});
        }
    }

    while(nxt2.size()){
        int v = nxt2.top().second;
        long long w = nxt2.top().first;
        nxt2.pop();

        if(d2[v] != LLONG_MAX) continue;
        d2[v] = w;

        for(auto p : adj[v]){
            nxt2.push({w + p.first, p.second});
        }
    }


    cout<<min(d[n], d2[n]);

    return 0;
}
