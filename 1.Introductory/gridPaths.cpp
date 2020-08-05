#include <bits/stdc++.h>
using namespace std;

string a;

bool visited[10][10];
long long s[10][10];
int Y[10]; //y
int X[10]; //x
int d[20]; //x+y | x+y+1
int d2[20]; // y-x+6 | 7-abs(y-x)

long long bsk(int i=0, int x=0, int y=0){
    if(x<0 || x==7 || y<0 ||y==7)
        return 0;
    if(visited[y][x])
        return 0;
    if(x==0 && y==6){
        //cout<<i<<"\n";
        return i==48;
    }
    Y[y]++;
    if(Y[y]==7 && y>0){
        //for(int i=0; i<y; i++)
            if(Y[y-1]<7){
                Y[y]--;
                return 0;
            }
    }

    X[x]++;
    if(X[x]==7 && x<6){
        //for(int i=x+1; i<7; i++)
        //int i=x+1;
        if(X[x+1]<7){
            X[x]--;
            Y[y]--;
            return 0;
        }
    }

    d[x+y]++;
    if(d[x+y]==x+y+1 && x+y>0){
        if(d[x+y-1]<x+y){
            X[x]--;
            Y[y]--;
            d[x+y]--;
            return 0;
        }
    }

    d2[y-x+6]++;
    if(d[y-x+6]==7-abs(y-x) && y-x+6<12){
        int k = y-x;
        if(k>=0) k=1;
        else k=-1;
        if(d[y-x+7]<7-abs(y-x) + k){
            X[x]--;
            Y[y]--;
            d[x+y]--;
            d2[y-x+6]--;
            return 0;
        }
    }

    //cout<<x<<" "<<y<<"\n";
    //cout<<a[i]<<" ";

    visited[y][x] = true;
    long long sum=0;
    if(a[i]=='D')
        sum = bsk(i+1, x, y+1);
    else if(a[i]=='U')
        sum = bsk(i+1, x, y-1);
    else if(a[i]=='L')
        sum = bsk(i+1, x-1, y);
    else if(a[i]=='R')
        sum = bsk(i+1, x+1, y);
    else
        sum = bsk(i+1, x, y-1)+ bsk(i+1, x, y+1)+bsk(i+1, x-1, y)+bsk(i+1, x+1, y);
    visited[y][x] = false;
    X[x]--;
    Y[y]--;
    return sum;
}

int main(){
    cin>>a;
    cout<<bsk()<<"\n";
    return 0;
}

//??????R??????U??????????????????????????LD????D?
