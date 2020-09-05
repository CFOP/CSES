#include <bits/stdc++.h>
using namespace std;

#define MAX 1010
char grid[MAX][MAX];
int monster[MAX][MAX];
int route[MAX][MAX];

string ans = "";
int n, m;

void reconstruct(int y, int x){
    //cout<<y<<" "<<x<<"\n";
    if(grid[y][x] == 'A'){
        ans.push_back(' ');
        return;
    }

    if(y>0 && route[y-1][x] == route[y][x]-1 && (grid[y-1][x] == '.' && route[y-1][x]) || grid[y-1][x] == 'A' ){
        ans.push_back('D');
        reconstruct(y-1, x);
        return;
    }

    if(y<n-1 && route[y+1][x] == route[y][x]-1 && (grid[y+1][x] == '.' && route[y+1][x]) || grid[y+1][x] == 'A'){
        ans.push_back('U');
        reconstruct(y+1, x);
        return;
    }

    if(x<m+1 && route[y][x+1] == route[y][x]-1 && (grid[y][x+1] == '.' && route[y][x+1]) || grid[y][x+1] == 'A'){
        ans.push_back('L');
        reconstruct(y, x+1);
        return;
    }

    if(x>0 && route[y][x-1] == route[y][x]-1 && (grid[y][x-1] == '.' && route[y][x-1]) || grid[y][x-1] == 'A'){
        ans.push_back('R');
        reconstruct(y, x-1);
        return;
    }
}

int main(){

    ios_base::sync_with_stdio(0); cin.tie(0);

    int x, y;
    queue <pair<int, int>> last; //{y, x}

    cin>>n>>m;
    for(int i = 0; i<n; i++)
        for(int j=0; j<m; j++){
            cin>>grid[i][j];
            if(grid[i][j]=='M'){
                last.push({i, j});
            }
            if(grid[i][j]=='A'){
                y=i;
                x=j;
            }
        }

    while(last.size()){
        int y = last.front().first, x = last.front().second;
        last.pop();

        if(y > 0 && grid[y-1][x] == '.' && !monster[y-1][x]){
            monster[y-1][x] = monster[y][x] + 1;
            last.push({y-1, x});
        }

        if(y < n-1 && grid[y+1][x] == '.' && !monster[y+1][x]){
            monster[y+1][x] = monster[y][x] + 1;
            last.push({y+1, x});
        }

        if(x > 0 && grid[y][x-1] == '.' && !monster[y][x-1]){
            monster[y][x-1] = monster[y][x] + 1;
            last.push({y, x-1});
        }

        if(x < m-1 && grid[y][x+1] == '.' && !monster[y][x+1]){
            monster[y][x+1] = monster[y][x] + 1;
            last.push({y, x+1});
        }
    }

    last.push({y, x});
    while(last.size()){
        int y = last.front().first, x = last.front().second;
        last.pop();

        if(y > 0 && grid[y-1][x] == '.' && (monster[y-1][x]>route[y][x]+1 || !monster[y-1][x]) && !route[y-1][x]){
            route[y-1][x] = route[y][x] + 1;
            last.push({y-1, x});
        }
        else if(y == 0){
            reconstruct(y, x);
            break;
        }

        if(y < n-1 && grid[y+1][x] == '.' && (monster[y+1][x]>route[y][x]+1 || !monster[y+1][x]) && !route[y+1][x] ){
            route[y+1][x] = route[y][x] + 1;
            last.push({y+1, x});
        }
        else if(y == n-1){
            reconstruct(y, x);
            break;
        }

        if(x > 0 && grid[y][x-1] == '.' && (monster[y][x-1]>route[y][x]+1 || !monster[y][x-1]) && !route[y][x-1] ){
            route[y][x-1] = route[y][x] + 1;
            last.push({y, x-1});
        }
        else if(x == 0){
            reconstruct(y, x);
            break;
        }

        if(x < m-1 && grid[y][x+1] == '.' && (monster[y][x+1]>route[y][x]+1 || !monster[y][x+1]) && !route[y][x+1] ){
            route[y][x+1] = route[y][x] + 1;
            last.push({y, x+1});
        }
        if(x == m-1){
            reconstruct(y, x);
            break;
        }
    }

    /*for(int i=0; i<n; i++){
        for(int j=0; j<m; j++)
            cout<<route[i][j]<<" ";
        cout<<"\n";
    }*/

    if(ans.size()){
        ans.pop_back();
        cout<<"YES\n";
        reverse(ans.begin(), ans.end());
        cout<<ans.size()<<"\n";
        cout<<ans<<"\n";
    }
    else
        cout<<"NO\n";

    return 0;
}

/*
7 5
#####
#...#
..#.#
##A.#
....#
#M..#
#####
*/
