#include <bits/stdc++.h>
using namespace std;
#define MAX 2000

int n, m;
char grid[MAX][MAX];
string ans;

void reconstruct(int i, int j){
    while(grid[i][j]!='A'){
        ans += grid[i][j];
        if(grid[i][j]=='U')
            i++;
        else if(grid[i][j]=='D')
            i--;
        else if(grid[i][j]=='L')
            j++;
        else if(grid[i][j]=='R')
            j--;
    }
}

bool bfs(int i, int j){
    queue<pair<int, int>> q;
    q.push({i, j});

    while(q.size()){

        int i = q.front().first, j = q.front().second;
        q.pop();

        if(i>0 && grid[i-1][j]=='.'){
            grid[i-1][j] = 'U';
            q.push({i-1, j});
        }

        if(i<n-1 && grid[i+1][j]=='.'){
            grid[i+1][j] = 'D';
            q.push({i+1, j});
        }


        if(j>0 && grid[i][j-1]=='.'){
            grid[i][j-1] = 'L';
            q.push({i, j-1});
        }

        if(j<m-1 && grid[i][j+1]=='.'){
            grid[i][j+1] = 'R';
            q.push({i, j+1});
        }

        if(i>0 && grid[i-1][j]=='B'){
            ans += 'U';
            reconstruct(i, j);
            return true;
        }

        if(i<n-1 && grid[i+1][j]=='B'){
            ans += 'D';
            reconstruct(i, j);
            return true;
        }

        if(j>0 && grid[i][j-1]=='B'){
            ans += 'L';
            reconstruct(i, j);
            return true;
        }

        if(j<m-1 && grid[i][j+1]=='B'){
            ans += 'R';
            reconstruct(i, j);
            return true;
        }


    }

    return false;
}

int main(){
    cin>>n>>m;
    for(int i=0; i<n; i++)
        for(int j = 0; j<m; j++)
            cin>>grid[i][j];

    for(int i=0; i<n; i++)
        for(int j = 0; j<m; j++){

            if(grid[i][j]=='A'){

                if(bfs(i, j)){
                    cout<<"YES\n";
                    reverse(ans.begin(), ans.end());
                    cout<<ans.size()<<"\n"<<ans<<"\n";
                }
                else cout<<"NO\n";

                /*for(int i=0; i<n; i++){
                    for(int j=0; j<m; j++)
                        cout<<grid[i][j];
                    cout<<"\n";
                }*/

                return 0;
            }

        }


}
