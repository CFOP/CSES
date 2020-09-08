#include <bits/stdc++.h>
using namespace std;
#define MAX 200100

vector<int> adj[MAX];
int nb[MAX];
bool matched[MAX];

int main(){
    int n; cin>>n;
    for(int i=1; i<n; i++){
        int a, b; cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
        nb[a]++;
        nb[b]++;
    }

    queue <int> q;
    for(int i=1; i<=n; i++){
        if(nb[i]==1){
            q.push(i);
        }
    }

    int ans = 0;
    while(q.size()){
        int v = q.front(); q.pop();

        int k = 0;
        for(int u : adj[v]){
            if(!matched[u])
                k = u;
            nb[u]--;
            if(nb[u]==1)
                q.push(u);
        }

        if(k && !matched[v]){
            ans++;
            matched[k] = true;
            matched[v] = true;
        }
    }

    cout<<ans<<"\n";

    return 0;
}

/*
6
1 3
5 3
6 4
4 2
5 6

12
1 2
2 3
2 4
5 2
2 6
6 7
6 8
9 4
9 10
11 4
11 12

2
1 2

3
1 2
2 3

4
1 2
2 3
4 1
*/
