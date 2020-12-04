#include <bits/stdc++.h>
using namespace std;

#define MAX 1100

typedef long long ull;

ull grid[MAX][MAX];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n, q; cin>>n>>q;
    for(int i=1; i<=n; i++)
        for(int j=1; j<=n; j++){
            char c; cin>>c;
            grid[i][j] = c=='*';
        }


    for(int i=1; i<=n; i++)
        for(int j=2; j<=n; j++)
            grid[i][j] += grid[i][j-1];

    for(int i=2; i<=n; i++)
        for(int j=1; j<=n; j++)
            grid[i][j] += grid[i-1][j];


    while(q--){
        int y1, x1, y2, x2;
        cin>>y1>>x1>>y2>>x2;

        ull ans = grid[y2][x2]-grid[y1-1][x2]-grid[y2][x1-1]+grid[y1-1][x1-1];
        cout<<ans<<"\n";


    }

}
