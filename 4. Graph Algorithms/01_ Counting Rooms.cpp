#include <iostream>
using namespace std;
#define MAX 2000

int n, m;
char grid[MAX][MAX];

void dfs(int i,int j){
    if(i<0 || i>=n || j<0 || j>=m)
        return;
    if(grid[i][j]=='#')
        return;
    grid[i][j]='#';
    dfs(i+1, j);
    dfs(i-1, j);
    dfs(i, j+1);
    dfs(i, j-1);
}

int main(){
    cin>>n>>m;
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            cin>>grid[i][j];
    int ans = 0;
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            if(grid[i][j]=='.'){
                ans++;
                dfs(i, j);
            }
    cout<<ans<<"\n";
    return 0;
}
