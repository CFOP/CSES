#include <bits/stdc++.h>
using namespace std;

#define MAX 200100
int n, q;

int lift[40][MAX];

int walk(int i, int k){
    for(int d=0; d<32; d++)
        if((1<<d)&k)
            i = lift[d][i];
    return i;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin>>n>>q;

    for(int i=1; i<=n; i++){
        int t; cin>>t;
        lift[0][i] = t;
    }

    for(int d = 1; d<32; d++){
        for(int j = 1; j<=n; j++)
            lift[d][j] = lift[d-1][ lift[d-1][j] ];
    }

    while(q--){
        int x, k; cin>>x>>k;
        cout<<walk(x, k)<<"\n";
    }

    return 0;
}
