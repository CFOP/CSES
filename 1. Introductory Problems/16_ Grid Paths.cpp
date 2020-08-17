#include <bits/stdc++.h>
using namespace std;

string a;

bool visited[10][10];

long long bsk(int i=0, int x=0, int y=0){
    if(x<0 || x==7 || y<0 ||y==7)
        return 0;
    if(visited[y][x])
        return 0;
    if(x==0 && y==6){
        //cout<<i<<"\n";
        return i==48;
    }

    if(x>0 && x<6 && y>0 && y<6){
        if(visited[y-1][x] && visited[y+1][x] && !visited[y][x+1] && !visited[y][x-1])
            return 0;
        if(!visited[y-1][x] && !visited[y+1][x] && visited[y][x+1] && visited[y][x-1])
            return 0;
    }
    else {
        if(x>0 && x<6 && y==0){
            if(visited[y+1][x] && !visited[y][x+1] && !visited[y][x-1])
                return 0;
        }
        if(x>0 && x<6 && y==6){
            if(visited[y-1][x] && !visited[y][x+1] && !visited[y][x-1])
                return 0;
        }
        if(y>0 && y<6 && x==0){
            if(!visited[y-1][x] && !visited[y+1][x] && visited[y][x+1])
            return 0;
        }
        if(y>0 && y<6 && x==6){
            if(!visited[y-1][x] && !visited[y+1][x] && visited[y][x-1])
            return 0;
        }
    }

    visited[y][x] = true;
    long long sum=0;
    if(a[i]=='D' && !visited[y+1][x])
        sum = bsk(i+1, x, y+1);
    else if(a[i]=='U' && !visited[y-1][x])
        sum = bsk(i+1, x, y-1);
    else if(a[i]=='L' && !visited[y][x-1])
        sum = bsk(i+1, x-1, y);
    else if(a[i]=='R' && !visited[y][x+1])
        sum = bsk(i+1, x+1, y);
    else if(a[i]=='?'){
        sum = bsk(i+1, x, y-1)+ bsk(i+1, x, y+1)+bsk(i+1, x-1, y)+bsk(i+1, x+1, y);
    }
    visited[y][x] = false;

    return sum;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>a;
    cout<<bsk()<<"\n";
    //cout<<k<<"\n";
    return 0;
}

//??????R??????U??????????????????????????LD????D?
//????????????????????????????????????????????????
